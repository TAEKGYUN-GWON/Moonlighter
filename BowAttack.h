#pragma once
#include "PlayerAttack.h"
#include "Player.h"

class BowAttack : public PlayerAttack
{
private:

public:
	BowAttack(Player* obj) : PlayerAttack(obj) {}

	virtual void Enter() override;
	virtual void Update() override;
	virtual void Exit() override;
};

