#include "stdafx.h"
#include "ParticleManager.h"



//파티클 풀
void ParticlePool::InssertPool(int num)
{
	ActivePool[num]->SetIsActive(false);
	pool.push(ActivePool[num]);
	ActivePool.erase(ActivePool.begin() + num);
}

void ParticlePool::InssertActiveObject()
{
	pool.top()->SetIsActive(true);
	ActivePool.push_back(pool.top());
	pool.pop();
}

void ParticlePool::Init(int size, string imgKey, bool isFrame, float FPS)
{
	ActivePool.reserve(size);
	for (int i = 0; i < size; i++)
	{
		Particle* newObj = Object::CreateObject<Particle>();
		newObj->Init(RND->getFromFloatTo(_Mgr->GetMinAngle(), _Mgr->GetMaxAngle()),
			RND->getFromFloatTo(_Mgr->GetMinSpeed(), _Mgr->GetMaxSpeed()),
			_Mgr->GetPos(), _Mgr->GetScale(), imgKey, isFrame, FPS
		);
		newObj->SetIsActive(false);
		pool.push(newObj);

	}
}

//파티클 매니저
ParticleManager::ParticleManager()
{
	_maxAngle = 140 * DegToRad;
	_minAngle = 40 * DegToRad;
	_maxSpeed = 20;
	_minSpeed = 10;

}

void ParticleManager::Init(int size, ParticleType type, Vector2 pos, Vector2 scale, string imgKey, bool isFrame, float FPS)
{
	_type = type;
	_pos = pos;
	_scale = scale;
	_pool.SetLink(this);
	_pool.Init(size, imgKey, isFrame, FPS);

}

void ParticleManager::Update()
{

	if (_pool.GetPool().size())
	{
		_pool.GetPoolObject()->SetPos(_pos);
		_pool.GetPoolObject()->SetRangeAngleToRadian(RND->getFromFloatTo(_minAngle, _maxAngle));
		_pool.GetPoolObject()->SetRotateToRadian(RND->getFromFloatTo(0, PI2));
		_pool.GetPoolObject()->SetSpeed(RND->getFromFloatTo(_minSpeed, _maxSpeed));
		_pool.GetPoolObject()->SetAlpha(1.f);
		_pool.GetPoolObject()->SetActive(true);
		_pool.InssertActiveObject();
	}

	for (int i = 0; i < _pool.GetActivePool().size(); i++)
	{
		if (!_pool.GetActivePool()[i]->GetIsActive())
		{
			_pool.GetActivePool()[i]->SetRotateToRadian(RND->getFromFloatTo(0, PI2));
			_pool.InssertPool(i);
		}
	}

	if(KEYMANAGER->isStayKeyDown(VK_UP))	_pos += Vector2::up * 10;
	if(KEYMANAGER->isStayKeyDown(VK_LEFT))	_pos += Vector2::left * 10;
	if(KEYMANAGER->isStayKeyDown(VK_RIGHT))	_pos += Vector2::right * 10;
	if(KEYMANAGER->isStayKeyDown(VK_DOWN))	_pos += Vector2::down * 10;

	
	if (KEYMANAGER->isStayKeyDown(VK_NUMPAD1))
	{
		if (_maxAngle > MAX_ANGLE_MAX) _maxAngle = MAX_ANGLE_MAX;
		else if (_maxAngle< MAX_ANGLE_MIN) _maxAngle = MAX_ANGLE_MIN;

		if (_minAngle > MIN_ANGLE_MAX) _minAngle = MIN_ANGLE_MAX;
		else if (_minAngle < MIN_ANGLE_MIN) _minAngle = MIN_ANGLE_MIN;

		_maxAngle += 0.03;
		_minAngle -= 0.03;
	}
	if (KEYMANAGER->isStayKeyDown(VK_NUMPAD2))
	{
		if (_maxAngle > MAX_ANGLE_MAX) _maxAngle = MAX_ANGLE_MAX;
		else if (_maxAngle < MAX_ANGLE_MIN) _maxAngle = MAX_ANGLE_MIN;

		if (_minAngle > MIN_ANGLE_MAX) _minAngle = MIN_ANGLE_MAX;
		else if (_minAngle < MIN_ANGLE_MIN) _minAngle = MIN_ANGLE_MIN;
		_maxAngle -= 0.03;
		_minAngle += 0.03;
	}

	if (KEYMANAGER->isStayKeyDown(VK_NUMPAD3))
	{
		_maxSpeed += 1;
		_minSpeed += 1;
	}
	if (KEYMANAGER->isStayKeyDown(VK_NUMPAD4))
	{
		_maxSpeed -= 1;
		_minSpeed -= 1;
	}

	
}

void ParticleManager::Render()
{

	for (int i = 0; i < _pool.GetActivePool().size(); i++)
	{
		if (KEYMANAGER->isToggleKey(VK_F6))
			GRAPHICMANAGER->DrawRect(_pool.GetActivePool()[i]->GetTrans()->GetPos(), _pool.GetActivePool()[i]->GetTrans()->GetScale(), _pool.GetActivePool()[i]->GetTrans()->GetRotateDegree(), ColorF::Red);
	}
	GRAPHICMANAGER->DrawLine(_pos, _pos +Vector2(cosf(_minAngle), -sinf(_minAngle)) * 200, D2D1::ColorF::Red,1.f,true);
	GRAPHICMANAGER->DrawLine(_pos, _pos +Vector2(cosf(_maxAngle), -sinf(_maxAngle)) * 200, D2D1::ColorF::Red,1.f,true);

	wchar_t buffer[1024];
	swprintf(buffer, 128, L"minAngle : %f  maxAngle : %f", _minAngle * RadToDeg, _maxAngle * RadToDeg);
	GRAPHICMANAGER->Text(Vector2(WINSIZEX / 2, 0), buffer, 20, 300, 50, ColorF::Azure);

	swprintf(buffer, 128, L"minSpeed : %f  maxSpeed : %f", _minSpeed, _maxSpeed);
	GRAPHICMANAGER->Text(Vector2(WINSIZEX / 2, 50), buffer, 20, 300, 50, ColorF::Azure);

}
