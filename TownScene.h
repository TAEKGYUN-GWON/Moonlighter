#pragma once
#include "Scene.h"
#include "Player.h"
#include "Maptool.h"
#include "Smithy.h"
#include "Npc.h"
#include "Astar.h"

class TownScene : public Scene
{
private:
	//Tile* _tiles[TILENUMX * TILENUMY];
	vector<Tile*> _tiles;
	tagTile _tagTiles[TILENUMX * TILENUMY];
	Player* _player;


	Smithy* _smithy;


	//���尣 ������
	Object* _smithh;
	Graphic* _smith;
	Graphic* _j;
	int _frameCount, _frameX;

	//���� �ֹε�
	Astar* _aStar;

	vector<Vector2> _destination;

	//vector<int> _destCount;
	vector<int>	_destCount;

	vector<Npc*> _vNpc;


public:
	virtual void Init();
	virtual void Update();

	void SetUp();
	void Render();

	bool ShowJ();



	//NPC ����
	void CreateNPC();
	void FoundWay(Npc* npc, int i);

	void SetDest();

	Vector2 ReturnDest(int i);

	void MoveNPC();

};



