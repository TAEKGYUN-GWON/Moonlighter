#pragma once
#include "Object.h"
#include "ShopStand.h"
#include <list>

class NpcState;



class Npc :	public Object
{
private:
	Sprite* _sprite;
	PhysicsBody* _physics;
	float _speed;

	ShopStand* _shopStand;
	NpcState* _npcState;

	//리스트 벡터2 값 만들어놔야함, a스타용 

public:
	Npc() {};
	~Npc() {};

	virtual void Init() override;
	virtual void Release() override;
	virtual void Update() override;
	virtual void Render() override;

	void SetNpcState(NpcState* npcstate) { _npcState = npcstate; }

	void In();
	void Stay();
	void Out();


};

