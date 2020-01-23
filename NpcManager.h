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

	void CheckStandCollision(); //����� �浹
	void ShopStandCollision(); //���Ǵ�� �浹

	void SetCheckStandLink(CheckStand* checkstand) { _checkStand = checkstand; }

};

