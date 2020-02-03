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
	string _prevScene;
	float _fadeAlpha;
	bool _isFade;

public:
	virtual void Init();
	virtual void Update();
	virtual void Release();

	void SetUp();
	void Render();
};

