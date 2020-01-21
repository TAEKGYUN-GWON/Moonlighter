#pragma once
#include "ShopStand.h"
#include "Npc.h"

class NpcState
{
protected:
	int _counter; //idle 상태에 시간잴거

	ShopStand* _shopStand; //써야될거같아서 넣어둠
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
