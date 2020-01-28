#include "stdafx.h"
#include "PlayerAttack.h"
#include "PlayerIdle.h"

void PlayerAttack::Enter()
{
	_obj->GetSprite()->SetFrameX(0);
	_obj->GetSprite()->SetFPS(1.5f);

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

	_isAtk = false;
}

void PlayerAttack::Update()
{
	if (_obj->GetAttackType() == AttackType::Sword)
	{
		if (!_isAtk)
		{
			_isAtk = true;
			_obj->GetSprite()->SetImgName("will_sword");
			//_obj->GetSprite()->SetMaxFrameX(11);
			_obj->GetSprite()->SetMaxFrameX(7);
		}
	}
	else if (_obj->GetAttackType() == AttackType::Bow)
	{
		if (!_isAtk)
		{
			_isAtk = true;
			_obj->GetSprite()->SetImgName("will_bow");
			_obj->GetSprite()->SetMaxFrameX(9);
		}
	}

	if (_obj->GetSprite()->GetCurrentFrameX() >= _obj->GetSprite()->GetMaxFrameX())
	{
		_obj->ChangeState(new PlayerIdle(_obj));
	}
}

void PlayerAttack::Exit()
{
}
