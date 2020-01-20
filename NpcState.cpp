#include "stdafx.h"
#include "NpcState.h"

//★이부분 뭔지 모르겠음 일단 있어서 베낌
NpcStateIdle* NpcStateIdle::instance;
NpcStateSearch* NpcStateSearch::instance;
NpcStateInline* NpcStateInline::instance;
NpcStateGoHome* NpcStateGoHome::instance;

//======================IDLE 상태===========================

NpcStateIdle* NpcStateIdle::GetInstance()
{
	if (instance == nullptr)
	{
		instance = new NpcStateIdle(); //★ ㅇ
	}
	return instance;
}

void NpcStateIdle::BuyStuffs(Npc* npc)
{
}

void NpcStateIdle::NotBuyStuffs(Npc* npc)
{
}

void NpcStateIdle::Move(Npc* npc)
{
}

void NpcStateIdle::GoHome(Npc* npc)
{
}
//======================Search 상태===========================
NpcStateSearch* NpcStateSearch::GetInstance()
{
	if (instance == nullptr)
	{
		instance = new NpcStateSearch();
	}
	return instance;
}

void NpcStateSearch::BuyStuffs(Npc* npc)
{
}

void NpcStateSearch::NotBuyStuffs(Npc* npc)
{
}

void NpcStateSearch::Move(Npc* npc)
{
}

void NpcStateSearch::GoHome(Npc* npc)
{
}
//======================Inline 상태===========================
NpcStateInline* NpcStateInline::GetInstance()
{
	if (instance == nullptr)
	{
		instance = new NpcStateInline();
	}
	return instance;
}

void NpcStateInline::BuyStuffs(Npc* npc)
{
}

void NpcStateInline::NotBuyStuffs(Npc* npc)
{
}

void NpcStateInline::Move(Npc* npc)
{
}

void NpcStateInline::GoHome(Npc* npc)
{
}
//======================GoHome 상태===========================
NpcStateGoHome* NpcStateGoHome::GetInstance()
{
	if (instance == nullptr)
	{
		instance = new NpcStateGoHome();
	}
	return instance;
}

void NpcStateGoHome::BuyStuffs(Npc* npc)
{
}

void NpcStateGoHome::NotBuyStuffs(Npc* npc)
{
}

void NpcStateGoHome::Move(Npc* npc)
{
}

void NpcStateGoHome::GoHome(Npc* npc)
{
}
