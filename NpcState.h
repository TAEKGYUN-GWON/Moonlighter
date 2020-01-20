#pragma once
#include "Npc.h"

class NpcState
{
private:

protected:

	//setter
	void SetNpcState(Npc* npc, NpcState* npcstate)
	{ 
		npc->SetState(npcstate);
	}

public :
	virtual void BuyStuffs(Npc* npc) = 0;	//물건 사기 행동
	virtual void NotBuyStuffs(Npc* npc) = 0;//물건 안사기 행동
	virtual void Move(Npc* npc) = 0;		//이동 행동 (상태에 따라 바껴야함)
	virtual void GoHome(Npc* npc) = 0;		//집에 가기 행동

};

class NpcStateIdle : NpcState
{
	//Npc가 얘 써야해서 스태틱..
	static NpcStateIdle* instance;

public:
	static NpcStateIdle* GetInstance();

	virtual void BuyStuffs(Npc* npc);
	virtual void NotBuyStuffs(Npc* npc);
	virtual void Move(Npc* npc);
	virtual void GoHome(Npc* npc);
};
class NpcStateSearch : NpcState
{
	static NpcStateSearch* instance;

public:
	static NpcStateSearch* GetInstance();

	virtual void BuyStuffs(Npc* npc);
	virtual void NotBuyStuffs(Npc* npc);
	virtual void Move(Npc* npc);
	virtual void GoHome(Npc* npc);

};
class NpcStateInline : NpcState
{
	static NpcStateInline* instance;

public:
	static NpcStateInline* GetInstance();

	virtual void BuyStuffs(Npc* npc);
	virtual void NotBuyStuffs(Npc* npc);
	virtual void Move(Npc* npc);
	virtual void GoHome(Npc* npc);

};
class NpcStateGoHome : NpcState
{
	static NpcStateGoHome* instance;

public:
	static NpcStateGoHome* GetInstance();

	virtual void BuyStuffs(Npc* npc);
	virtual void NotBuyStuffs(Npc* npc);
	virtual void Move(Npc* npc);
	virtual void GoHome(Npc* npc);

};
