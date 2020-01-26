#pragma once
#include "Scene.h"
#include "Player.h"
#include "Maptool.h"

class TownScene : public Scene
{
private:
	Tile* _tiles[TILENUMX * TILENUMY];
	tagTile _tagTiles[TILENUMX * TILENUMY];
	Player* _player;
public:
	virtual void Init();
	virtual void Update();

	void SetUp();
	void Render();
};

