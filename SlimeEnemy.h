#pragma once
#include "Enemy.h"

class SlimeEnemy : public Enemy
{
protected:

public:
	SlimeEnemy();
	~SlimeEnemy();

	void Init();
	void Update();
	void Render();
	void Release();

	//void 공격 패턴 함수

	void SetHP();
	void GetHP();
};

