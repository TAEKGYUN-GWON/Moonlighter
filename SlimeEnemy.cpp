#include "stdafx.h"
#include "SlimeEnemy.h"
#include "Hp.h"


SlimeEnemy::SlimeEnemy()
{

}

SlimeEnemy::~SlimeEnemy()
{

}

void SlimeEnemy::Init()
{
	Enemy::Init();

	GRAPHICMANAGER->AddFrameImage("slime", L"resource/img/Enemy", 5, 1); 
	
	_tag = "enemy";
	_name = "Slime";
	
	_hp = new Hp(1, 1); 
	
	////이미지 크기, pos는 어떻게 하지 생성될때 방안에 랜덤으로 해야 할거 같음
	_trans->SetPos(WINSIZEX / 2, WINSIZEY / 2); //->위치 어떻게?
	_trans->SetScale(Vector2(_sprite->GetGraphic()->GetFrameWidth(), 
		_sprite->GetGraphic()->GetFrameHeight()));

	_sprite = AddComponent<Sprite>();
	_sprite->Init(true, true);
	_sprite->SetMaxFrameX(5);
	_sprite->SetFrameY(1);
	_sprite->SetRectColor(ColorF::Cornsilk);

	_physics = AddComponent<PhysicsBody>();
	_physics->Init(BodyType::DYNAMIC, 1.0f);	//플레이어한테 뚫림 왜 그러지?
	//가상세계의 렉트 뒤틀리는거 고정
	_physics->GetBody()->SetFixedRotation(true);	
	
}

void SlimeEnemy::Update()
{
	Enemy::Update();
	
	if (_path.size())
	{
		Vector2 _astar = *_path.begin() - _trans->GetPos();
		_trans->SetPos(_trans->GetPos() + _astar.Nomalized() * 70 * TIMEMANAGER->getElapsedTime());
		
		if ((int)Vector2::Distance(*_path.begin(), _trans->GetPos()) < (int)20)_path.erase(_path.begin());
	}
	
	//_sprite->set
}

void SlimeEnemy::Attack()
{
	//여기에 범위 원 렉트?
	//GRAPHICMANAGER->DrawEllipse
		//(float x, float y, float radiusX, float radiusY, ColorF::Enum color, float strokeWidth)
		//데미지 주는거?
	//원 랙트 안에 센서 on이면 떄리고 off면 안 때리고
	//이미지 바꿔줘야 하나 여기서?->슬라임은 필요x
	//길바떄 센서처럼 하면 될까??->bool player?


}

