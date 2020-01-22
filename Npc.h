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

	//����Ʈ ����2 �� ����������, a��Ÿ�� 

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

