#include "stdafx.h"
#include "Bullet.h"

void Bullet::Init(string imgKey, string tag, string name)
{
	_tag = tag;
	_name = name;

	_sprite->Init();
	_sprite->SetImgName(imgKey);
	_trans->scale = Vector2(_sprite->GetGraphic()->GetFrameWidth(),
		_sprite->GetGraphic()->GetFrameHeight());

	_physics = AddComponent<PhysicsBody>();
	_physics->Init(BodyType::DYNAMIC, 1.0f);

	_physics->GetBody()->SetFixedRotation(true);
	_physics->GetBody()->SetActive(false);
	_isActive = false;

	

}

void Bullet::Update()
{
	Object::Update();
	Move();
	if (_name != "������...")
		_trans->pos = _physics->GetBodyPosition();
}

void Bullet::Fire(Vector2 pos, float angle, float speed)
{
	_speed = speed;
	_trans->pos = pos;
	_physics->SetBodyPosition();
	_trans->SetRotateToRadian(angle);
	_physics->SetBodyActive(true);
	_isActive = true;
}

void Bullet::Move()
{
	if (_name != "������...")
		_physics->GetBody()->SetLinearVelocity(b2Vec2(cosf(_trans->GetRotateRadian()) * _speed,
			-sinf(_trans->GetRotateRadian()) * _speed) * TIMEMANAGER->getElapsedTime());
	else
	{
		_trans->SetPos(_trans->GetPos() + Vector2(cosf(_trans->GetRotateRadian()) * _speed, 0));
		_physics->SetBodyPosition();
	}

	//SetIsActive()
	/*if (_trans->pos.x > CAMERA->GetPosition().x + WINSIZEX || _trans->pos.x < CAMERA->GetPosition().x ||
		_trans->pos.y > CAMERA->GetPosition().y + WINSIZEY || _trans->pos.y < CAMERA->GetPosition().y)
	{
		_isActive = false;
	}*/
}
