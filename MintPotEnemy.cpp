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

	

	////이미지 크기, pos는 어떻게 하지 생성될때 방안에 랜덤으로 해야 할거 같음
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
	////가상세계의 렉트 뒤틀리는거 고정
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
