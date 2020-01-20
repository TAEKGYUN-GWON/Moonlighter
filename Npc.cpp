#include "stdafx.h"
#include "Npc.h"
#include "NpcState.h"

//생성자임
Npc::Npc()
{
	_npcState = NpcStateIdle::GetInstance();
}

void Npc::Init()
{
}

void Npc::Release()
{
}

void Npc::Update()
{
}

void Npc::Render()
{
}


void Npc::SetState(NpcState* npcstate)
{
	this->_npcState = npcstate;
}

void Npc::BuyStuffs()
{
	_npcState->BuyStuffs(this);
}

void Npc::NotBuyStuffs()
{
	_npcState->NotBuyStuffs(this);
}

void Npc::Move()
{
	_npcState->Move(this);
}

void Npc::GoHome()
{
	_npcState->GoHome(this);
}
