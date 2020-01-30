#include "stdafx.h"
#include "Particle.h"

Particle::Particle()
{
	_tag = "Particle";
	_sprite = AddComponent<Sprite>();
}

void Particle::Init(float angle, float speed, Vector2 pos, Vector2 scale, string imgKey, bool isFrame, float FPS)
{
	Object::Init();
	//_physics = AddComponent<PhysicsBody>();
	_angle = angle;
	_speed = speed;
	_trans->SetPos(pos);
	_trans->SetScale(scale);
	_alpha = 1.f;
	_sprite->SetAlpha(_alpha);
	//_physics->Init(BodyType::DYNAMIC, 0, 0, 0.5, true, true);
	if (imgKey != "None")
	{
		if (isFrame)
		{
			_sprite->Init(true, true);
			_sprite->SetFPS(FPS);
		}
		else
		{
			_sprite->Init();
		}
		_sprite->SetImgName(imgKey);
	}

	_sprite->SetFillRect(true);
	_sprite->SetRectColor(ColorF(ColorF::AntiqueWhite,_alpha));
	_sprite->SetPosition(_trans->GetPos());
	_rotate = 0;
}

void Particle::Update()
{
	if (!_isActive) return;

	Object::Update();
	Setdepth();

	_alpha -= 0.4*TIMEMANAGER->getElapsedTime();

	if (_alpha <= 0.f) _isActive = false;

	move();

	_rotate += 0.9 * TIMEMANAGER->getElapsedTime();
	_trans->SetRotateToRadian(_rotate);
}

void Particle::Render()
{
	if (!_isActive) return;
	Object::Render();
}

void Particle::Setdepth()
{
	//_trans->bottomPos = Vector2(_trans->bottomPos.x, 99999);
}

void Particle::move()
{
	
	_trans->SetPos(_trans->GetPos() + Vector2(cosf(_angle), -sinf(_angle) * _speed * TIMEMANAGER->getElapsedTime()));
	
	//if (_active)
	//{
	//	Fire();
	//	_active = false;
	//}
	_sprite->SetPosition(_trans->GetPos());

	_sprite->SetAlpha(_alpha);
	
}

void Particle::Fire()
{
	_physics->ApplyForce(b2Vec2(cosf(_angle), -sinf(_angle)) * _speed);
}
