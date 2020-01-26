#pragma once
#include "Object.h"



enum DIRECTION
{
	LEFT,
	RIGHT,
	UP,
	DOWN
};

//상태패턴을 위한 전방선언
class EnemyBasic;
class EnemyIdle;
class EnemyMove;
class EnemyAttack;
class EnemyHit;
class EnemyDead;

//hp, bullet
class Hp;
//class Bullet;

class Enemy : public Object
{
protected:
	Sprite* _sprite;
	PhysicsBody* _physics;
	//■■■■■■■ 상태패턴 틀이 되는 EnemyBasic를 Enemy에게 알려줌 ■■■■■■■
	EnemyBasic* state;
	float _speed;
	Hp* _hp;

	//타임도 줘야 하나?

public:
	Enemy();
	virtual~Enemy(); //상속

	DIRECTION _dir;	//방향
	//플레이어가 있냐 없냐 bool 값으루 해줘야 하나?

	//string _tag = "",pos 어디서 해주지?

	//상태패턴을 만들어서 Enemy에게 알려주기 위한 함수
	void SetState(EnemyBasic* state);
	//hp 생성시 정해주는거, hp 다 똑같이 할까?
	virtual void Init();
	virtual void Update();	//방향지정해줘야함->겟앵글로...
	virtual void Attack() {};
//get,set함수 만들어야 함
	Hp* GetHP() { return _hp; }
	PhysicsBody* GetPhysics() { return _physics; }
//아이템 떨굴 갯수 만들어야함

};

//■■■■■■■■■■■■■■ 상태 ■■■■■■■■■■■■■■■■

class EnemyBasic
{
protected:
	//상태패턴 내부에서 서로의 상태를 왔다 갔다 하기 위한 것.
	void SetEnemyState(Enemy* _sEnemy, EnemyBasic* _EnemyState)
	{
		_sEnemy->SetState(_EnemyState);
	}
public:
	//basic이라서 다 초기화 해준다.
	virtual void Init(Enemy* _sEnemy) {};
	virtual void Update(Enemy* _sEnemy);
	virtual void Release(Enemy* _sEnemy) {};
};
//■■■■■■■■■■■■ Idle ■■■■■■■■■■■■■■
class EnemyIdle : public EnemyBasic
{
	//상태를 객체화 해줌
static EnemyIdle* instance;

public:
	//Idle이 아닌 다른 상태들한테 보내줄 인스턴스
	static EnemyIdle* GetInstance();

	virtual void Init(Enemy* _sEnemy);
	virtual void Update(Enemy* _sEnemy);
	virtual void Release(Enemy* _sEnemy);
};
//■■■■■■■■■■■■ Move ■■■■■■■■■■■■■
class EnemyMove : public EnemyBasic
{
	//상태를 객체화 해줌
	static EnemyMove* instance;

public:
	static EnemyMove* GetInstance();

	virtual void Init(Enemy* _sEnemy);
	virtual void Update(Enemy* _sEnemy);
	virtual void Release(Enemy* _sEnemy);
};
//■■■■■■■■■■■ Attack ■■■■■■■■■■■■
class EnemyAttack : public EnemyBasic
{
	//상태를 객체화 해줌
	static EnemyAttack* instance;

public:
	static EnemyAttack* GetInstance();

	virtual void Init(Enemy* _sEnemy);
	virtual void Update(Enemy* _sEnemy);
	virtual void Release(Enemy* _sEnemy);
};

//■■■■■■■■■■■■ Hit ■■■■■■■■■■■■■
class EnemyHit : public EnemyBasic
{
	//상태를 객체화 해줌
	static EnemyHit* instance;

public:
	static EnemyHit* GetInstance();

	virtual void Init(Enemy* _sEnemy);
	virtual void Update(Enemy* _sEnemy);
	virtual void Release(Enemy* _sEnemy);
};
//■■■■■■■■■■■■ Dead ■■■■■■■■■■■■

class EnemyDead : public EnemyBasic
{
	//상태를 객체화 해줌
	static EnemyDead* instance;

public:
	static EnemyDead* GetInstance();

	virtual void Init(Enemy* _sEnemy);
	virtual void Update(Enemy* _sEnemy);
	virtual void Release(Enemy* _sEnemy);
};