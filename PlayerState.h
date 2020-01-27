#pragma once

class Player;

class PlayerState abstract
{
protected:
	Player* _obj;

public:
	PlayerState() {}
	PlayerState(Player* obj) : _obj(obj) {}

	virtual void Enter() {}
	virtual void Update() {}
	virtual void Exit() {}
};

