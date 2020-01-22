#pragma once
#include "Object.h"
#include "ShopStand.h"
#include <list>

class NpcShopState;

class Npc :	public Object
{
private:
	Sprite* _sprite;
	PhysicsBody* _physics;
	float _speed;

	ShopStand* _shopStand;
	NpcShopState* _npcShopState;

	//리스트 벡터2 값 만들어놔야함, a스타용 

public:
	Npc() {};
	~Npc() {};

	virtual void Init() override;
	virtual void Release() override;
	virtual void Update() override;
	virtual void Render() override;

	void SetNpcState(NpcShopState* npcshopstate) { _npcShopState = npcshopstate; }

	void In();
	void Stay();
	void Out();


};

