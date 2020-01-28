#pragma once
#include "Object.h"

class Hp;
class Inventory;
class PlayerState;

typedef enum class Direction
{
	Left,
	Left_Up,
	Left_Down,
	Up,
	Right,
	Right_Up,
	Right_Down,
	Down,
}Dir;

enum class AttackType
{
	Sword,
	Bow,
};

class Player : public Object
{
private:
	Inventory* _inven;
	Hp* _hp;
	Sprite* _sprite;
	PhysicsBody* _physics;

	PlayerState* _state;
	Direction _dir;
	AttackType _atkType;

	float _speed;

public:
	Player();
	~Player();

	virtual void Init();
	virtual void Update();
	virtual void Render();

	void ChangeState(PlayerState* state);
	void SetDirection(Direction dir) { _dir = dir; }
	void SetAttackType(AttackType type) { _atkType = type; }

	float GetSpeed() { return _speed; }
	Sprite* GetSprite() { return _sprite; }
	PhysicsBody* GetPhysics() { return _physics; }
	Inventory* GetInventory() { return _inven; }
	Direction GetDirection() { return _dir; }
	AttackType GetAttackType() { return _atkType; }
	Hp* GetHP() { return _hp; }
	PlayerState* GetState() { return _state; }
};

