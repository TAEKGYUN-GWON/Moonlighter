#include "stdafx.h"
#include "Player.h"

Player::Player()
{
}

Player::~Player()
{
}

void Player::Init()
{
	Object::Init();

	_tag = "Player";
	_name = "Will";

	_trans->SetPos(WINSIZEX / 2, WINSIZEY / 2);
	_trans->SetScale(Vector2(30, 50));

	_sprite = AddComponent<Sprite>();

	_physics = AddComponent<PhysicsBody>();
	_physics->Init(BodyType::DYNAMIC, 1.0f);

	_speed = 3.0f;

}

void Player::Update()
{
	Object::Update();

	if (KEYMANAGER->isStayKeyDown(VK_LEFT)) _trans->SetPos(_trans->GetPos() + Vector2::left * _speed);
	else if (KEYMANAGER->isStayKeyDown(VK_RIGHT)) _trans->SetPos(_trans->GetPos() + Vector2::right * _speed);
	if (KEYMANAGER->isStayKeyDown(VK_UP)) _trans->SetPos(_trans->GetPos() + Vector2::up * _speed);
	else if (KEYMANAGER->isStayKeyDown(VK_DOWN)) _trans->SetPos(_trans->GetPos() + Vector2::down * _speed);
	_physics->SetBodyPosition();
}
