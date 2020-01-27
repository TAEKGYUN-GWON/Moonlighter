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

	ShopStand* _shopStand;
	NpcShopState* _npcShopState;
	CheckStand* _checkStand;
	list<Vector2> _lPath;

	Sprite* _sprite;

	//리스트 벡터2 값 만들어놔야함, a스타용 

public:
	Npc() {};
	~Npc() {};

	virtual void Init(string imgkey) ;
	virtual void Release() override;
	virtual void Update() override;
	virtual void Render() override;
	
	void SetCheckStandLink(CheckStand* checkstand) { _checkStand = checkstand; }
	CheckStand* GetCheckStand() { return _checkStand; }
	void SetNpcState(NpcShopState* npcshopstate);
	void SetPath(list<Vector2> lpath);

	//void SetImgKey(string imgkey) { _sprite->SetImgName(imgkey); }

	void In();
	void Stay();
	void Out();


};

