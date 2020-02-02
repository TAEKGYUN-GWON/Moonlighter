#include "stdafx.h"
#include "PlayerRoll.h"
#include "PlayerIdle.h"

void PlayerRoll::Enter()
{
	_state = "Roll";

	_obj->GetSprite()->SetMaxFrameX(8);
	_obj->GetSprite()->SetFrameX(0);
	_obj->GetSprite()->SetFPS(2.5f);
	_obj->GetPhysics()->SetSensor(true);

	_rollSpeed = 200.0f;
	//_rollSpeed = 10.0f;
	_friction = -0.4f;
}

void PlayerRoll::Update()
{
	if (_obj->GetDirection() == Dir::Left)
	{
		if (_obj->GetSprite()->GetCurrentFrameY() != 5)
		{
			_obj->GetSprite()->SetFrameY(5);
			_obj->GetPhysics()->ApplyForce(Vector2::b2Left * _rollSpeed * TIMEMANAGER->getElapsedTime());
		}
	}
	else if (_obj->GetDirection() == Dir::Left_Up)
	{
		if (_obj->GetSprite()->GetCurrentFrameY() != 5)
		{
			_obj->GetSprite()->SetFrameY(5);
			_obj->GetPhysics()->ApplyForce(b2Vec2(cosf(2.53f * RadToDeg), -sinf(2.53f * RadToDeg)) * _rollSpeed * TIMEMANAGER->getElapsedTime());
		}
	}
	else if (_obj->GetDirection() == Dir::Left_Down)
	{
		if (_obj->GetSprite()->GetCurrentFrameY() != 5)
		{
			_obj->GetSprite()->SetFrameY(5);
			_obj->GetPhysics()->ApplyForce(b2Vec2(cosf(PI * RadToDeg), -sinf((5 * PI / 4) * Rad2Deg)) * _rollSpeed * TIMEMANAGER->getElapsedTime());
		}
	}
	else if (_obj->GetDirection() == Dir::Right)
	{
		if (_obj->GetSprite()->GetCurrentFrameY() != 4)
		{
			_obj->GetSprite()->SetFrameY(4);
			_obj->GetPhysics()->ApplyForce(Vector2::b2Right * _rollSpeed * TIMEMANAGER->getElapsedTime());
		}
	}
	else if (_obj->GetDirection() == Dir::Right_Up)
	{
		if (_obj->GetSprite()->GetCurrentFrameY() != 4)
		{
			_obj->GetSprite()->SetFrameY(4);
			_obj->GetPhysics()->ApplyForce(b2Vec2(cosf((PI / 4) * Rad2Deg), -sinf((PI / 4) * Rad2Deg)) * _rollSpeed * TIMEMANAGER->getElapsedTime());
		}
	}
	else if (_obj->GetDirection() == Dir::Right_Down)
	{
		if (_obj->GetSprite()->GetCurrentFrameY() != 4)
		{
			_obj->GetSprite()->SetFrameY(4);
			_obj->GetPhysics()->ApplyForce(b2Vec2(cosf((PI / 4) * Rad2Deg), sinf((PI / 4) * Rad2Deg)) * _rollSpeed * TIMEMANAGER->getElapsedTime());
		}
	}
	else if (_obj->GetDirection() == Dir::Up)
	{
		if (_obj->GetSprite()->GetCurrentFrameY() != 6)
		{
			_obj->GetSprite()->SetFrameY(6);
			_obj->GetPhysics()->ApplyForce(Vector2::b2Up * _rollSpeed * TIMEMANAGER->getElapsedTime());
		}
	}
	else if (_obj->GetDirection() == Dir::Down)
	{
		if (_obj->GetSprite()->GetCurrentFrameY() != 7)
		{
			_obj->GetSprite()->SetFrameY(7);
			_obj->GetPhysics()->ApplyForce(Vector2::b2Down * _rollSpeed * TIMEMANAGER->getElapsedTime());
		}
	}

	/*if (_obj->GetDirection() == Dir::Left)
	{
		_obj->GetSprite()->SetFrameY(5);
		_obj->GetTrans()->SetPos(_obj->GetTrans()->GetPos() + Vector2(cosf(PI), -sinf(0.0f)) * _rollSpeed);
	}
	else if (_obj->GetDirection() == Dir::Left_Up)
	{
		_obj->GetSprite()->SetFrameY(5);
		_obj->GetTrans()->SetPos(_obj->GetTrans()->GetPos() + Vector2(cosf(2.53f), -sinf(2.53f)) * _rollSpeed);
	}
	else if (_obj->GetDirection() == Dir::Left_Down)
	{
			_obj->GetSprite()->SetFrameY(5);
			_obj->GetPhysics()->ApplyForce(b2Vec2(cosf(PI * RadToDeg), -sinf((5 * PI / 4) * Rad2Deg)) * _rollSpeed * TIMEMANAGER->getElapsedTime());
	}
	else if (_obj->GetDirection() == Dir::Right)
	{
		_obj->GetSprite()->SetFrameY(4);
		_obj->GetTrans()->SetPos(_obj->GetTrans()->GetPos() + Vector2(cosf(PI2), -sinf(0.0f)) * _rollSpeed);
	}

	_rollSpeed += _friction;
	_obj->GetPhysics()->SetBodyPosition();

	if (_rollSpeed <= 0)
	{
		_obj->GetPhysics()->SetSensor(false);
		_obj->ChangeState(new PlayerIdle(_obj));
	}*/

	if (_obj->GetSprite()->GetCurrentFrameX() >= _obj->GetSprite()->GetMaxFrameX())
	{
		_obj->GetPhysics()->GetBody()->SetLinearVelocity(Vector2::b2Zero);
		_obj->GetPhysics()->SetSensor(false);
		_obj->ChangeState(new PlayerIdle(_obj));
	}
}

void PlayerRoll::Exit()
{
}
