#pragma once
#include "Object.h"

class Hp;
class Inventory;
class PlayerState;

class Player : public Object
{
private:
	Inventory* _inven;
	Hp* _hp;
	Sprite* _sprite;
	PhysicsBody* _physics;

	PlayerState* _state;

	float _speed;

public:
	Player();
	~Player();

	virtual void Init();
	virtual void Update();
	virtual void Render();

	void ChangeState(PlayerState* state);

	Sprite* GetSprite() { return _sprite; }
	Inventory* GetInventory() { return _inven; }
	Hp* GetHP() { return _hp; }
	PlayerState* GetState() { return _state; }
};

