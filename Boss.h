#pragma once
#include "Object.h"
#include "Ability.h"
#include "Player.h"

class BossBasic;
class BossIdle;
class BossAttack;
class BossHit;
class BossDead;


//보스 공격 패턴
enum PHASE
{
	ROCK,
	HAND,
	SLIME
};

class Boss : public Object
{
protected:
	Sprite* _sprite;
	PhysicsBody* _physics;
	Player* _player;
	float _speed; //굳이 있어야 하나?

	Ability* _ability;
	int _angle;
	
	list<Vector2> _path;

public:
	Boss();
	~Boss();

	PHASE _phase;

	int maxFrameX;
	int frameY;


	void Init(Vector2 pos);
	void Update();
	void Render();
	void Release();
	
	
	void Attack();
	void RockAtk();
	void BslimeAtk();

	//스킬(?)마다 함수로 뻬자
	//그리고 어택에서 스위치문하고
	//어택을 업데이트에 걸어주면 되나??

	Ability* GetHP() { return _ability; }
	PhysicsBody* GetPhysics() { return _physics; }
	Sprite* GetSprite() { return _sprite; }
	Player* GetPlayer() { return _player; }
	PHASE GetPhase() { return _phase; }

	
};