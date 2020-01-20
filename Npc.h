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

	void SetState(NpcState* npcstate);	//���� ���� 
	void Act();			//���� ���, �̵� �� �ൿ
	void NotBuyStuffs();//���� �Ȼ�� �ൿ
	void GoHome();		//���� ���� �ൿ


};

