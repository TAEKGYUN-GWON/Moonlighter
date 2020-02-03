#include "stdafx.h"
#include "Npc.h"
#include "NpcShopState.h"

void Npc::Init(string imgkey, Vector2 pos)
{
	Object::Init();

	_tag = "Npc";

	_sprite = AddComponent<Sprite>();
	_sprite->Init(true, true);
	_sprite->SetImgName(imgkey);

	_npcShopState = new NpcIdle(this);
	_npcShopState->Enter();

	
	_trans->SetPos(pos.x, pos.y); //�� �ۿ� ����
	_trans->SetScale(Vector2(
		//GRAPHICMANAGER->FindImage(imgkey)->GetFrameWidth()+15,
		//GRAPHICMANAGER->FindImage(imgkey)->GetFrameHeight()+15));
		GRAPHICMANAGER->FindImage(imgkey)->GetFrameWidth(),
		GRAPHICMANAGER->FindImage(imgkey)->GetFrameHeight()));

	_sprite->SetPosition(_trans->GetPos());
	_timer = 0;

	_isAstarOn = true;	//astar �޾ƾ��ϴ� ��������

	_npcThought = NPCTHOUGHT::WINDOW;
	_npcNowPosition = NPCNOWPOSITION::POS_ENTER;
}

void Npc::Release()
{
	Object::Release();
}

void Npc::Update()
{

	Object::Update();
	//���� �����̶�� ��� ��
	//if (_trans->GetPos() >= Vector2(392, 500))
	//_trans->SetPos(Vector2(_trans->GetPos()+Vector2::up));


	//Astar �� �Լ�
	//SetPath(list<Vector2> lpath);
	Move();

	//npc �׸� ����
	_sprite->SetPosition(_trans->GetPos()); 

	_npcShopState->Update();

}

void Npc::Render()
{
	Object::Render();

	//�̰� ���ϸ� �ڲ� ��ü�Ҹ��� ���׶�̰� ���Ǿ�ó�� ������.. erase�Ҷ� false ����
	/*if (_isActive)
	{
		if(SCENEMANAGER->GetNowScene()->GetName() == )
		GRAPHICMANAGER->DrawEllipse(
			_trans->GetPos().x, 
			_trans->GetPos().y, 
			_trans->GetScale().x / 2, 
			_trans->GetScale().y / 2);
	}*/

	wchar_t buffer[128];
	swprintf(buffer, 128, L"x: %1.f, y:%1.f", _trans->GetPos().x , _trans->GetPos().y);
	GRAPHICMANAGER->Text(Vector2(_trans->GetPos().x - CAMERA->GetPosition().x, _trans->GetPos().y - CAMERA->GetPosition().y), buffer, 20, 500, 300, ColorF::White);
}

void Npc::SetPath(list<Vector2> lpath)
{
	this->_lPath.clear();
	this->_lPath = lpath;
}

void Npc::ChangeState(NpcShopState* state)
{
	_npcShopState->Exit();
	_npcShopState = state;
	_npcShopState->Enter();

}

void Npc::Move()
{
	if (_lPath.size())
	{
		if (!_isAstarOn) //������ ������ false ����
		{

			Vector2 a = *_lPath.begin() - _trans->GetPos(); // ��������ġ���� ����ġ�� ����, ���ߵǴ� ���� ��尡 ����
			float b = Vector2::GetAngle(_trans->GetPos(), *_lPath.begin());

			_trans->SetPos(_trans->GetPos() + Vector2(cosf(b), -sinf(b)) * 50 * TIMEMANAGER->getElapsedTime());

			if ((int)Vector2::Distance(*_lPath.begin(), _trans->GetPos()) < (int)2)//���� �����ϰ� ����ó�� ���ִ� �κ�
				_lPath.pop_front(); //���� ù��° ������ �����, ���� ��带 �ֱ� ����		}
		}
	}
	else //������ ������ true �����
	{
		_timer += TIMEMANAGER->getElapsedTime();
		if (_timer > 2)
		{
			_isAstarOn = true;
			_timer = 0;
		}
	}
}


