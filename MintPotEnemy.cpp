#include "stdafx.h"
#include "MintPotEnemy.h"
#include "Hp.h"
#include "Bullet.h"

MintPotEnemy::MintPotEnemy()
{
}

MintPotEnemy::~MintPotEnemy()
{
}

void MintPotEnemy::Init(Vector2 pos)
{
	Enemy::Init();

	GRAPHICMANAGER->AddFrameImage("enemyPot", L"resource/img/Enemy/pot.png", 11, 4);

	_tag = "enemy";
	_name = "Pot";

	_hp = new Hp(30, 30);

	

	////�̹��� ũ��, pos�� ��� ���� �����ɶ� ��ȿ� �������� �ؾ� �Ұ� ����
	_sprite = AddComponent<Sprite>();
	_sprite->Init(true, true);
	_sprite->SetImgName("enemyPot");
	_trans->SetScale(Vector2(_sprite->GetGraphic()->GetFrameWidth(),
		_sprite->GetGraphic()->GetFrameHeight()));
	_trans->SetPos(pos);
	//_sprite->SetMaxFrameX(5);
	//_sprite->SetFrameY(1);
	//_sprite->SetRectColor(ColorF::Cornsilk);
	_trans->SetScale(Vector2(20, 10));
	_physics = AddComponent<PhysicsBody>();
	_physics->Init(BodyType::DYNAMIC, 1.0f);
	////���󼼰��� ��Ʈ ��Ʋ���°� ����
	_physics->GetBody()->SetFixedRotation(true);

}

void MintPotEnemy::Update()
{
	Enemy::Update();
	_sprite->SetPosition(_trans->GetPos()+Vector2::up*10);
}

void MintPotEnemy::Attack()
{
}
