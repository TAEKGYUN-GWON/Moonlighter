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
//	virtual void BuyStuffs(Npc* npc) = 0;	//���� ��� �ൿ
	virtual void NotBuyStuffs(Npc* npc) = 0;//���� �Ȼ�� �ൿ
	virtual void Act(Npc* npc) = 0;		//�̵� �ൿ (���¿� ���� �ٲ�����)
	virtual void GoHome(Npc* npc) = 0;		//���� ���� �ൿ
	
};

class NpcStateIdle : public NpcState
{
	//Npc�� �� ����ؼ� ����ƽ..
	static NpcStateIdle* instance;

public:
	static NpcStateIdle* GetInstance();

//	virtual void BuyStuffs(Npc* npc);
	virtual void NotBuyStuffs(Npc* npc);
	virtual void Act(Npc* npc);
	virtual void GoHome(Npc* npc);
};
class NpcStateDecide : public NpcState
{
	static NpcStateDecide* instance;

public:
	static NpcStateDecide* GetInstance();

//	virtual void BuyStuffs(Npc* npc);
	virtual void NotBuyStuffs(Npc* npc);
	virtual void Act(Npc* npc);
	virtual void GoHome(Npc* npc);

};
class NpcStateInline : public NpcState
{
	static NpcStateInline* instance;

public:
	static NpcStateInline* GetInstance();

//	virtual void BuyStuffs(Npc* npc);
	virtual void NotBuyStuffs(Npc* npc);
	virtual void Act(Npc* npc);
	virtual void GoHome(Npc* npc);

};
class NpcStateGoHome : public NpcState
{
	static NpcStateGoHome* instance;

public:
	static NpcStateGoHome* GetInstance();

//	virtual void BuyStuffs(Npc* npc);
	virtual void NotBuyStuffs(Npc* npc);
	virtual void Act(Npc* npc);
	virtual void GoHome(Npc* npc);

};
