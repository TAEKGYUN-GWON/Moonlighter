#include "stdafx.h"
#include "BowAttack.h"
#include "PlayerIdle.h"

void BowAttack::Enter()
{
	_state = "Attack";

	_obj->GetSprite()->SetFrameX(0);
	_obj->GetSprite()->SetFPS(2.8f);
	_obj->GetSprite()->SetIsLoop(false);
	
	switch (_obj->GetDirection())
	{
	case Dir::Left: case Dir::Left_Up: case Dir::Left_Down: _obj->GetSprite()->SetFrameY(3); break;
	case Dir::Right: case Dir::Right_Up: case Dir::Right_Down: _obj->GetSprite()->SetFrameY(2); break;
	case Dir::Up: _obj->GetSprite()->SetFrameY(0); break;
	case Dir::Down: _obj->GetSprite()->SetFrameY(1); break;
	}

	_obj->GetSprite()->SetImgName("will_bow");
	_obj->GetSprite()->SetMaxFrameX(9);

	_obj->GetSprite()->SetPosition(_obj->GetTrans()->GetPos() + Vector2(0, -14));
	
	//_isAtk = false;
	_timer = _count = 0;
	_delay = 0.29f;
}

void BowAttack::Update()
{
	if (_obj->GetSprite()->GetCurrentFrameX() == _obj->GetSprite()->GetMaxFrameX())
	{
		_timer += TIMEMANAGER->getElapsedTime();
	
		if (_timer >= _delay)
		{
			_timer -= _delay;
			_obj->ChangeState(new PlayerIdle(_obj));
		}
	}
}

void BowAttack::Exit()
{
}
