#include "stdafx.h"
#include "PlayerIdle.h"
#include "PlayerMove.h"
#include "PlayerRoll.h"

void PlayerIdle::Enter()
{
	_obj->GetSprite()->SetMaxFrameX(10);
	_obj->GetSprite()->SetFrameX(0);
	
	if (_obj->GetDirection() == Dir::Left) _obj->GetSprite()->SetFrameY(9);
	else if (_obj->GetDirection() == Dir::Up) _obj->GetSprite()->SetFrameY(10);
	else if (_obj->GetDirection() == Dir::Right) _obj->GetSprite()->SetFrameY(8);
	else if (_obj->GetDirection() == Dir::Down) _obj->GetSprite()->SetFrameY(11);
	_obj->GetSprite()->SetFPS(1.0f);
	_obj->GetPhysics()->GetBody()->SetLinearVelocity(Vector2::b2Zero);
}

void PlayerIdle::Update()
{
	if (KEYMANAGER->isStayKeyDown(VK_LEFT))
	{
		_obj->ChangeState(new PlayerMove(_obj));
	}
	if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
	{
		_obj->ChangeState(new PlayerMove(_obj));
	}
	if (KEYMANAGER->isStayKeyDown(VK_UP))
	{
		_obj->ChangeState(new PlayerMove(_obj));
	}
	if (KEYMANAGER->isStayKeyDown(VK_DOWN))
	{
		_obj->ChangeState(new PlayerMove(_obj));
	}

	if (KEYMANAGER->isOnceKeyDown(VK_SPACE))
	{
		_obj->ChangeState(new PlayerRoll(_obj));
	}
}

void PlayerIdle::Exit()
{
}
