#pragma once
#include "Npc.h"
#include "Astar.h"
#include "ShopScene.h"

class ShopStandManager;
class CheckStand;
class ShopScene;

class NpcManager
{
private:
	Npc* _npc;
	vector<Npc*> _vNpc;
	ShopStandManager* _shopStandMgr;
	CheckStand* _checkStand;



	Astar* _ast;

	int _counter; //�� �ð���ŭ �帥 �� ���ο� ���Ǿ� ������
	int _timer;

public:
	void Init(ShopScene* parent);
	void Update();
	void Release();
	void Render();

	void MakeNpc();
	void AstarFunction(Vector2 destination);

	void CheckStandCollision(); //����� �浹
	void ShopStandCollision(); //���Ǵ�� �浹

	void SetCheckStandLink(CheckStand* checkstand) { _checkStand = checkstand; }
	void SetShopStandMgrLink(ShopStandManager* shopstsandmgr) { _shopStandMgr = shopstsandmgr; }
	vector<Npc*> GetNpcVector() { return _vNpc; }

};

