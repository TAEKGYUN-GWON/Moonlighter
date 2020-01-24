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

	_sprite = AddComponent<Sprite>();
	_sprite->Init(true, true);
	_sprite->SetImgName("will_dungeon");
	_sprite->SetMaxFrameX(7);
	_sprite->SetFrameY(1);
	_sprite->SetFPS(10.f);
	//_sprite->GetGraphic()->SetScale(Vector2(100, 100));
	_sprite->GetGraphic()->SetSize(Vector2(100, 100));

	_trans->SetPos(WINSIZEX / 2, WINSIZEY / 2);
	_trans->SetScale(Vector2(_sprite->GetGraphic()->GetFrameWidth(), _sprite->GetGraphic()->GetFrameHeight()));

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
