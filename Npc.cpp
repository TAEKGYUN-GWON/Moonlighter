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

	SetNpcState(NpcIdle::GetInstance()); //기본 상태
	
	_trans->SetPos(392, 850); //문 밖에 생성
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

	//위로 움직이라고 명령 중
	//if (_trans->GetPos() >= Vector2(392, 500))
	//_trans->SetPos(Vector2(_trans->GetPos()+Vector2::up));

	//상태
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

//상태 정의
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
