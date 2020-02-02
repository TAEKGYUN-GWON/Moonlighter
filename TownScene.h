#pragma once
#include "Scene.h"
#include "Player.h"
#include "Maptool.h"
#include "Smithy.h"
#include "Npc.h"

class TownScene : public Scene
{
private:
	Tile* _tiles[TILENUMX * TILENUMY];
	tagTile _tagTiles[TILENUMX * TILENUMY];
	Player* _player;


	Smithy* _smithy;


	//���尣 ������
	Object* _smithh;
	Graphic* _smith;
	Graphic* _j;
	int _frameCount, _frameX;

	//���� �ֹε�
	vector<Npc*> _vNpc;

public:
	virtual void Init();
	virtual void Update();

	void SetUp();
	void Render();

	bool ShowJ();

	void CreateNPC();

};

