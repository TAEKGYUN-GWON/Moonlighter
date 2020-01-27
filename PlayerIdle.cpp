#include "stdafx.h"
#include "PlayerIdle.h"

void PlayerIdle::Enter()
{
	_obj->GetSprite()->SetMaxFrameX(7);
	_obj->GetSprite()->SetFrameX(1);
}

void PlayerIdle::Update()
{
}

void PlayerIdle::Exit()
{
}
