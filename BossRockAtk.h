#pragma once
#include "BossAttack.h"
#include "Boss.h"

enum class ROCKATK
{
	START,
	END
};

class BossRockAtk : public BossAttack
{
private:

	int _count = 0;
	float timer = 0;

	ROCKATK _state;
	vector<Object*>rocks;

public:
	BossRockAtk(Boss* _boss) : BossAttack(_boss) {}

	virtual void Enter() override;
	virtual void Update() override;
	virtual void Exit() override;
};

