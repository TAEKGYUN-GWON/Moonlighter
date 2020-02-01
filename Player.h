#pragma once
#include "Object.h"
#include "Bullet.h"

class Ability;
class Inventory;
class PlayerState;

typedef enum class Direction : byte
{
	Right = 0,
	Right_Up,
	Up,
	Left_Up,
	Left,
	Left_Down,
	Down,
	Right_Down,
}Dir;

enum class AttackType : byte
{
	Sword,
	Bow,
};

class Player : public Object
{
private:
	Inventory* _inven;
	Ability* _ability;
	Sprite* _sprite;
	PhysicsBody* _physics;

	PlayerState* _state;
	Direction _dir;
	AttackType _atkType;
	BulletObjPool* _pool;

	float _speed;

public:
	Player();
	~Player();

	virtual void Init();
	virtual void Update();
	virtual void Render();
	virtual void Release();

	void ChangeState(PlayerState* state);
	void SetDirection(Direction dir) { _dir = dir; }
	void SetAttackType(AttackType type) { _atkType = type; }

	float GetSpeed() { return _speed; }
	Sprite* GetSprite() { return _sprite; }
	PhysicsBody* GetPhysics() { return _physics; }
	Inventory* GetInventory() { return _inven; }
	Direction GetDirection() { return _dir; }
	AttackType GetAttackType() { return _atkType; }
	Ability* GetAbility() { return _ability; }
	PlayerState* GetState() { return _state; }
	BulletObjPool* GetBulletPool() { return _pool; }
};

