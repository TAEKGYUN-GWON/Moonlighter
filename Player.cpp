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
	_trans->SetScale(Vector2(50, 100));

	_sprite = AddComponent<Sprite>();

	_physics = AddComponent<PhysicsBody>();
	_physics->Init(BodyType::DYNAMIC, 1.0f);

}

void Player::Update()
{
	Object::Update();

	if (KEYMANAGER->isStayKeyDown(VK_LEFT))
	{

	}

}
