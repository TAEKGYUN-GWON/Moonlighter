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
	virtual void Idle(Npc* npc) = 0;
	virtual void Search(Npc* npc) = 0;
	virtual void Inline(Npc* npc) = 0;
	virtual void GoHome(Npc* npc) = 0;

};

class NpcStateIdle : NpcState
{
	//Npc°¡ ¾ê ½á¾ßÇØ¼­ ½ºÅÂÆ½..
	static NpcStateIdle* instance;

public:
	virtual void Idle(Npc* npc);
	virtual void Search(Npc* npc);
	virtual void Inline(Npc* npc);
	virtual void GoHome(Npc* npc);
};
class NpcStateSearch : NpcState
{

};
class NpcStateInline : NpcState
{

};
class NpcStateGoHome : NpcState
{

};
