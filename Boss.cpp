#include "stdafx.h"
#include "Boss.h"
#include "Ability.h"
#include "SlimeEnemy.h"

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
	GRAPHICMANAGER->AddFrameImage("deadBoss1", L"resource/img/Enemy/deadBoss1.png", 41, 1);
	GRAPHICMANAGER->AddFrameImage("deadBoss2", L"resource/img/Enemy/deadBoss21.png", 41, 1);
	//GRAPHICMANAGER->AddFrameImage("lll", L"resource/img/Enemy/lll.png", 10, 5);
	GRAPHICMANAGER->AddFrameImage("FistShoot", L"resource/img/Enemy/FistShoot.png", 41, 3);
	GRAPHICMANAGER->AddFrameImage("Hand_Shoot_First", L"resource/img/Enemy/Hand_Shoot_First.png", 20, 1);
	GRAPHICMANAGER->AddFrameImage("Hand_Shoot_Last", L"resource/img/Enemy/Hand_Shoot_Last.png", 11, 1);

	_tag = "boss";
	_name = "Boss";

	_ability = new Ability(100, 100, 10); //더 크게 줘야 하나?

	maxFrameX = 0;
	frameY = 0;
	_sprite = AddComponent<Sprite>();
	_sprite->Init(true, true);
	_sprite->SetImgName("Open_Boss");
	_sprite->SetRectColor(ColorF::Cornsilk);
	_trans->SetScale(Vector2(_sprite->GetGraphic()->GetFrameWidth(),
		_sprite->GetGraphic()->GetFrameHeight()));
	_trans->SetScale(Vector2(100, 100)); //보스 범위
	_trans->SetPos(pos);
	_sprite->SetPosition(_trans->GetPos());
	_physics = AddComponent<PhysicsBody>();
	_physics->Init(BodyType::DYNAMIC, 1.0f);
	////가상세계의 렉트 뒤틀리는거 고정
	_physics->GetBody()->SetFixedRotation(true);

#pragma region 무덤

	Object* rock = Object::CreateObject<Object>(this);
	rock->GetTrans()->SetScale(100, 109);
	rock->GetTrans()->SetPos(759, 533);
	auto s = rock->AddComponent<Sprite>();
	s->Init();
	s->SetImgName("");
	auto p = rock->AddComponent<PhysicsBody>();
	p->Init(BodyType::STATIC, 1, 1);
	p->SetBodyPosition();
	_rocks.push_back(rock);

	rock = Object::CreateObject<Object>(this);
	rock->GetTrans()->SetScale(100, 109);
	rock->GetTrans()->SetPos(896, 642);
	s = rock->AddComponent<Sprite>();
	s->Init();
	s->SetImgName("");
	p = rock->AddComponent<PhysicsBody>();
	p->Init(BodyType::STATIC, 1, 1);
	p->SetBodyPosition();
	_rocks.push_back(rock);

	rock = Object::CreateObject<Object>(this);
	rock->GetTrans()->SetScale(100, 109);
	rock->GetTrans()->SetPos(1050, 742);
	s = rock->AddComponent<Sprite>();
	s->Init();
	s->SetImgName("");
	p = rock->AddComponent<PhysicsBody>();
	p->Init(BodyType::STATIC, 1, 1);
	p->SetBodyPosition();
	_rocks.push_back(rock);

	rock = Object::CreateObject<Object>(this);
	rock->GetTrans()->SetScale(100, 109);
	rock->GetTrans()->SetPos(1195, 642);
	s = rock->AddComponent<Sprite>();
	s->Init();
	s->SetImgName("");
	p = rock->AddComponent<PhysicsBody>();
	p->Init(BodyType::STATIC, 1, 1);
	p->SetBodyPosition();
	_rocks.push_back(rock);

	rock = Object::CreateObject<Object>(this);
	rock->GetTrans()->SetScale(100, 109);
	rock->GetTrans()->SetPos(1367, 547);
	s = rock->AddComponent<Sprite>();
	s->Init();
	s->SetImgName("");
	p = rock->AddComponent<PhysicsBody>();
	p->Init(BodyType::STATIC, 1, 1);
	p->SetBodyPosition();
	_rocks.push_back(rock);

	rock = Object::CreateObject<Object>(this);
	rock->GetTrans()->SetScale(100, 109);
	rock->GetTrans()->SetPos(583, 601);
	s = rock->AddComponent<Sprite>();
	s->Init();
	s->SetImgName("");
	p = rock->AddComponent<PhysicsBody>();
	p->Init(BodyType::STATIC, 1, 1);
	p->SetBodyPosition();
	_rocks.push_back(rock);

	rock = Object::CreateObject<Object>(this);
	rock->GetTrans()->SetScale(100, 109);
	rock->GetTrans()->SetPos(791, 773);
	s = rock->AddComponent<Sprite>();
	s->Init();
	s->SetImgName("");
	p = rock->AddComponent<PhysicsBody>();
	p->Init(BodyType::STATIC, 1, 1);
	p->SetBodyPosition();
	_rocks.push_back(rock);

	rock = Object::CreateObject<Object>(this);
	rock->GetTrans()->SetScale(100, 109);
	rock->GetTrans()->SetPos(1050, 917);
	s = rock->AddComponent<Sprite>();
	s->Init();
	s->SetImgName("");
	p = rock->AddComponent<PhysicsBody>();
	p->Init(BodyType::STATIC, 1, 1);
	p->SetBodyPosition();
	_rocks.push_back(rock);

	rock = Object::CreateObject<Object>(this);
	rock->GetTrans()->SetScale(100, 109);
	rock->GetTrans()->SetPos(1317, 751);
	s = rock->AddComponent<Sprite>();
	s->Init();
	s->SetImgName("");
	p = rock->AddComponent<PhysicsBody>();
	p->Init(BodyType::STATIC, 1, 1);
	p->SetBodyPosition();
	_rocks.push_back(rock);

	rock = Object::CreateObject<Object>(this);
	rock->GetTrans()->SetScale(100, 109);
	rock->GetTrans()->SetPos(1539, 633);
	s = rock->AddComponent<Sprite>();
	s->Init();
	s->SetImgName("");
	p = rock->AddComponent<PhysicsBody>();
	p->Init(BodyType::STATIC, 1, 1);
	p->SetBodyPosition();
	_rocks.push_back(rock);

	rock = Object::CreateObject<Object>(this);
	rock->GetTrans()->SetScale(100, 109);
	rock->GetTrans()->SetPos(411, 687);
	s = rock->AddComponent<Sprite>();
	s->Init();
	s->SetImgName("");
	p = rock->AddComponent<PhysicsBody>();
	p->Init(BodyType::STATIC, 1, 1);
	p->SetBodyPosition();
	_rocks.push_back(rock);

	rock = Object::CreateObject<Object>(this);
	rock->GetTrans()->SetScale(100, 109);
	rock->GetTrans()->SetPos(651, 917);
	s = rock->AddComponent<Sprite>();
	s->Init();
	s->SetImgName("");
	p = rock->AddComponent<PhysicsBody>();
	p->Init(BodyType::STATIC, 1, 1);
	p->SetBodyPosition();
	_rocks.push_back(rock);

	rock = Object::CreateObject<Object>(this);
	rock->GetTrans()->SetScale(100, 109);
	rock->GetTrans()->SetPos(1050, 1076);
	s = rock->AddComponent<Sprite>();
	s->Init();
	s->SetImgName("");
	p = rock->AddComponent<PhysicsBody>();
	p->Init(BodyType::STATIC, 1, 1);
	p->SetBodyPosition();
	_rocks.push_back(rock);

	rock = Object::CreateObject<Object>(this);
	rock->GetTrans()->SetScale(100, 109);
	rock->GetTrans()->SetPos(1449, 896);
	s = rock->AddComponent<Sprite>();
	s->Init();
	s->SetImgName("");
	p = rock->AddComponent<PhysicsBody>();
	p->Init(BodyType::STATIC, 1, 1);
	p->SetBodyPosition();
	_rocks.push_back(rock);

	rock = Object::CreateObject<Object>(this);
	rock->GetTrans()->SetScale(100, 109);
	rock->GetTrans()->SetPos(1723, 719);
	s = rock->AddComponent<Sprite>();
	s->Init();
	s->SetImgName("");
	p = rock->AddComponent<PhysicsBody>();
	p->Init(BodyType::STATIC, 1, 1);
	p->SetBodyPosition();
	_rocks.push_back(rock);

	rock = Object::CreateObject<Object>(this);
	rock->GetTrans()->SetScale(100, 109);
	rock->GetTrans()->SetPos(511, 1037);
	s = rock->AddComponent<Sprite>();
	s->Init();
	s->SetImgName("");
	p = rock->AddComponent<PhysicsBody>();
	p->Init(BodyType::STATIC, 1, 1);
	p->SetBodyPosition();
	_rocks.push_back(rock);

	rock = Object::CreateObject<Object>(this);
	rock->GetTrans()->SetScale(100, 109);
	rock->GetTrans()->SetPos(1050, 1251);
	s = rock->AddComponent<Sprite>();
	s->Init();
	s->SetImgName("");
	p = rock->AddComponent<PhysicsBody>();
	p->Init(BodyType::STATIC, 1, 1);
	p->SetBodyPosition();
	_rocks.push_back(rock);

	rock = Object::CreateObject<Object>(this);
	rock->GetTrans()->SetScale(100, 109);
	rock->GetTrans()->SetPos(1589, 1026);
	s = rock->AddComponent<Sprite>();
	s->Init();
	s->SetImgName("");
	p = rock->AddComponent<PhysicsBody>();
	p->Init(BodyType::STATIC, 1, 1);
	p->SetBodyPosition();
	_rocks.push_back(rock);








#pragma endregion

	for (Object* r : _rocks)
	{
		r->GetComponent<PhysicsBody>()->SetBodyActive(false);
		r->SetIsActive(false);
	}

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
	for (Object* r : _rocks)
		SCENEMANAGER->GetNowScene()->GetWorld()->DestroyBody(r->GetComponent<PhysicsBody>()->GetBody());

	Object::Release();

}

void Boss::Attack()
{
	switch (_phase)
	{
	case PHASE::ROCK:
		break;
	case PHASE::HAND:
		break;
	case PHASE::SLIME:
		break;
	default:
		break;
	}
}

void Boss::SetState(BossState* state)
{
	_Bstate->Exit();
	delete _Bstate;
	_Bstate = state;
	_Bstate->Enter();
}

