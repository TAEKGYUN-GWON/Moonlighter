#include "stdafx.h"
#include "Boss.h"
#include "Ability.h"


Boss::Boss()
{
	
}

Boss::~Boss()
{
}

void Boss::Init(Vector2 pos)
{
	Object::Init();

	GRAPHICMANAGER->AddFrameImage("Open_Boss", L"resource/img/Enemy/createBoss.png", 32, 1);

	_tag = "boss";
	_name = "Boss";

	_ability = new Ability(100, 100, 10); //더 크게 줘야 하나?

	maxFrameX = 0;
	frameY = 0;
	_sprite = AddComponent<Sprite>();
	_sprite->Init(true, true);
	_sprite->SetImgName("Open_Boss");
	_sprite->SetRectColor(ColorF::Cornsilk);
	_trans->SetScale(Vector2(_sprite->GetGraphic()->GetFrameWidth(),
		_sprite->GetGraphic()->GetFrameHeight()));
	_trans->SetScale(Vector2(50, 50)); //보스 범위
	_trans->SetPos(pos);
	_sprite->SetPosition(_trans->GetPos());
	_physics = AddComponent<PhysicsBody>();
	_physics->Init(BodyType::DYNAMIC, 1.0f);
	////가상세계의 렉트 뒤틀리는거 고정
	_physics->GetBody()->SetFixedRotation(true);
	

	
}

void Boss::Update()
{
	Object::Update();

	//_sprite->GetCurrentFrameX();
}

void Boss::Render()
{
	Object::Render();

	
}

void Boss::Release()
{
	Object::Release();
}

void Boss::Attack()
{
	switch (_phase)
	{
	case ROCK:
		break;
	case HAND:
		break;
	case SLIME:
		break;
	}
}


void Boss::RockAtk()
{
	//순차적으로 깔림..
	//
}

void Boss::BslimeAtk()
{
	//getangle 로 플레이어 향해서 이미지 늘어남
}

