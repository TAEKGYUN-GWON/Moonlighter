#pragma once
#include "Dungeon.h"
class DungeonMgr
{
private:
	vector<Dungeon*> _rooms;

public:
	void Init();
	void Update();
	void Render();

};

