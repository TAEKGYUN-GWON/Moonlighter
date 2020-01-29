#pragma once
#include "Enemy.h"

class MintPotEnemy : public Enemy
{
protected:

public:
	MintPotEnemy();
	~MintPotEnemy();

	void Init(Vector2 pos);
	void Update();
	void Attack();
};

