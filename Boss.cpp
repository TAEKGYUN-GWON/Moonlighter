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

	_tag = "enemy";
	_name = "Boss";
	//GRAPHICMANAGER->AddFrameImage("", L"resource/img/Enemy", , );
	_hp = new Ability(100, 100, 10); //�� ũ�� ��� �ϳ�?

	_trans->SetScale(Vector2(_sprite->GetGraphic()->GetFrameWidth(),
		_sprite->GetGraphic()->GetFrameHeight()));

	_sprite = AddComponent<Sprite>();
	_sprite->Init(true, true);
	_sprite->SetRectColor(ColorF::Cornsilk);

	_physics = AddComponent<PhysicsBody>();
	_physics->Init(BodyType::DYNAMIC, 1.0f);
	////���󼼰��� ��Ʈ ��Ʋ���°� ����
	_physics->GetBody()->SetFixedRotation(true);


}

void Boss::Update()
{
	Object::Update();

	state->Update(this);
}

void Boss::Render()
{
	Object::Render();
}

void Boss::Release()
{
}

void BossBasic::Update(Boss* _sBoss)
{
	if (_sBoss->GetHP()->IsDead())
	{
		SetBossState(_sBoss, BossDead::GetInstance());
	}
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

	BossBasic::Update(_sBoss);
	Release(_sBoss);
}

void BossIdle::Release(Boss* _sBoss)
{
	
	SetBossState(_sBoss, BossAttack::GetInstance());
	
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
	BossBasic::Update(_sBoss);
	Release(_sBoss);
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
	BossBasic::Update(_sBoss);
	Release(_sBoss);
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
	if (_sBoss->GetHP()->IsDead());
	Release(_sBoss);
}

void BossDead::Release(Boss* _sBoss)
{
	//�ƿ� ������ ������� ��
}

