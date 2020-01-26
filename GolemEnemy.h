#pragma once
#include "Enemy.h"

class GolemEnemy : public Enemy
{
protected:

public:
	GolemEnemy();
	~GolemEnemy();

	void Init();
	void Update();
	void Attack();
};

