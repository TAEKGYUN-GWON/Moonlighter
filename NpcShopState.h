#pragma once
#include "ShopStand.h"
#include "Npc.h"
#include "CheckStand.h"

class NpcShopState
{
protected:
	int _counter = 0; //idle ���¿� �ð����
	bool _isFunctionDone = false; //�Լ� ���ϴ��߳�? �ȴ�����

	ShopStand* _shopStand; //��ߵɰŰ��Ƽ� �־��
	Npc* _npc;
	CheckStand* _checkStand;

public :
	NpcShopState() {};
	~NpcShopState() {};

	virtual void StateIn(Npc* npc) = 0;
	virtual void StateStay(Npc* npc) = 0;
	virtual void StateOut(Npc* npc) = 0;
};

class NpcIdle : public NpcShopState
{
	static NpcIdle* instance;
public:
	static NpcIdle* GetInstance();

	virtual void StateIn(Npc* npc);
	virtual void StateStay(Npc* npc);
	virtual void StateOut(Npc* npc);
};
class NpcDecide : public NpcShopState
{
	static NpcDecide* instance;
public:
	static NpcDecide* GetInstance();

	virtual void StateIn(Npc* npc);
	virtual void StateStay(Npc* npc);
	virtual void StateOut(Npc* npc);
};
class NpcInline : public NpcShopState
{
	static NpcInline* instance;
public:
	static NpcInline* GetInstance();

	virtual void StateIn(Npc* npc);
	virtual void StateStay(Npc* npc);
	virtual void StateOut(Npc* npc);
};
class NpcExit : public NpcShopState
{
	static NpcExit* instance;
public:
	static NpcExit* GetInstance();

	virtual void StateIn(Npc* npc);
	virtual void StateStay(Npc* npc);
	virtual void StateOut(Npc* npc);
};
