#include "stdafx.h"
#include "PlayerRoll.h"
#include "PlayerIdle.h"

void PlayerRoll::Enter()
{
	_obj->GetSprite()->SetMaxFrameX(8);
	_obj->GetSprite()->SetFrameX(0);
	_obj->GetSprite()->SetFPS(2.0f);
}

void PlayerRoll::Update()
{
	if (_obj->GetDirection() == Dir::Left)
	{
		if (_obj->GetSprite()->GetCurrentFrameY() != 5)
		{
			_obj->GetSprite()->SetFrameY(5);
			_obj->GetPhysics()->ApplyForce(Vector2::b2Left * 30.0f);
		}
	}
	else if (_obj->GetDirection() == Dir::Right)
	{
		if (_obj->GetSprite()->GetCurrentFrameY() != 4)
		{
			_obj->GetSprite()->SetFrameY(4);
			_obj->GetPhysics()->ApplyForce(Vector2::b2Right * 30.0f);
		}
	}
	_obj->GetSprite()->SetPosition(_obj->GetTrans()->GetPos() + Vector2(0, 2));

	if (_obj->GetSprite()->GetCurrentFrameX() >= _obj->GetSprite()->GetMaxFrameX())
	{
		_obj->ChangeState(new PlayerIdle(_obj));
	}
}

void PlayerRoll::Exit()
{
}
