#include "stdafx.h"
#include "Npc.h"
#include "NpcShopState.h"

void Npc::Init(string imgkey)
{
	Object::Init();

	_tag = "Npc";

	_sprite = AddComponent<Sprite>();
	_sprite->Init(true, true);
	_sprite->SetImgName(imgkey);
	
	_trans->SetPos(400, 700); //�� �ۿ� ����
	_trans->SetScale(Vector2(
		GRAPHICMANAGER->FindImage(imgkey)->GetFrameWidth(),
		GRAPHICMANAGER->FindImage(imgkey)->GetFrameHeight()));

	_sprite->SetPosition(_trans->GetPos());

	_npcShopState = new NpcIdle(this);
	_npcShopState->Enter();

	//_destination = Vector2(340, 200);
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

	//npc �׸� ����
	_sprite->SetPosition(_trans->GetPos()); 

	_npcShopState->Update();

}

void Npc::Render()
{
	Object::Render();

	//�̰� ���ϸ� �ڲ� ��ü�Ҹ��� ���׶�̰� ���Ǿ�ó�� ������.. erase�Ҷ� false ����
	if (_isActive)
	{
		GRAPHICMANAGER->DrawEllipse(
			_trans->GetPos().x, 
			_trans->GetPos().y, 
			_trans->GetScale().x / 2, 
			_trans->GetScale().y / 2);
	}

	wchar_t buffer[128];
	swprintf(buffer, 128, L"x: %1.f, y:%1.f", _trans->GetPos().x , _trans->GetPos().y);
	GRAPHICMANAGER->Text(Vector2(_trans->GetPos().x - CAMERA->GetPosition().x, _trans->GetPos().y - CAMERA->GetPosition().y), buffer, 20, 500, 300, ColorF::White);

	if(_npcShopState->GetStateType() == "Idle")
		GRAPHICMANAGER->Text(Vector2(_trans->GetPos().x - 25 - CAMERA->GetPosition().x, _trans->GetPos().y + 25 - CAMERA->GetPosition().y), L"Idle", 20, 100, 30, ColorF::AntiqueWhite);
	else if (_npcShopState->GetStateType() == "Move")
		GRAPHICMANAGER->Text(Vector2(_trans->GetPos().x - 25 - CAMERA->GetPosition().x, _trans->GetPos().y + 25 - CAMERA->GetPosition().y), L"Move", 20, 100, 30, ColorF::AntiqueWhite);
	else if (_npcShopState->GetStateType() == "Home")
		GRAPHICMANAGER->Text(Vector2(_trans->GetPos().x - 25 - CAMERA->GetPosition().x, _trans->GetPos().y + 25 - CAMERA->GetPosition().y), L"Home", 20, 100, 30, ColorF::AntiqueWhite);
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
