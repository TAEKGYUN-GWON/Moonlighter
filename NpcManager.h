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

	int _counter; //�� �ð���ŭ �帥 �� ���ο� ���Ǿ� ������

public:
	void Init();
	void Update();
	void Release();
	void Render();

	void StateControl();

	void SetCheckStandLink(CheckStand* checkstand) { _checkStand = checkstand; }

};

//npc �߿� isactive(����ø��� �ٸ��� �����) �� �ְ� ������
//erase.

