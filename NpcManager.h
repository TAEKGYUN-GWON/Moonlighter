#pragma once
#include <vector>
#include "Npc.h"

class NpcManager
{
private:
	Npc* _npc;
	vector<Npc*> _vNpc;

public:
	void Init();
	void Update();
	void Release();
	void Render();

	void StateControl();

};

//npc �߿� isactive(����ø��� �ٸ��� �����) �� �ְ� ������
//erase.

