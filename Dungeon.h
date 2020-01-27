#pragma once
#include "Maptool.h"
#include "Tile.h"
#include "Scene.h"
#include "Player.h"
#define Dungeon_X 39
#define Dungeon_Y 24
class Dungeon : public Scene
{
private:
	Tile* _tiles[Dungeon_X * Dungeon_Y];
	tagTile _tagTiles[Dungeon_X * Dungeon_Y];

public:
	virtual void Init();
	virtual void Update();
	virtual void Render();
	void SetUp();
};

