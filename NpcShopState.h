#pragma once
#include "ShopStand.h"
#include "CheckStand.h"

class Npc;

class NpcShopState
{
protected:
	int _counter = 0; //idle 상태에 시간잴거

	ShopStand* _shopStand; //써야될거같아서 넣어둠
	CheckStand* _checkStand;

public :
	NpcShopState() {};
	~NpcShopState() {};

	void SetCheckStandLink(CheckStand* checkstand) { _checkStand = checkstand; }

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
