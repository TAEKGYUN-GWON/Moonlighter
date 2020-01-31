#pragma once
#include "Object.h"
#include "ShopStand.h"
#include "CheckStand.h"
#include "Sprite.h"
#define NPDSPEED 70

class ShopStand;
class CheckStand;
class NpcShopState;

class Npc :	public Object
{
private:
	Sprite* _sprite;

	//float _speed;
	bool _isShopSOn;	//가판대랑 충돌중인지
	bool _isCheckSOn;	//계산대랑 충돌중인지
	bool _isAstarOn=true;	//astar 받아야하는 상태인지

	
	NpcShopState* _npcShopState;

	ShopStand* _shopStand;
	CheckStand* _checkStand;

	list<Vector2> _lPath;

	Vector2 _destination; //astar 목적지임



public:
	Npc() {};
	~Npc() {};

	virtual void Init(string imgkey);
	virtual void Release() override;
	virtual void Update() override;
	virtual void Render() override;

	void SetPath(list<Vector2> lpath);
	void Move();
	void SetNpcState(NpcShopState* npcshopstate);
	

	//상태패턴 정의용 함수
	void In();
	void Stay();
	void Out();

	//계산대 링크용
	void SetCheckStandLink(CheckStand* checkstand) { _checkStand = checkstand; }
	CheckStand* GetCheckStand() { return _checkStand; }

	//계산대랑 가판대랑 충돌중ING인지 체크할 bool
	void SetIsShopSOn(bool shop) { _isShopSOn = shop; }
	bool GetIsShopSOn() { return _isShopSOn; }
	void SetIsCheckSOn(bool check) { _isCheckSOn = check; }
	bool GetIsCheckSOn() { return _isCheckSOn; }
	void SetIsAstarOn(bool ast) { _isAstarOn = ast; }
	bool GetIsAstarOn() { return _isAstarOn; }
	void SetDestination(Vector2 destination) { _destination = destination; }
	Vector2 GetDestination() { return _destination; }

	NpcShopState* GetState() {	return _npcShopState; }
};

