#include "stdafx.h"
#include "Npc.h"
#include "NpcState.h"

//생성자임
Npc::Npc()
{
	_npcState = NpcStateIdle::GetInstance(); //여기가 문제임..
}

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
}

void Npc::Update()
{

	//SetState(NpcState * npcstate); //이거도 여기다가 이렇게 하면 되는것인지..
	//if (생각보다 가격이 낮으면)
	{
	Act();
	}
	//else if (생각보다 가격이 높으면)
	{
	NotBuyStuffs();
	}
	GoHome();
	
	Object::Update();
}

void Npc::Render()
{
}


void Npc::SetState(NpcState* npcstate)
{
	this->_npcState = npcstate;
}

void Npc::Act()
{
	_npcState->Act(this);
}

void Npc::NotBuyStuffs()
{
	_npcState->NotBuyStuffs(this);
}

void Npc::GoHome()
{
	_npcState->GoHome(this);
}
