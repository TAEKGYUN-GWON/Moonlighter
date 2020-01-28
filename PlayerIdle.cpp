#include "stdafx.h"
#include "PlayerIdle.h"
#include "PlayerMove.h"

void PlayerIdle::Enter()
{
	_obj->GetSprite()->SetMaxFrameX(10);
	_obj->GetSprite()->SetFrameX(0);
	_obj->GetSprite()->SetFrameY(11);
	_obj->GetSprite()->SetFPS(1.0f);
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
}

void PlayerIdle::Exit()
{
	//_obj->GetSprite()->SetFrameX(0);
}
