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

	SetNpcState(NpcIdle::GetInstance()); //�⺻ ����
	
	_trans->SetPos(392, 850); //�� �ۿ� ����
	_trans->SetScale(Vector2(
		GRAPHICMANAGER->FindImage(imgkey)->GetFrameWidth(),
		GRAPHICMANAGER->FindImage(imgkey)->GetFrameHeight()));

	_speed = 3.0f;

	int a;

	
}

void Npc::Release()
{
	Object::Release();
}

void Npc::Update()
{

	//���� �����̶�� ��� ��
	//if (_trans->GetPos() >= Vector2(392, 500))
	//_trans->SetPos(Vector2(_trans->GetPos()+Vector2::up));

	//����
	Stay();

	Object::Update();
}

void Npc::Render()
{
	GRAPHICMANAGER->DrawEllipse(_trans->GetPos().x, _trans->GetPos().y, _trans->GetScale().x/2, _trans->GetScale().y/2);

	Object::Render();
}

void Npc::SetNpcState(NpcShopState* npcshopstate)
{
	_npcShopState = npcshopstate;
	_npcShopState->StateIn(this);
	
}

void Npc::SetPath(list<Vector2> lpath)
{
	this->_lPath.clear();
	this->_lPath = lpath;
}

//���� ����
void Npc::In()
{
	_npcShopState->StateIn(this);
}

void Npc::Stay()
{
	_npcShopState->StateStay(this);
}

void Npc::Out()
{
	_npcShopState->StateOut(this);
}
