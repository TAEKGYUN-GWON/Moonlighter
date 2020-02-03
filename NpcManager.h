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

	int _counter; //�� �ð���ŭ �帥 �� ���ο� ���Ǿ� ������
	int _timer;


public:
	void Init(ShopScene* parent);
	void Update();
	void Release();
	

	void MakeNpc();
	void SetAstar(); //������ �����ִ°���
	void AstarFunction(int i, int astar); //astar ���ư��� ��

	void CheckStandCollision(); //����� �浹
	void ShopStandCollision(); //���Ǵ�� �浹

	void SetCheckStandLink(CheckStand* checkstand) { _checkStand = checkstand; }
	void SetShopStandMgrLink(ShopStandManager* shopstsandmgr) { _shopStandMgr = shopstsandmgr; }
	vector<Npc*> GetNpcVector() { return _vNpc; }

};

