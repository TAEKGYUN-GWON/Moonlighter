#pragma once
#include "Object.h"

class Player : public Object
{
private:
	Sprite* _sprite;
	PhysicsBody* _physics;

public:
	Player();
	~Player();

	virtual void Init();
	virtual void Update();
};

