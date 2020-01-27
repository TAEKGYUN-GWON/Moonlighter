#include "stdafx.h"
#include "SlimeEnemy.h"
#include "Hp.h"


SlimeEnemy::SlimeEnemy()
{

}

SlimeEnemy::~SlimeEnemy()
{

}

void SlimeEnemy::Init()
{
	Enemy::Init();
	//Object::Update();
	GRAPHICMANAGER->AddFrameImage("slime", L"resource/img/Enemy", 5, 1); //슬라임 추가할것
	
	_tag = "enemy";
	_name = "Slime";
	
	_hp = new Hp(1, 1); 
	
	////이미지 크기, pos는 어떻게 하지 생성될때 방안에 랜덤으로 해야 할거 같음
	_trans->SetPos(WINSIZEX / 2, WINSIZEY / 2 - 200); //->셋포스는 나중에 사라질 예정
	//_trans->SetScale(Vector2(100, 100));	
	_trans->SetScale(Vector2(_sprite->GetGraphic()->GetFrameWidth(), 
		_sprite->GetGraphic()->GetFrameHeight()));

	_sprite = AddComponent<Sprite>();
	_sprite->Init(true, true);
	_sprite->SetRectColor(ColorF::Cornsilk);

	_physics = AddComponent<PhysicsBody>();
	_physics->Init(BodyType::DYNAMIC, 1.0f);	//플레이어한테 뚫림 왜 그러지?
	////가상세계의 렉트 뒤틀리는거 고정
	_physics->GetBody()->SetFixedRotation(true);	
	
}

void SlimeEnemy::Update()
{
	Enemy::Update();
	//if(_path.size())
}

void SlimeEnemy::Attack()
{
	//공격 하는 함수 인데 일정 범위 안에 있으면 때리는거...
	// a*로 가는거...?
	
}

