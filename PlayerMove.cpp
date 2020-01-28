#include "stdafx.h"
#include "PlayerMove.h"
#include "PlayerIdle.h"

void PlayerMove::Enter()
{
	_obj->GetSprite()->SetMaxFrameX(8);
	_obj->GetSprite()->SetFrameX(0);
	_obj->GetSprite()->SetFPS(2.0f);
}

void PlayerMove::Update()
{
	if (KEYMANAGER->isStayKeyDown(VK_LEFT))
	{
		_obj->GetSprite()->SetFrameY(3);
		_obj->GetTrans()->SetPos(_obj->GetTrans()->GetPos() + Vector2::left * _obj->GetSpeed() * TIMEMANAGER->getElapsedTime());
		_obj->GetSprite()->SetPosition(_obj->GetTrans()->GetPos() + Vector2(0, 2));
		_obj->GetPhysics()->SetBodyPosition();
	}
	else if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
	{
		_obj->GetSprite()->SetFrameY(2);
		_obj->GetTrans()->SetPos(_obj->GetTrans()->GetPos() + Vector2::right * _obj->GetSpeed() * TIMEMANAGER->getElapsedTime());
		_obj->GetSprite()->SetPosition(_obj->GetTrans()->GetPos() + Vector2(0, 2));
		_obj->GetPhysics()->SetBodyPosition();
	}
	else
	{
		_obj->ChangeState(new PlayerIdle(_obj));
	}
}

void PlayerMove::Exit()
{
}
