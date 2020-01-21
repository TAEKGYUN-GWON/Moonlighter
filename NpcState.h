#pragma once
#include "ShopStand.h"
#include "Npc.h"

class NpcState
{
protected:
	int _counter = 0; //idle ���¿� �ð����
	bool _isFunctionDone = false; //�Լ� ���ϴ��߳�? �ȴ�����

	ShopStand* _shopStand; //��ߵɰŰ��Ƽ� �־��
	Npc* _npc;

public :
	NpcState() {};
	~NpcState() {};

	virtual void StateIn(Npc* npc) = 0;
	virtual void StateStay(Npc* npc) = 0;
	virtual void StateOut(Npc* npc) = 0;
};

class NpcIdle : public NpcState
{
	static NpcIdle* instance;
public:
	static NpcIdle* GetInstance();

	virtual void StateIn(Npc* npc);
	virtual void StateStay(Npc* npc);
	virtual void StateOut(Npc* npc);
};
class NpcDecide : public NpcState
{
	static NpcDecide* instance;
public:
	static NpcDecide* GetInstance();

	virtual void StateIn(Npc* npc);
	virtual void StateStay(Npc* npc);
	virtual void StateOut(Npc* npc);
};
class NpcInline : public NpcState
{
	static NpcInline* instance;
public:
	static NpcInline* GetInstance();

	virtual void StateIn(Npc* npc);
	virtual void StateStay(Npc* npc);
	virtual void StateOut(Npc* npc);
};
class NpcExit : public NpcState
{
	static NpcExit* instance;
public:
	static NpcExit* GetInstance();

	virtual void StateIn(Npc* npc);
	virtual void StateStay(Npc* npc);
	virtual void StateOut(Npc* npc);
};
