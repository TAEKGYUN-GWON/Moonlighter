#pragma once
#include "Npc.h"
//#include "Astar.h"
//astar�� include���ڸ��� ������.. xmemory �ߴ°�..

class ShopStandManager;
class CheckStand;

class NpcManager
{
private:
	Npc* _npc;
	vector<Npc*> _vNpc;
	ShopStandManager* _shopStandMgr;
	CheckStand* _checkStand;



	//Astar* _ast;

	int _counter; //�� �ð���ŭ �帥 �� ���ο� ���Ǿ� ������
	int _timer;

public:
	void Init();
	void Update();
	void Release();
	void Render();

	void MakeNpc();
	//void AstarFunction();

	void CheckStandCollision(); //����� �浹
	void ShopStandCollision(); //���Ǵ�� �浹

	void SetCheckStandLink(CheckStand* checkstand) { _checkStand = checkstand; }
	void SetShopStandMgrLink(ShopStandManager* shopstsandmgr) { _shopStandMgr = shopstsandmgr; }
};

