#include "stdafx.h"
#include "Enemy.h"
#include "Transform.h"
#include "Sprite.h"

void Enemy::Init()
{
	Object* obj = Object::CreateObject<Object>();
	auto a = obj->AddComponent<Sprite>();	//aoto �ᵵ ������?

	//���ʹ̵� �ɾ���߰���?
	//��1, ��2 ��..
	//�̹��� ũ��, pos�� ��� ���� �����ɶ� ��ȿ� ��������?
	//�ʱ� ���´� idle�̰ų� �׷���?

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
