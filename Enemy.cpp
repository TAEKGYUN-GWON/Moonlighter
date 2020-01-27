#include "stdafx.h"
#include "Enemy.h"
#include "Hp.h"
#include "Bullet.h"
//#include "Player.h"
//���漱�� ���� ��...?
EnemyIdle* EnemyIdle::instance;	
EnemyMove* EnemyMove::instance;
EnemyAttack* EnemyAttack::instance;
EnemyHit* EnemyHit::instance;
EnemyDead* EnemyDead::instance;

Enemy::Enemy()
{

	SetState(EnemyIdle::GetInstance());

	//cout << "�����ںκ� ���̵�" << endl;
	
}

Enemy::~Enemy()
{
}
//ó�� ���ʹ� ���� ���úκ� ���� Enemy::Init()���� ���� ������
void Enemy::SetState(EnemyBasic* state)
{
	this->state = state;
	this->state->Init(this);
}

void Enemy::Init()
{
	Object::Init();

	//enemy�� enemymaneger�� �ɾ��ְ� 
	//�Ŵ����� �������� �ɾ������.
	_tag = "enemy";
	_speed = 30.0f;
	

}

void Enemy::Update()
{
	Object::Update();
	//���� Update �ɾ���
	state->Update(this);
}

void EnemyBasic::Update(Enemy* _sEnemy)
{
	if (_sEnemy->GetHP()->IsDead())
	{
		SetEnemyState(_sEnemy, EnemyDead::GetInstance());
	}
}
//������������� Idle ���������������
EnemyIdle* EnemyIdle::GetInstance()
{

	//instance�� null�̸� 
	if (instance == nullptr)
	{
		//enemy���´� idle
		instance = new EnemyIdle();
	}
	//instance = new EnemyIdle(); ��� �������ϱ� EnemyIdle�� ��
	//���� state->Update(this); �ɾ������ϱ� Idle instance�� ������
	return instance;
}

void EnemyIdle::Init(Enemy* _sEnemy)
{
	cout << "�� �ȵ���?" << endl;
}

void EnemyIdle::Update(Enemy* _sEnemy)
{

	//getAngle(float x1, float y1, float x2, float y2);
	//�� ���� ���ؾ���...
	
	//ó�� ���� ��ġ����?
	if (KEYMANAGER->isOnceKeyDown('0'))
		//if () �ÿ��̾ ������ 
		EnemyBasic::Update(_sEnemy);
		Release(_sEnemy);
	cout << "������?" << endl;
}

void EnemyIdle::Release(Enemy* _sEnemy)
{
	cout << "move�� ��!!!" << endl;
	
	//if �÷��̾ ������
	SetEnemyState(_sEnemy, EnemyMove::GetInstance());
	// else if ü���� 0 �̸� �׾��!
	//SetEnemyState(_sEnemy, EnemyDead::GetInstance());
}
//������������� Move ��������������
EnemyMove* EnemyMove::GetInstance()
{
	if (instance == nullptr)
	{
		instance = new EnemyMove();
	}

	return instance;
}

void EnemyMove::Init(Enemy* _sEnemy)
{
	cout << "move ����?" << endl;

}

void EnemyMove::Update(Enemy* _sEnemy)
{

	EnemyBasic::Update(_sEnemy);
	_sEnemy->GetPhysics()->SetBodyPosition();
	cout << "����� ���� ���� �ε�ĩ" << endl;
	Release(_sEnemy);
}

void EnemyMove::Release(Enemy* _sEnemy)
{
	//if ������ �÷��̾ ������ �����ϰ�
	SetEnemyState(_sEnemy, EnemyAttack::GetInstance());
	// else if ������ �÷��̾ ������ �ٽ� ����
	//SetEnemyState(_sEnemy, EnemyMove::GetInstance());
	// else if ü���� 0 �̸� �׾��!
}
//������������ Attack �������������
EnemyAttack* EnemyAttack::GetInstance()
{
	if (instance == nullptr)
	{
		instance = new EnemyAttack();
	}

	return instance;
}

void EnemyAttack::Init(Enemy* _sEnemy)
{
	cout << "���� ���Դ�?" << endl;
}

void EnemyAttack::Update(Enemy* _sEnemy)
{

	EnemyBasic::Update(_sEnemy);
	_sEnemy->Attack();
	cout << "����� ����!" << endl;
	Release(_sEnemy);
}

void EnemyAttack::Release(Enemy* _sEnemy)
{
	//if �÷��̾����� ������ �´� ���·� ����
	SetEnemyState(_sEnemy, EnemyHit::GetInstance());
	// else if �ƴϸ� idle�� ����
	//SetEnemyState(_sEnemy, EnemyIdle::GetInstance());
	// else if ü���� 0 �̸� �׾��!
}
//������������� Hit ��������������

EnemyHit* EnemyHit::GetInstance()
{
	if (instance == nullptr)
	{
		instance = new EnemyHit();
	}

	return instance;
}

void EnemyHit::Init(Enemy* _sEnemy)
{
	cout << "����� �¾Ҵٰ� �ϴ� �κ�" << endl;
}

void EnemyHit::Update(Enemy* _sEnemy)
{
	EnemyBasic::Update(_sEnemy);
	cout << "�÷��̾����� �¾ҳ�?" << endl;
	Release(_sEnemy);
}

void EnemyHit::Release(Enemy* _sEnemy)
{
	// if �¾����� idle�� ����
	// else if �ȸ¾����� �ٽ� ������
	// else if ü���� 0 �̸� �׾��!
	SetEnemyState(_sEnemy, EnemyDead::GetInstance());

}
//������������� Dead �������������

EnemyDead* EnemyDead::GetInstance()
{
	if (instance == nullptr)
	{
		instance = new EnemyDead();
	}

	return instance;
}

void EnemyDead::Init(Enemy* _sEnemy)
{
	cout << "����� ���� ����" << endl;
}

void EnemyDead::Update(Enemy* _sEnemy)
{
	cout << "�׾���?" << endl;
	Release(_sEnemy);
}

void EnemyDead::Release(Enemy* _sEnemy)
{
	cout << "�׾��� �Ф�" << endl;

}
