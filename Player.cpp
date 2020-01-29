#include "stdafx.h"
#include "Player.h"
#include "Hp.h"
#include "Inventory.h"
#include "PlayerState.h"

Player::Player()
{
}

Player::~Player()
{
}

void Player::Init()
{
	Object::Init();

	GRAPHICMANAGER->AddFrameImage("will_dungeon", L"will_dungeon.png", 10, 13);

	_tag = "Player";
	_name = "Will";

	_trans->SetPos(WINSIZEX / 2, WINSIZEY / 2);
	_trans->SetScale(Vector2(36, 50));

	_sprite = AddComponent<Sprite>();
	_sprite->Init(true, true);
	_sprite->SetImgName("will_dungeon");
	_sprite->SetPosition(_trans->GetPos() + Vector2(0, 2));
	_sprite->SetMaxFrameX(7);
	_sprite->SetFrameY(1);

	//_sprite->GetGraphic()->SetSize(Vector2(200, 200));

	_physics = AddComponent<PhysicsBody>();
	_physics->Init(BodyType::DYNAMIC, 1.0f);
	_physics->GetBody()->SetFixedRotation(true);

	_hp = new Hp(100, 100);

	_speed = 300.0f;
}

void Player::Update()
{
	//if (_inven->GetActive()) return;

	if (KEYMANAGER->isStayKeyDown('P')) _hp->DamageHP(10);
	else if (KEYMANAGER->isStayKeyDown('O')) _hp->HealHP(10);

	if (!_hp->IsDead())
	{
		Object::Update();

		if (KEYMANAGER->isStayKeyDown(VK_LEFT))
		{
			_trans->SetPos(_trans->GetPos() + Vector2::left * _speed * TIMEMANAGER->getElapsedTime());
		}
		else if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
		{
			_trans->SetPos(_trans->GetPos() + Vector2::right * _speed * TIMEMANAGER->getElapsedTime());
		}
		if (KEYMANAGER->isStayKeyDown(VK_UP))
		{
			_trans->SetPos(_trans->GetPos() + Vector2::up * _speed * TIMEMANAGER->getElapsedTime());
		}
		else if (KEYMANAGER->isStayKeyDown(VK_DOWN))
		{
			_trans->SetPos(_trans->GetPos() + Vector2::down * _speed * TIMEMANAGER->getElapsedTime());
		}
		_physics->SetBodyPosition();
		_sprite->SetPosition(_trans->GetPos() + Vector2(0, 2));
	}
}

void Player::Render()
{
	Object::Render();

	wchar_t buffer[128];
	swprintf(buffer, 128, L"%1.f / %1.f", _hp->GetCurrentHP(), _hp->GetMaxHP());
	GRAPHICMANAGER->Text(_trans->GetPos() + Vector2(-(_trans->GetScale().x + 10.0f), 32.f), buffer, 20, 90, 30, ColorF::LawnGreen, TextPivot::RIGHT_TOP);

	if (_hp->IsDead()) GRAPHICMANAGER->Text(_trans->GetPos() + Vector2(-(_trans->GetScale().x - (_trans->GetScale().x * 0.5f) + 4.0f), -62.f), L"Dead", 20, 100, 30, ColorF::Red);
}

void Player::ChangeState(PlayerState* state)
{
	_state->Exit();
	_state = state;
	_state->Enter();
}
