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

	_ability = new Ability(100, 100, 10); //�� ũ�� ��� �ϳ�?

	maxFrameX = 0;
	frameY = 0;
	_sprite = AddComponent<Sprite>();
	_sprite->Init(true, true);
	_sprite->SetImgName("Open_Boss");
	_sprite->SetRectColor(ColorF::Cornsilk);
	_trans->SetScale(Vector2(_sprite->GetGraphic()->GetFrameWidth(),
		_sprite->GetGraphic()->GetFrameHeight()));
	_trans->SetScale(Vector2(50, 50)); //���� ����
	_trans->SetPos(pos);
	_sprite->SetPosition(_trans->GetPos());
	_physics = AddComponent<PhysicsBody>();
	_physics->Init(BodyType::DYNAMIC, 1.0f);
	////���󼼰��� ��Ʈ ��Ʋ���°� ����
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
	//���������� ��..
	//
}

void Boss::BslimeAtk()
{
	//getangle �� �÷��̾� ���ؼ� �̹��� �þ
}

