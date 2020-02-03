#pragma once
#include "Object.h"
//#include "ShopStand.h"
//#include "ShopStandManager.h"
//#include "CheckStand.h"
//#include "Sprite.h"

#define NPDSPEED 70

class ShopStand;
class CheckStand;
class NpcShopState;

class Npc :	public Object
{
private:
	Sprite* _sprite;

	bool _isShopSOn;	//가판대랑 충돌중인지
	bool _isCheckSOn;	//계산대랑 충돌중인지

	bool _isAstarOn = true;	//astar 받아야하는 상태인지

	
	NpcShopState* _npcShopState;

	//ShopStand* _shopStand; //스탠드를 가져야될지 매니저를 가져야될지 모르겠음
	//ShopStandManager* _shopStandMgr;
	//CheckStand* _checkStand;

	list<Vector2> _lPath; //가야하는 길

public:
	Npc() {};
	~Npc() {};

	virtual void Init(string imgkey);
	virtual void Release() override;
	virtual void Update() override;
	virtual void Render() override;

	void SetPath(list<Vector2> lpath);
	
	//상태 정의용
	void ChangeState(NpcShopState* state);

	//계산대/판매대 링크용
	//void SetCheckStandLink(CheckStand* checkstand) { _checkStand = checkstand; }
	//CheckStand* GetCheckStand() { return _checkStand; }
	//void SetShopStandLink(ShopStandManager* shopstand) { _shopStandMgr = shopstand; }
	//ShopStandManager* GetShopStandMgr() { return _shopStandMgr; }

	//계산대랑 가판대랑 충돌중ING인지 체크할 bool
	void SetIsShopSOn(bool shop) { _isShopSOn = shop; }
	bool GetIsShopSOn() { return _isShopSOn; }
	void SetIsCheckSOn(bool check) { _isCheckSOn = check; }
	bool GetIsCheckSOn() { return _isCheckSOn; }
	void SetIsAstarOn(bool ast) { _isAstarOn = ast; }
	bool GetIsAstarOn() { return _isAstarOn; }

	//NpcShopState* GetStatePointer() { return _npcShopState; }

	Sprite* GetSprite() { return _sprite; }
	NpcShopState* GetState() {	return _npcShopState; }

	list<Vector2>* GetPath() { return &_lPath; }
};

