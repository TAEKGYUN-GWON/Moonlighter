#include "stdafx.h"
#include "PlayerRoll.h"
#include "PlayerIdle.h"

void PlayerRoll::Enter()
{
	_state = "Roll";

	_obj->GetSprite()->SetMaxFrameX(8);
	_obj->GetSprite()->SetFrameX(0);
	_obj->GetSprite()->SetFPS(2.5f);
	_obj->GetSprite()->SetPosition(_obj->GetTrans()->GetPos() + Vector2(0, -14));
	_obj->GetSprite()->SetFillRect(true);
	_obj->GetPhysics()->SetSensor(true);

	_rollSpeed = 350.0f;
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
			_obj->GetPhysics()->ApplyForce(b2Vec2(cosf(PI * RadToDeg), -sinf((PI / 2) * RadToDeg)) * _rollSpeed * TIMEMANAGER->getElapsedTime());
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

	_obj->GetSprite()->SetPosition(_obj->GetTrans()->GetPos() + Vector2(0, -14));

	if (_obj->GetSprite()->GetCurrentFrameX() >= _obj->GetSprite()->GetMaxFrameX())
	{
		_obj->GetPhysics()->SetSensor(false);
		_obj->ChangeState(new PlayerIdle(_obj));
	}
}

void PlayerRoll::Exit()
{
}
