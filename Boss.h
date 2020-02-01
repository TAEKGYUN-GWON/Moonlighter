#pragma once
#include "Object.h"
#include "Ability.h"
#include "Player.h"
#include"BossState.h"


class BossState;


//보스 공격 패턴
enum class PHASE
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

	PHASE _phase;
	Ability* _ability;
	BossState* _Bstate;
	Player* _player;
	list<Vector2> _path;

	vector<Object*> _rocks;

	vector<Enemy*> _enemys;

	int _angle;
	float _speed; //굳이 있어야 하나?

public:
	Boss();
	~Boss();


	int maxFrameX;
	int frameY;
	//float GetAtkArea() { return 200; }
	void Init(Vector2 pos);
	void Update();
	void Render();
	void Release();

	vector<Object*> GetRocks() { return _rocks; }

	void Attack();
	//void AttackEnd();
	vector<Enemy*>* GetEnemys() { return &_enemys; }

	//스킬(?)마다 함수로 뻬자
	//그리고 어택에서 스위치문하고
	//어택을 업데이트에 걸어주면 되나??

	Ability* GetHP() { return _ability; }
	PhysicsBody* GetPhysics() { return _physics; }
	Sprite* GetSprite() { return _sprite; }
	Player* GetPlayer() { return _player; }
	PHASE GetPhase() { return _phase; }
	BossState* GetState() { return _Bstate; }
	void SetState(BossState* state);
	
};