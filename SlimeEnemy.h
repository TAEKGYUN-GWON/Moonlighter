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

	//void ���� ���� �Լ�

	void SetHP();
	void GetHP();
};

