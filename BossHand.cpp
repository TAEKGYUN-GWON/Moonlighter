#include "stdafx.h"
#include "BossHand.h"
#include "BossAttack.h"
#include "BossIdle.h"

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

	_sprite = AddComponent<Sprite>();
	_sprite->Init(true, true);
	_sprite->SetImgName("Hand");
	_sprite->SetPosition(_trans->GetPos());
	_trans->SetScale(Vector2(_sprite->GetGraphic()->GetFrameWidth(),
		_sprite->GetGraphic()->GetFrameHeight()));

	_physics = AddComponent<PhysicsBody>();
	_physics->Init(BodyType::DYNAMIC, 1.0f);
	_physics->GetBody()->SetFixedRotation(true);

	_count = timer = 0;
	//changeImg = false;

	//_Bstate = new BossAttack(this); //idle��? atk��?
	//_Bstate->Enter();


}

void BossHand::Update()
{
	Object::Update();

	//_sprite->SetPosition()
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
	if (_count == 0)
	{
		Hatk = HANDATK::OFF;
		timer = 0;
	}
	//�� ����..���� ����? 
	timer += TIMEMANAGER->getElapsedTime();
	BossHand* h = (BossHand*)&h;
	Player* p = (Player*)&p;

	if (_name == "BossHand") // ���� ������...? �ڵ� ȣ���ϸ�? 
	{
		switch (Hatk)
		{
		case HANDATK::ON:

			Vector2::GetAngle(h->GetTrans()->GetPos(), p->GetTrans()->GetPos());
			
			break;
		case HANDATK::OFF:
		

			break;
		}
		timer = 0;
		_count++;

	}
	//������ ����? �װ͵� �־�� ��..
}

