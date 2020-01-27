#pragma once
#include "Object.h"
#include "ShopStand.h"
#include "CheckStand.h"
#include "Sprite.h"

class ShopStand;
class CheckStand;
class NpcShopState;

class Npc :	public Object
{
private:
	//Sprite* _sprite;

	float _speed;
	bool _isShopSOn;	//가판대랑 충돌중인지
	bool _isCheckSOn;	//계산대랑 충돌중인지



	NpcShopState* _npcShopState;

	ShopStand* _shopStand;
	CheckStand* _checkStand;

	//list<Vector2> _lPath;

	Sprite* _sprite;

	//리스트 벡터2 값 만들어놔야함, a스타용 

public:
	Npc() {};
	~Npc() {};

	virtual void Init(string imgkey) ;
	virtual void Release() override;
	virtual void Update() override;
	virtual void Render() override;

	//void Move();

	void SetNpcState(NpcShopState* npcshopstate);
	//void SetPath(list<Vector2> lpath);

	void In();
	void Stay();
	void Out();

	void SetCheckStandLink(CheckStand* checkstand) { _checkStand = checkstand; }
	CheckStand* GetCheckStand() { return _checkStand; }

	//계산대랑 가판대랑 충돌중ING인지 체크할 bool
	void SetIsShopSOn(bool shop) { _isShopSOn = shop; }
	void SetIsCheckSOn(bool check) { _isCheckSOn = check; }
	bool GetIsShopSOn() { return _isShopSOn; }
	bool GetIsCheckSOn() { return _isCheckSOn; }

};

