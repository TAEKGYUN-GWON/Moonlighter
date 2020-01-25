#include "stdafx.h"
#include "Enemy.h"

//���漱�� ���� ��...?
EnemyIdle* EnemyIdle::instance;	
EnemyMove* EnemyMove::instance;
EnemyAttack* EnemyAttack::instance;
EnemyHit* EnemyHit::instance;
EnemyDead* EnemyDead::instance;
SlimeAtk* SlimeAtk::instance;

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
	_name = "minion1";
	
	//�̹��� ũ��, pos�� ��� ���� �����ɶ� ��ȿ� �������� �ؾ� �Ұ� ����
	_trans->SetPos(WINSIZEX / 2, WINSIZEY / 2 - 200); //->�������� ���߿� ����� ����
	_trans->SetScale(Vector2(100, 100));	
	//_trans->SetScale(Vector2(_sprite->GetGraphic()->GetFrameWidth(), 
	//	_sprite->GetGraphic()->GetFrameHeight()));

	_sprite = AddComponent<Sprite>();
	_sprite->SetRectColor(ColorF::Cornsilk);

	_physics = AddComponent<PhysicsBody>();
	_physics->Init(BodyType::DYNAMIC, 1.0f);	//�÷��̾����� �ո� �� �׷���?
	//���󼼰��� ��Ʈ ��Ʋ���°� ����
	_physics->GetBody()->SetFixedRotation(true);	

}

void Enemy::Update()
{
	Object::Update();
	_physics->SetBodyPosition();
	//���� Update �ɾ���
	state->Update(this);
}

void Enemy::Render()
{
	Object::Render();
}

void Enemy::Release()
{
	Object::Release();
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
	//ó�� ���� ��ġ����?
	if (KEYMANAGER->isOnceKeyDown('0'))
		//if () �ÿ��̾ ������ 
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

	
	if (_sEnemy->GetName() == "minion1")
	{
		SetEnemyState(_sEnemy, SlimeAtk::GetInstance());
		return;
	}
	else if (_sEnemy->GetName() == "minion2")
	{
		cout << "�̴Ͼ�2 ����" << endl;
		return;
	}
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
//  ������������� ������ ���� �������������
SlimeAtk* SlimeAtk::GetInstance()
{
	if (instance == nullptr)
	{
		instance = new SlimeAtk();
	}

	return instance;
}

void SlimeAtk::Update(Enemy* _sEnemy)
{
	cout << "�̴Ͼ�1 ����" << endl;
	//slime* a = (slime*)_sEnemy;
	//a->
	Release(_sEnemy);
}
