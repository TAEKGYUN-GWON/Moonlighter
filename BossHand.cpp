#include "stdafx.h"
#include "BossHand.h"
#include "BossAttack.h"
#include "BossIdle.h"
#include "Player.h"

BossHand::BossHand()
{
}

BossHand::~BossHand()
{
}

void BossHand::Init()
{
	Object::Init();

	_tag = "boss";
	_name = "BossHand";

	Boss* _boss = new Boss;
	Player* _player = new Player;
	_sprite = AddComponent<Sprite>();
	_sprite->Init(true, true);
	_sprite->SetImgName("Hand");
	_sprite->SetPosition(_trans->GetPos());
	_trans->SetScale(Vector2(_sprite->GetGraphic()->GetFrameWidth(),
		_sprite->GetGraphic()->GetFrameHeight()));
	_trans->SetPos(_player->GetTrans()->GetPos());
	_physics = AddComponent<PhysicsBody>();
	_physics->Init(BodyType::DYNAMIC, 1.0f);
	_physics->GetBody()->SetFixedRotation(true);

	_player = (Player*)SCENEMANAGER->GetNowScene()->GetChildFromName("Will");
	//_obj = Object::CreateObject<Player>();
	//_player->GetTrans()->SetPos(_player->GetTrans()->GetPos());
	_count = timer = 0;
	//changeImg = false;

	//_Bstate = new BossAttack(this); //idle로? atk로?
	//_Bstate->Enter();


}

void BossHand::Update()
{
	Object::Update();

	Attack();
}

void BossHand::Render()
{
	Object::Render();
}

void BossHand::Release()
{
	SCENEMANAGER->GetNowScene()->GetWorld()->DestroyBody(_physics->GetBody());
	Object::Release();

}

void BossHand::Attack()
{
	if (timer == 0)
	{
		_state = HANDSTATE::SHADOW;
		//timer = 0;
	}
	//온 오프..같은 느낌? 
	timer += TIMEMANAGER->getElapsedTime();
	//BossHand* h = (BossHand*)&h;
	//Player* p = (Player*)&p;

	if (timer >= 5.f) // 조건 뭐주지...? 핸드 호출하면? 
	{
		switch (_state)
		{
		case HANDSTATE::SHADOW:
			//_sprite->SetImgName("Shadow"); 이게 왜 터져???
			//_trans->SetPos(500, 100);
			Vector2::GetAngle(_trans->GetPos(), _target);
			//_boss->GetPlayer()->GetTrans()->GetPos()
			//_player->GetTrans()->GetPos()
			break;
		case HANDSTATE::HAND:
			if (timer == 6.f) _sprite->SetImgName("Hand");
			_physics->SetBodyActive(true);
			break;
		case HANDSTATE::END:
			timer == 8.f;
			_sprite->SetImgName("Shadow");
			_physics->SetBodyActive(false);
			break;
		}
		timer = 0;
		_count++;
	}
	//나가는 조건? 그것두 있어야 함..
}

