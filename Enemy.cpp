#include "stdafx.h"
#include "Enemy.h"
#include "Transform.h"
#include "Sprite.h"

void Enemy::Init()
{
	Object* obj = Object::CreateObject<Object>();
	auto a = obj->AddComponent<Sprite>();	//aoto 써도 괜찮나?

	//에너미들 걸어줘야겠지?
	//골렘1, 골렘2 등..
	//이미지 크기, pos는 어떻게 하지 생성될때 방안에 랜덤으로?
	//초기 상태는 idle이거나 그런거?

}

void Enemy::Update()
{
}

void Enemy::Move()
{
}

void Enemy::Render()
{
}

void Enemy::Release()
{
}
