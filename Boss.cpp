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
	_hp = new Ability(100, 100, 10); //더 크게 줘야 하나?

	_trans->SetScale(Vector2(_sprite->GetGraphic()->GetFrameWidth(),
		_sprite->GetGraphic()->GetFrameHeight()));

	_sprite = AddComponent<Sprite>();
	_sprite->Init(true, true);
	_sprite->SetRectColor(ColorF::Cornsilk);

	_physics = AddComponent<PhysicsBody>();
	_physics->Init(BodyType::DYNAMIC, 1.0f);
	////가상세계의 렉트 뒤틀리는거 고정
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

//■■■■■■■■■■■■ Idle ■■■■■■■■■■■■■■
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
//■■■■■■■■■■■ Attack ■■■■■■■■■■■■

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
	//플레이어가 있으면 때리고
	//플레이어가 없으면 아이들로 가고
	//맞았으면 hit로 가고
	//hp가 0이면 죽어라
}
//■■■■■■■■■■■■ Hit ■■■■■■■■■■■■■

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
	//플레이어가 있으면 때리고
	//플레이어가 없으면 아이들
	//체력이 0이면 죽어라
}
//■■■■■■■■■■■■ Dead ■■■■■■■■■■■■

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
	//아예 릴리즈 시켜줘야 함
}

