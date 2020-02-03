#pragma once
#include "Npc.h"
#include "Astar.h"
#include "ShopScene.h"

class ShopStandManager;
class CheckStand;
class ShopScene;

enum DESTINATION
{
	WINDOW,
	STAND1,
	STAND2,
	STAND3,
	STAND4,
	CHECKSTAND,
	END
};
class NpcManager
{
private:
	vector<Npc*> _vNpc;
	ShopStandManager* _shopStandMgr;
	CheckStand* _checkStand;

	Vector2 _positions[DESTINATION::END];

	DESTINATION _destination;


	Astar* _ast;

	int _counter; //이 시간만큼 흐른 뒤 새로운 엔피씨 입장함
	int _timer;


public:
	void Init(ShopScene* parent);
	void Update();
	void Release();
	

	void MakeNpc();
	void SetAstar(); //목적지 정해주는것임
	void AstarFunction(int i, int astar); //astar 돌아가는 곳

	void CheckStandCollision(); //계산대랑 충돌
	void ShopStandCollision(); //가판대랑 충돌

	void SetCheckStandLink(CheckStand* checkstand) { _checkStand = checkstand; }
	void SetShopStandMgrLink(ShopStandManager* shopstsandmgr) { _shopStandMgr = shopstsandmgr; }
	vector<Npc*> GetNpcVector() { return _vNpc; }

};

