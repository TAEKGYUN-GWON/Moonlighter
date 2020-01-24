#pragma once
#include "Object.h"

class Player : public Object
{
private:
	Sprite* _sprite;
	PhysicsBody* _physics;
	float _speed;

public:
	Player();
	~Player();

	virtual void Init();
	virtual void Update();
	Sprite* GetSprite() { return _sprite; }
};

