#include "stdafx.h"
#include "Npc.h"
#include "NpcShopState.h"


void Npc::Init()
{
	Object::Init();

	_tag = "Npc";
	
	_trans->SetPos(WINSIZEX / 2, WINSIZEY / 2);
	_trans->SetWorldPos(Vector2(30, 50)); //나중에 그림 크기대로 바꿔주기, framewidth
	
	_sprite = AddComponent<Sprite>();

	_physics = AddComponent<PhysicsBody>();
	_physics->Init(BodyType::DYNAMIC, 1.0f);

	_speed = 3.0f;
}

void Npc::Release()
{
	Object::Release();
}

void Npc::Update()
{
	In();
	//아래 함수들은 In에서 조건주고 보내기로..
	//Stay();
	//Out();
	
	Object::Update();
}

void Npc::Render()
{
	Object::Render();
}

//상태 정의
void Npc::In()
{
	_npcState->StateIn(this);
}

void Npc::Stay()
{
	_npcState->StateStay(this);
}

void Npc::Out()
{
	_npcState->StateOut(this);
}
