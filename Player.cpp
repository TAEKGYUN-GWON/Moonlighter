#include "stdafx.h"
#include "Player.h"
#include "Inventory.h"
#include "PlayerState.h"
#include "PlayerIdle.h"
#include "ETCS.h"

Player::Player()
{
}

Player::~Player()
{
}

void Player::Init()
{
	Object::Init();

	GRAPHICMANAGER->AddFrameImage("will_dungeon", L"resource/img/Player/will_dungeon.png", 10, 13);
	GRAPHICMANAGER->AddFrameImage("will_sword", L"resource/img/Player/will_sword.png", 11, 4);
	GRAPHICMANAGER->AddFrameImage("will_bow", L"resource/img/Player/will_bow.png", 9, 4);
	
	GRAPHICMANAGER->AddFrameImage("arrow_up", L"resource/img/Player/arrow_up.png", 1, 1);
	GRAPHICMANAGER->AddFrameImage("arrow_right", L"resource/img/Player/arrow_right.png", 1, 1);
	GRAPHICMANAGER->AddFrameImage("arrow_down", L"resource/img/Player/arrow_down.png", 1, 1);
	GRAPHICMANAGER->AddFrameImage("arrow_left", L"resource/img/Player/arrow_left.png", 1, 1);

	_tag = "Player";
	_name = "Will";

	_trans->SetPos(WINSIZEX / 2, WINSIZEY / 2);
	_trans->SetScale(Vector2(36, 25));

	_sprite = AddComponent<Sprite>();
	_sprite->Init(true, true);
	_sprite->SetImgName("will_dungeon");
	_sprite->SetSize(Vector2(GRAPHICMANAGER->FindImage("will_dungeon")->GetFrameWidth(), GRAPHICMANAGER->FindImage("will_dungeon")->GetFrameHeight()));
	_sprite->SetPosition(_trans->GetPos() + Vector2(0, -14));

	_physics = AddComponent<PhysicsBody>();
	_physics->Init(BodyType::DYNAMIC, 1.0f,0.3f);
	_physics->GetBody()->SetFixedRotation(true);

	_ability = new Ability(100, 100, 10);

	_speed = 300.0f;

	_dir = Dir::Down;
	_atkType = AttackType::Sword;

	_inven = new Inventory;
	_inven->Init();

	Item* item = Item::CreateItem<Golem_Core>(Vector2(100, 100));
	_inven->Insert(item);

	_state = new PlayerIdle(this);
	_state->Enter();

	_pool = new BulletObjPool;
	_pool->Init(20, "arrow_down", "Arrow", "Arrow", this, 3);
}

void Player::Update()
{
	_inven->Update();
	if (_inven->GetActive()) return;

	if (KEYMANAGER->isStayKeyDown('P')) _ability->DamageHP(10);
	else if (KEYMANAGER->isStayKeyDown('O')) _ability->HealHP(10);

	if (_state->GetState() != "Attack")
	{
		if (KEYMANAGER->isOnceKeyDown('Z')) _atkType = (AttackType)(((int)_atkType + 1) % 2);
	}

	Object:: Update();

	_state->Update();

	// 무언가와 충돌했을 때
	for (int i = 0; i < _pool->GetActivePoolSize(); i++)
	{
		if (_pool->GetActivePool()[i]->GetCollision())
		{
			_pool->GetActivePool()[i]->SetCollision(false);
			_pool->InssertPool(i);
			break;
		}
	}

	// 그 무엇과도 충돌하지 않았을 때
	for (int i = 0; i < _pool->GetActivePoolSize(); i++)
	{
		if (!_pool->GetActivePool()[i]->GetIsActive())
		{
			_pool->GetActivePool()[i]->GetComponent<PhysicsBody>()->GetBody()->SetActive(false);
			_pool->InssertPool(i);
		}
	}
}

void Player::Render()
{
	Object::Render();

	wchar_t buffer[128];
	swprintf(buffer, 128, L"%1.f / %1.f", _ability->GetCurrentHP(), _ability->GetMaxHP());
	GRAPHICMANAGER->Text(_trans->GetPos() + Vector2(-(_trans->GetScale().x + 10.0f), 32.f), buffer, 20, 90, 30, ColorF::LawnGreen, TextPivot::RIGHT_TOP);

	swprintf(buffer, 128, L"player arrow count : %d", _pool->GetActivePoolSize());
	GRAPHICMANAGER->Text(Vector2(100, 100), buffer, 20, 400, 30, ColorF::BlanchedAlmond);

	if (_ability->IsDead()) GRAPHICMANAGER->Text(_trans->GetPos() + Vector2(-(_trans->GetScale().x - (_trans->GetScale().x * 0.5f) + 4.0f), -62.f), L"Dead", 20, 100, 30, ColorF::Red);

	int a = (int)_dir;
	Vector2 test((_trans->GetPos() + Vector2(0, -10)) + Vector2(cosf(a * 45.0f * Deg2Rad), -sinf(a * 45.0f * Deg2Rad)) * 50);
	GRAPHICMANAGER->DrawLine(_trans->GetPos() + Vector2(0, -10), test, ColorF::AntiqueWhite);

	char str[128];
	if(_atkType == AttackType::Sword) sprintf_s(str, "Attack Type : Sword\nState Type : %s", _state->GetState().c_str());
	else if (_atkType == AttackType::Bow) sprintf_s(str, "Attack Type : Bow\nState Type : %s", _state->GetState().c_str());

	GRAPHICMANAGER->DrawTextD2D(Vector2(WINSIZEX - 230, 2), str, 20, 200, 70, ColorF::AntiqueWhite, TextPivot::RIGHT_BOTTOM);
}

void Player::ChangeState(PlayerState* state)
{
	_state->Exit();
	_state = state;
	_state->Enter();
}
