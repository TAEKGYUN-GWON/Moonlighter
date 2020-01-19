#pragma once
#include "Npc.h"

class NpcState
{
private:



public:



	//setter
	void SetNpcState(Npc* npc, NPCSTATE* npcstate) 
	{ 
		npc->SetState(npcstate);
	}


};

class NpcStateIdle : NpcState
{

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
