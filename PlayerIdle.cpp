#include "stdafx.h"
#include "PlayerIdle.h"
#include "PlayerMove.h"
#include "PlayerRoll.h"
#include "PlayerAttack.h"

void PlayerIdle::Enter()
{
	_obj->GetSprite()->SetImgName("will_dungeon");
	_obj->GetSprite()->SetMaxFrameX(10);
	_obj->GetSprite()->SetFrameX(0);
	
	switch (_obj->GetDirection())
	{
	case Dir::Left : case Dir::Left_Up : case Dir::Left_Down :
		_obj->GetSprite()->SetFrameY(9);
		break;
	case Dir::Right : case Dir::Right_Up : case Dir::Right_Down:
		_obj->GetSprite()->SetFrameY(8);
		break;
	case Dir::Up : _obj->GetSprite()->SetFrameY(10); break;
	case Dir::Down: _obj->GetSprite()->SetFrameY(11); break;
	}
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

	if (KEYMANAGER->isOnceKeyDown('J'))
	{
		_obj->ChangeState(new PlayerAttack(_obj));
	}
}

void PlayerIdle::Exit()
{
}
