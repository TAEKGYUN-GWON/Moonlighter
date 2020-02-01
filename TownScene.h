#pragma once
#include "Scene.h"
#include "Player.h"
#include "Maptool.h"
#include "Smithy.h"

class TownScene : public Scene
{
private:
	Tile* _tiles[TILENUMX * TILENUMY];
	tagTile _tagTiles[TILENUMX * TILENUMY];
	Player* _player;


	Smithy* _smithy;


	//대장간 아조시
	Object* _smithh;
	Graphic* _smith;
	Graphic* _j;
	int _frameCount, _frameX;

public:
	virtual void Init();
	virtual void Update();

	void SetUp();
	void Render();

	bool ShowJ();

};

