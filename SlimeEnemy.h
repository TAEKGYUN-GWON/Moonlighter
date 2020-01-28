#pragma once
#include "Enemy.h"


class SlimeEnemy : public Enemy
{
protected:
	
public:
	SlimeEnemy();
	~SlimeEnemy();

	//Sprite* SetSprite() { return _sprite; }
	void Init();
	void Update();
	void Attack();
};

