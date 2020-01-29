#include "stdafx.h"
#include "PlayerAttack.h"
#include "PlayerIdle.h"

void PlayerAttack::Enter()
{
	_state = "Attack";

	_obj->GetSprite()->SetFrameX(0);
	_obj->GetSprite()->SetFPS(2.5f);
	_obj->GetSprite()->SetIsLoop(false);

	switch (_obj->GetDirection())
	{
	case Dir::Left: case Dir::Left_Up: case Dir::Left_Down:
		_obj->GetSprite()->SetFrameY(3);
		break;
	case Dir::Right: case Dir::Right_Up: case Dir::Right_Down:
		_obj->GetSprite()->SetFrameY(2);
		break;
	case Dir::Up: _obj->GetSprite()->SetFrameY(0); break;
	case Dir::Down: _obj->GetSprite()->SetFrameY(1); break;
	}

	if (_obj->GetAttackType() == AttackType::Sword)
	{
		_obj->GetSprite()->SetImgName("will_sword");
		_obj->GetSprite()->SetMaxFrameX(6);
	}
	else if (_obj->GetAttackType() == AttackType::Bow)
	{
		_obj->GetSprite()->SetImgName("will_bow");
		_obj->GetSprite()->SetMaxFrameX(9);
	}

	_obj->GetSprite()->SetPosition(_obj->GetTrans()->GetPos() + Vector2(0, -14));

	//_isAtk = false;
	_timer = _count = 0;
	_delay = 0.4f;
}

void PlayerAttack::Update()
{
	if (_obj->GetSprite()->GetCurrentFrameX() == _obj->GetSprite()->GetMaxFrameX())
	{
		_timer += TIMEMANAGER->getElapsedTime();

		if (_timer >= _delay)
		{
			_timer -= _delay;
			_obj->ChangeState(new PlayerIdle(_obj));
		}
		else
		{
			if (_obj->GetAttackType() == AttackType::Sword)
			{
				if (KEYMANAGER->isOnceKeyDown('J'))
				{
					if (_count == 0)
					{
						_timer = 0;
						_count++;
						_obj->GetSprite()->SetMaxFrameX(11);
						_obj->GetSprite()->Resume();
					}
					else if (_count == 1)
					{
						_timer = 0;
						_count++;
						_obj->GetSprite()->SetMaxFrameX(6);
						_obj->GetSprite()->SetFrameX(1);
						_obj->GetSprite()->Resume();
					}
				}
			}
		}
	}
}

void PlayerAttack::Exit()
{
}
