#pragma once
#include "Npc.h"
#include "CheckStand.h"
#include "Astar.h"

class CheckStand;

class NpcManager
{
private:
	Npc* _npc;
	vector<Npc*> _vNpc;
	CheckStand* _checkStand;

	Astar* _ast;

	int _counter; //이 시간만큼 흐른 뒤 새로운 엔피씨 입장함
	int _timer;

public:
	void Init();
	void Update();
	void Release();
	void Render();

	void MakeNpc();
	void AstarFunction();
	void CheckStandCollision(); //계산대랑 충돌
	void ShopStandCollision(); //가판대랑 충돌

	void SetCheckStandLink(CheckStand* checkstand) { _checkStand = checkstand; }

};

