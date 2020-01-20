#pragma once
#include "Object.h"
#include "ShopStand.h"

class NpcState;

class Npc :	public Object
{
private:
	Sprite* _sprite;
	PhysicsBody* _physics;
	float _speed;

	ShopStand* _shopStand;
	NpcState* _npcState;

public:
	Npc();

	virtual void Init() override;
	virtual void Release() override;
	virtual void Update() override;
	virtual void Render() override;

	void SetState(NpcState* npcstate);	//상태 정의 
	void Act();			//물건 사기, 이동 등 행동
	void NotBuyStuffs();//물건 안사기 행동
	void GoHome();		//집에 가기 행동


};

