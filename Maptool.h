#pragma once
#include "Scene.h"
#include "Tile.h"

//#define SAMPLE_TILE_X_NUM 8//32
//#define SAMPLE_TILE_Y_NUM 10//20

#define SAMPLE_TILE_X_NUM 4
#define SAMPLE_TILE_Y_NUM 6

#define COL_SIZE 25

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

	Vector2 startPos;
	Vector2 size;

	Vector2 startPos2;
	Vector2 size2;

	//Vector2 colSize;
	PIVOT pivot;
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

enum Attribute
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
	//Attribute attribute;
	string attribute;
	Vector2 startPos;
	Vector2 startPos2;
	Vector2 size;
	Vector2 size2;
	bool isFrame;
	int frameX;
	int frameY;
	int id;
	PIVOT pivot;

	tagTile()
	{
		imgKey.clear();
		attribute = "None";
		isFrame = false;
		frameX = 1;
		frameY = 1;
		id = 0;
		pivot = PIVOT::CENTER;
		startPos = Vector2(1, 1);
		size = Vector2(1, 1);
		startPos2 = Vector2(1, 1);
		size2 = Vector2(1, 1);
		id = 0;
	}

	//tagTile* Clone(string imgKey, Attribute attribute, bool isFrame, int frameX, int frameY, PIVOT pivot, Vector2 size)
	tagTile* Clone(string imgKey, string attribute, bool isFrame, int frameX, int frameY, PIVOT pivot, Vector2 startPos, Vector2 size, Vector2 startPos2, Vector2 size2)
	{
		tagTile* tile = new tagTile;
		tile->imgKey = imgKey;
		tile->attribute = attribute;
		tile->isFrame = isFrame;
		tile->frameX = frameX;
		tile->frameY = frameY;
		tile->pivot = pivot;
		tile->startPos = startPos;
		tile->size = size;
		tile->startPos2 = startPos2;
		tile->size2 = size2;
		tile->id = 0;
		return tile;
	}

	//tagTile* Clone(string imgKey, Attribute attribute, bool isFrame, int frameX, int frameY, PIVOT pivot)
	tagTile* Clone(string imgKey, string attribute, bool isFrame, int frameX, int frameY, PIVOT pivot, Vector2 startPos, Vector2 size)
	{
		tagTile* tile = new tagTile;
		tile->imgKey = imgKey;
		tile->attribute = attribute;
		tile->isFrame = isFrame;
		tile->frameX = frameX;
		tile->frameY = frameY;
		tile->pivot = pivot;
		tile->startPos = startPos;
		tile->size = size;
		tile->startPos2 = Vector2(1, 1);
		tile->size2 = Vector2(1, 1);
		tile->id = 0;
		return tile;
	}
};
#include"Player.h"
class Maptool : public Scene
{
private:
	

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
	int _id;

	int a;

	Object* _btn1;
	Object* obj;

	bool _isDown;

	POINT _prevMouse;

	Player* p;

public:
	virtual void Init();
	virtual void Update();
	virtual void Render();

	void SetUp();
	void SetMap();
	void RemoveObject();
	//void FindIndex(int curIdx, Vector2 size);
	void SetAttribute(int curIdx, Vector2 size);
	void SetAttribute(int curIdx, Vector2 StartPos, Vector2 size);
	void SetAttribute(int curIdx, Vector2 StartPos, Vector2 size, Vector2 StartPos2, Vector2 size2, string attribute);

	int FindId();

	tagTile* FindTile(string imgKey);
};

