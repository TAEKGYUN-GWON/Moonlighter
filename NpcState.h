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
	virtual void BuyStuffs(Npc* npc) = 0;	//���� ��� �ൿ
	virtual void NotBuyStuffs(Npc* npc) = 0;//���� �Ȼ�� �ൿ
	virtual void Move(Npc* npc) = 0;		//�̵� �ൿ (���¿� ���� �ٲ�����)
	virtual void GoHome(Npc* npc) = 0;		//���� ���� �ൿ

};

class NpcStateIdle : NpcState
{
	//Npc�� �� ����ؼ� ����ƽ..
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
