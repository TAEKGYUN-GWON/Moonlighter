#include "stdafx.h"
#include "Npc.h"
#include "NpcShopState.h"



void Npc::Init(string imgkey)
{
	
	Object::Init();

	_tag = "Npc";

	SetNpcState(NpcIdle::GetInstance());
	
	_trans->SetPos(WINSIZEX / 2, WINSIZEY / 2);
	_trans->SetWorldPos(Vector2(30, 50)); //나중에 그림 크기대로 바꿔주기, framewidth
	
	_sprite = AddComponent<Sprite>();

	_physics = AddComponent<PhysicsBody>();
	_physics->Init(BodyType::DYNAMIC, 1.0f);

	_speed = 3.0f;

	AddComponent<Sprite>();
	_sprite->SetImgName(imgkey);
	_sprite->Init(true, true);

	
}

void Npc::Release()
{
	Object::Release();
}

void Npc::Update()
{
	
	//In();
	//아래 함수들은 In에서 조건주고 보내기로..
	Stay();
	//Out();
	
	Object::Update();
}

void Npc::Render()
{
	Object::Render();
}

void Npc::SetNpcState(NpcShopState* npcshopstate)
{
	_npcShopState = npcshopstate;
	_npcShopState->StateIn(this);
	
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
