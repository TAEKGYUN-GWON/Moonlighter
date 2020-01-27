#pragma once
#include "Maptool.h"
#include "Tile.h"
#include "Scene.h"
#include "Player.h"
#include "EnemyManeger.h"
#define Dungeon_X 39
#define Dungeon_Y 24
class EnemyManeger;
class Dungeon : public Scene
{
private:
	Tile* _tiles[Dungeon_X * Dungeon_Y];
	vector<Tile*> tiles;
	tagTile _tagTiles[Dungeon_X * Dungeon_Y];
	EnemyManeger* _eMgr;
	Vector2 pos;
	bool _isAllowInit = false;
public:
	virtual void Init(Vector2 start);
	virtual void Update();
	virtual void Render();
	void SetUp();
	vector<Tile*> GetTiles();
};

