#include "stdafx.h"
#include "Enemy.h"
#include "Ability.h"
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

	_tag = "enemy";
	_speed = 30.0f;
	_hp = new Ability;
	

}

void Enemy::Update()
{
	Object::Update();
	
	//getAngle(float x1, float y1, float x2, float y2);
	//�� ���� ���ؾ���..
	//Vector2::
	/*if (getAngle(_trans->GetPos().x, _trans->GetPos().y
		, _player->GetTrans()->GetPos().x, _player->GetTrans()->GetPos().y))
	{
		//left �ϋ� _dir = LEFT �̷���...?
		// rigt �ϋ�
		// up �϶�
		// down �϶�?
		//�ؼ� �̹��� �ٲ� �ְ�? 
	}*/
	
	
	//���� Update �ɾ���
	state->Update(this);


}

void Enemy::SetPath(list<Vector2> _path)
{
	this->_path.clear();
	this->_path = _path;
}

//hp�� 0�̸� �׾��
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
	//cout << "�� �ȵ���?" << endl;
}

void EnemyIdle::Update(Enemy* _sEnemy)
{
	
	if (KEYMANAGER->isOnceKeyDown('0'))
		
		EnemyBasic::Update(_sEnemy);
		Release(_sEnemy);
	
	//cout << "������?" << endl;
}

void EnemyIdle::Release(Enemy* _sEnemy)
{
	//cout << "move�� ��!!!" << endl;

	//if �÷��̾ ������
	SetEnemyState(_sEnemy, EnemyMove::GetInstance());
	// else if ü���� 0 �̸� �׾��!
	if (_sEnemy->GetHP()->IsDead())
	{
		SetEnemyState(_sEnemy, EnemyDead::GetInstance());
	}
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
	//cout << "move ����?" << endl;

}

void EnemyMove::Update(Enemy* _sEnemy)
{

	EnemyBasic::Update(_sEnemy);
	_sEnemy->GetPhysics()->SetBodyPosition();
	//cout << "����� ���� ���� �ε�ĩ" << endl;
	Release(_sEnemy);
}

void EnemyMove::Release(Enemy* _sEnemy)
{
	//if ������ �÷��̾ ������ �����ϰ�
	SetEnemyState(_sEnemy, EnemyAttack::GetInstance());
	// else if ������ �÷��̾ ������ �ٽ� ����
	//SetEnemyState(_sEnemy, EnemyMove::GetInstance());
	// else if ü���� 0 �̸� �׾��!
	if (_sEnemy->GetHP()->IsDead())
	{
		SetEnemyState(_sEnemy, EnemyDead::GetInstance());
	}
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
	//cout << "���� ���Դ�?" << endl;
}

void EnemyAttack::Update(Enemy* _sEnemy)
{
	EnemyBasic::Update(_sEnemy);
	_sEnemy->Attack();
	//cout << "����� ����!" << endl;
	Release(_sEnemy);
}

void EnemyAttack::Release(Enemy* _sEnemy)
{
	//if �÷��̾����� ������ �´� ���·� ����
	SetEnemyState(_sEnemy, EnemyHit::GetInstance());
	// else if �ƴϸ� idle�� ����
	//SetEnemyState(_sEnemy, EnemyIdle::GetInstance());
	// else if ü���� 0 �̸� �׾��!
	if (_sEnemy->GetHP()->IsDead())
	{
		SetEnemyState(_sEnemy, EnemyDead::GetInstance());
	}
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
	//cout << "����� �¾Ҵٰ� �ϴ� �κ�" << endl;
}

void EnemyHit::Update(Enemy* _sEnemy)
{
	EnemyBasic::Update(_sEnemy);
	//cout << "�÷��̾����� �¾ҳ�?" << endl;
	Release(_sEnemy);
}

void EnemyHit::Release(Enemy* _sEnemy)
{
	// if �¾����� idle�� ����
	// else if �ȸ¾����� �ٽ� ������
	// else if ü���� 0 �̸� �׾��!
	if (_sEnemy->GetHP()->IsDead())
	{
		SetEnemyState(_sEnemy, EnemyDead::GetInstance());
	}

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
	//cout << "����� ���� ����" << endl;
}

void EnemyDead::Update(Enemy* _sEnemy)
{
//	cout << "�׾���?" << endl;
	Release(_sEnemy);
}

void EnemyDead::Release(Enemy* _sEnemy)
{
	//if (_sEnemy->GetHP()->IsDead())
	//cout << "�׾��� �Ф�" << endl;
//	_sEnemy->Release();
}
