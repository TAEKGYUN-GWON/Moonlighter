#pragma once
#include "PlayerState.h"
#include "Player.h"

class PlayerAttack : public PlayerState
{
private:
	int _count;
	float _timer;
	float _delay;

	//bool _isAtk;

public:
	PlayerAttack(Player* obj) : PlayerState(obj) {}

	virtual void Enter() override;
	virtual void Update() override;
	virtual void Exit() override;
};

