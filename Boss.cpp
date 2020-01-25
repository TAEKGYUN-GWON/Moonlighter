#include "stdafx.h"
#include "Boss.h"

BossIdle* BossIdle::instance;
//BossMove* BossMove::instance;
BossAttack* BossAttack::instance;
BossHit* BossHit::instance;
BossDead* BossDead::instance;


Boss::Boss()
{
	SetState(BossIdle::GetInstance());
}

Boss::~Boss()
{
}

void Boss::SetState(BossBasic* state)
{
	this->state = state;
	this->state->Init(this);
}

void Boss::Init()
{
	Object::Init();


	

}

void Boss::Update()
{
	Object::Update();
}

void Boss::Render()
{
	Object::Render();
}

void Boss::Release()
{
}

//������������� Idle ���������������
BossIdle* BossIdle::GetInstance()
{
	if (instance == nullptr)
	{
		instance = new BossIdle();
	}
	return instance;
}

void BossIdle::Init(Boss* _sBoss)
{
}

void BossIdle::Update(Boss* _sBoss)
{
}

void BossIdle::Release(Boss* _sBoss)
{
	//�÷��̾ ������ �������� ����
	SetBossState(_sBoss, BossAttack::GetInstance());
	//�÷��̾ ������ ���̵�
}
//������������ Attack �������������

BossAttack* BossAttack::GetInstance()
{
	if (instance == nullptr)
	{
		instance = new BossAttack();
	}
	return instance;
}

void BossAttack::Init(Boss* _sBoss)
{
}

void BossAttack::Update(Boss* _sBoss)
{
}

void BossAttack::Release(Boss* _sBoss)
{
	//�÷��̾ ������ ������
	//�÷��̾ ������ ���̵�� ����
	//�¾����� hit�� ����
	//hp�� 0�̸� �׾��
}
//������������� Hit ��������������

BossHit* BossHit::GetInstance()
{
	if (instance == nullptr)
	{
		instance = new BossHit();
	}
	return instance;
}

void BossHit::Init(Boss* _sBoss)
{
}

void BossHit::Update(Boss* _sBoss)
{
}

void BossHit::Release(Boss* _sBoss)
{
	//�÷��̾ ������ ������
	//�÷��̾ ������ ���̵�
	//ü���� 0�̸� �׾��
}
//������������� Dead �������������

BossDead* BossDead::GetInstance()
{
	if (instance == nullptr)
	{
		instance = new BossDead();
	}
	return instance;
}

void BossDead::Init(Boss* _sBoss)
{
}

void BossDead::Update(Boss* _sBoss)
{
}

void BossDead::Release(Boss* _sBoss)
{
	//�ƿ� ������ ������� ��
}
