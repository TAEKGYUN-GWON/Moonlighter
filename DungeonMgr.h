#pragma once
#include "Dungeon.h"
#include "Player.h"
class DungeonMgr
{
private:
	vector<Dungeon*> _rooms;
	Player* _player;

public:
	void Init(Player* player);
	void Update();
	void Render();
	vector<Dungeon*> GetRoom() { return _rooms; }
};

