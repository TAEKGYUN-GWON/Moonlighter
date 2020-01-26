#pragma once
#include "Object.h"



enum DIRECTION
{
	LEFT,
	RIGHT,
	UP,
	DOWN
};

//���������� ���� ���漱��
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
	//�������� �������� Ʋ�� �Ǵ� EnemyBasic�� Enemy���� �˷��� ��������
	EnemyBasic* state;
	float _speed;
	Hp* _hp;

	//Ÿ�ӵ� ��� �ϳ�?

public:
	Enemy();
	virtual~Enemy(); //���

	DIRECTION _dir;	//����
	//�÷��̾ �ֳ� ���� bool ������ ����� �ϳ�?

	//string _tag = "",pos ��� ������?

	//���������� ���� Enemy���� �˷��ֱ� ���� �Լ�
	void SetState(EnemyBasic* state);
	//hp ������ �����ִ°�, hp �� �Ȱ��� �ұ�?
	virtual void Init();
	virtual void Update();	//���������������->�پޱ۷�...
	virtual void Attack() {};
//get,set�Լ� ������ ��
	Hp* GetHP() { return _hp; }
	PhysicsBody* GetPhysics() { return _physics; }
//������ ���� ���� ��������

};

//��������������� ���� �����������������

class EnemyBasic
{
protected:
	//�������� ���ο��� ������ ���¸� �Դ� ���� �ϱ� ���� ��.
	void SetEnemyState(Enemy* _sEnemy, EnemyBasic* _EnemyState)
	{
		_sEnemy->SetState(_EnemyState);
	}
public:
	//basic�̶� �� �ʱ�ȭ ���ش�.
	virtual void Init(Enemy* _sEnemy) {};
	virtual void Update(Enemy* _sEnemy);
	virtual void Release(Enemy* _sEnemy) {};
};
//������������� Idle ���������������
class EnemyIdle : public EnemyBasic
{
	//���¸� ��üȭ ����
static EnemyIdle* instance;

public:
	//Idle�� �ƴ� �ٸ� ���µ����� ������ �ν��Ͻ�
	static EnemyIdle* GetInstance();

	virtual void Init(Enemy* _sEnemy);
	virtual void Update(Enemy* _sEnemy);
	virtual void Release(Enemy* _sEnemy);
};
//������������� Move ��������������
class EnemyMove : public EnemyBasic
{
	//���¸� ��üȭ ����
	static EnemyMove* instance;

public:
	static EnemyMove* GetInstance();

	virtual void Init(Enemy* _sEnemy);
	virtual void Update(Enemy* _sEnemy);
	virtual void Release(Enemy* _sEnemy);
};
//������������ Attack �������������
class EnemyAttack : public EnemyBasic
{
	//���¸� ��üȭ ����
	static EnemyAttack* instance;

public:
	static EnemyAttack* GetInstance();

	virtual void Init(Enemy* _sEnemy);
	virtual void Update(Enemy* _sEnemy);
	virtual void Release(Enemy* _sEnemy);
};

//������������� Hit ��������������
class EnemyHit : public EnemyBasic
{
	//���¸� ��üȭ ����
	static EnemyHit* instance;

public:
	static EnemyHit* GetInstance();

	virtual void Init(Enemy* _sEnemy);
	virtual void Update(Enemy* _sEnemy);
	virtual void Release(Enemy* _sEnemy);
};
//������������� Dead �������������

class EnemyDead : public EnemyBasic
{
	//���¸� ��üȭ ����
	static EnemyDead* instance;

public:
	static EnemyDead* GetInstance();

	virtual void Init(Enemy* _sEnemy);
	virtual void Update(Enemy* _sEnemy);
	virtual void Release(Enemy* _sEnemy);
};