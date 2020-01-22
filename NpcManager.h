#pragma once
#include <vector>
#include "Npc.h"
#include "CheckStand.h"

class CheckStand;

class NpcManager
{
private:
	Npc* _npc;
	vector<Npc*> _vNpc;
	CheckStand* _checkStand;

	int _counter; //이 시간만큼 흐른 뒤 새로운 엔피씨 입장함

public:
	void Init();
	void Update();
	void Release();
	void Render();

	void StateControl();

	void SetCheckStandLink(CheckStand* checkstand) { _checkStand = checkstand; }

};

//npc 중에 isactive(ㅇ기ㅓ말고 다른거 써야함) 인 애가 있으면
//erase.

