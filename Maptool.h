#pragma once
#include "Scene.h"
#include "Tile.h"

//#define SAMPLE_TILE_X_NUM 8//32
//#define SAMPLE_TILE_Y_NUM 10//20

#define SAMPLE_TILE_X_NUM 4//32
#define SAMPLE_TILE_Y_NUM 5//20

#pragma region 잠시보류

enum TERRAIN
{
	TR_CEMENT, TR_DESERT, TR_GRASS, TR_WATER, TR_END
};

enum OBJECT
{
	OBJ_WALL,
	OBJ_BLOCK1, OBJ_BLOCK3, OBJ_BLOCKS,	//벽돌 등 오브젝트
	OBJ_PLAYER,
	OBJ_ENEMY1, OBJ_ENEMY2,
	OBJ_ENEMY3, OBJ_ENEMY4,
	OBJ_NONE,							//나중에 지울용도
};

enum CTRL
{
	CTRL_SAVE,
	CTRL_LOAD,
	CTRL_TERRAINDRAW,
	CTRL_OBJDRAW,
	CTRL_ERASER,
	CTRL_END
};

struct tagCurrentTile
{
	string imgKey;
	bool isFrame;
	//int x;
	//int y;
};

struct tagSampleTile
{
	Vector2 pos;
	string imgKey;
	//int frameX;
	//int frameY;
};

#pragma endregion

enum class Attribute
{
	NONE_MOVE,
	DESTRUCTION,
	CLIFF,
	TERRAIN_DESTRUCTION,
	NONE,
};

struct tagTile
{
	string imgKey;
	Attribute attribute;
	vector<int> size;
	bool isFrame;
	int frameX;
	int frameY;

	tagTile()
	{
		imgKey.clear();
		attribute = Attribute::NONE;
		isFrame = false;
		frameX = 1;
		frameY = 1;
	}

	tagTile* Clone(string imgKey, Attribute attribute, bool isFrame, int frameX, int frameY)
	{
		tagTile* tile = new tagTile;
		tile->imgKey = imgKey;
		tile->attribute = attribute;
		tile->isFrame = isFrame;
		tile->frameX = frameX;
		tile->frameY = frameY;

		return tile;
	}
};

class Maptool : public Scene
{
private:
	typedef map<string, tagTile*> mapTileList;
	typedef map<string, tagTile*>::iterator mapTileIter;

private:
	//Tile* _currentTile;
	//Tile* _sampleTile[SAMPLE_TILE_X_NUM * SAMPLE_TILE_Y_NUM];

	tagCurrentTile _currentTile;
	tagSampleTile _sampleTile[SAMPLE_TILE_X_NUM * SAMPLE_TILE_Y_NUM];
	Tile* _tiles[TILENUMX * TILENUMY];

	mapTileList _mTileList;

	int _ctrSelect;
	int _curFrameX;
	int _curFrameY;

	int _index = 0;

	int a;

	Object* _btn1;
	Object* obj;

	bool _isDown;

	POINT _prevMouse;

public:
	virtual void Init();
	virtual void Update();
	virtual void Render();

	void SetUp();
	void SetMap();

	tagTile* FindTile(string imgKey);
};

