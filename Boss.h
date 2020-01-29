#pragma once
#include "Object.h"
#include "Ability.h"

class BossBasic;
class BossIdle;
class BossAttack;
class BossHit;
class BossDead;

//���� ���� ����
enum PHASE
{
	ONE,
	TWO,
	TREE
};

class Boss : public Object
{
protected:
	Sprite* _sprite;
	PhysicsBody* _physics;
	BossBasic* state;
	float _speed; //���� �־�� �ϳ�?

	Ability* _hp;

public:
	Boss();
	~Boss();

	PHASE _phase;

	void SetState(BossBasic* state);

	void Init();
	void Update();
	void Render();
	void Release();

	Ability* GetHP() { return _hp; }
	PhysicsBody* GetPhysics() { return _physics; }

};

class BossBasic
{
protected:

	void SetBossState(Boss* _sBoss, BossBasic* _BossState)
	{
		_sBoss->SetState(_BossState);
	}
public:
	virtual void Init(Boss* _sBoss) {};
	virtual void Update(Boss* _sBoss);
	virtual void Release(Boss* _sBoss) {};
};
//������������� Idle ���������������
class BossIdle : public BossBasic
{

	static BossIdle* instance;

public:
	//Idle�� �ƴ� �ٸ� ���µ����� ������ �ν��Ͻ�
	static BossIdle* GetInstance();

	virtual void Init(Boss* _sBoss);
	virtual void Update(Boss* _sBoss);
	virtual void Release(Boss* _sBoss);
};
//������������� Move ��������������
//class BossMove : public BossBasic
//{
//	
//	static BossMove* instance;
//
//public:
//	static BossMove* GetInstance();
//
//	virtual void Init(Boss* _sBoss);
//	virtual void Update(Boss* _sBoss);
//	virtual void Release(Boss* _sBoss);
//};

//������������ Attack �������������
class BossAttack : public BossBasic
{

	static BossAttack* instance;

public:
	static BossAttack* GetInstance();

	virtual void Init(Boss* _sBoss);
	virtual void Update(Boss* _sBoss);
	virtual void Release(Boss* _sBoss);
};

//������������� Hit ��������������
class BossHit : public BossBasic
{

	static BossHit* instance;

public:
	static BossHit* GetInstance();

	virtual void Init(Boss* _sBoss);
	virtual void Update(Boss* _sBoss);
	virtual void Release(Boss* _sBoss);
};
//������������� Dead �������������

class BossDead : public BossBasic
{

	static BossDead* instance;

public:
	static BossDead* GetInstance();

	virtual void Init(Boss* _sBoss);
	virtual void Update(Boss* _sBoss);
	virtual void Release(Boss* _sBoss);
};