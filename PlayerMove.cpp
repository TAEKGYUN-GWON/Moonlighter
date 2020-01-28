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
	if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
	{
		if (KEYMANAGER->isStayKeyDown(VK_UP))
		{
			_obj->GetSprite()->SetFrameY(0);
			_obj->GetTrans()->SetPos(_obj->GetTrans()->GetPos() + Vector2(cosf((PI / 4) * Rad2Deg), -sinf((PI / 4) * Rad2Deg)) * _obj->GetSpeed() * TIMEMANAGER->getElapsedTime());
			_obj->SetDirection(Dir::Up);
		}
		else if (KEYMANAGER->isStayKeyDown(VK_DOWN))
		{
			_obj->GetSprite()->SetFrameY(1);
			_obj->GetTrans()->SetPos(_obj->GetTrans()->GetPos() + Vector2(cosf((PI / 4) * Rad2Deg), sinf((PI / 4) * Rad2Deg)) * _obj->GetSpeed() * TIMEMANAGER->getElapsedTime());
			_obj->SetDirection(Dir::Down);
		}
		else
		{
			_obj->GetSprite()->SetFrameY(2);
			_obj->GetTrans()->SetPos(_obj->GetTrans()->GetPos() + Vector2::right * _obj->GetSpeed() * TIMEMANAGER->getElapsedTime());
			_obj->SetDirection(Dir::Right);
		}
		_obj->GetSprite()->SetPosition(_obj->GetTrans()->GetPos() + Vector2(0, 2));
		_obj->GetPhysics()->SetBodyPosition();
	}
	else if (KEYMANAGER->isStayKeyDown(VK_LEFT))
	{
		if (KEYMANAGER->isStayKeyDown(VK_UP))
		{
			_obj->GetSprite()->SetFrameY(0);
			_obj->GetTrans()->SetPos(_obj->GetTrans()->GetPos() + Vector2(cosf(PI * RadToDeg), -sinf((PI / 2) * RadToDeg)) * _obj->GetSpeed() * TIMEMANAGER->getElapsedTime());
			_obj->SetDirection(Dir::Up);
		}
		else if (KEYMANAGER->isStayKeyDown(VK_DOWN))
		{
			_obj->GetSprite()->SetFrameY(1);
			_obj->GetTrans()->SetPos(_obj->GetTrans()->GetPos() + Vector2(cosf(PI * RadToDeg), -sinf((5 * PI /4) * Rad2Deg)) * _obj->GetSpeed() * TIMEMANAGER->getElapsedTime());
			_obj->SetDirection(Dir::Down);
		}
		else
		{
			_obj->GetSprite()->SetFrameY(3);
			_obj->GetTrans()->SetPos(_obj->GetTrans()->GetPos() + Vector2::left * _obj->GetSpeed() * TIMEMANAGER->getElapsedTime());
			_obj->SetDirection(Dir::Left);
		}
		_obj->GetSprite()->SetPosition(_obj->GetTrans()->GetPos() + Vector2(0, 2));
		_obj->GetPhysics()->SetBodyPosition();
	}
	else if (KEYMANAGER->isStayKeyDown(VK_UP))
	{
		_obj->GetSprite()->SetFrameY(0);
		_obj->GetTrans()->SetPos(_obj->GetTrans()->GetPos() + Vector2::up * _obj->GetSpeed() * TIMEMANAGER->getElapsedTime());
		_obj->GetSprite()->SetPosition(_obj->GetTrans()->GetPos() + Vector2(0, 2));
		_obj->SetDirection(Dir::Up);
		_obj->GetPhysics()->SetBodyPosition();
	}
	else if (KEYMANAGER->isStayKeyDown(VK_DOWN))
	{
		_obj->GetSprite()->SetFrameY(1);
		_obj->GetTrans()->SetPos(_obj->GetTrans()->GetPos() + Vector2::down * _obj->GetSpeed() * TIMEMANAGER->getElapsedTime());
		_obj->GetSprite()->SetPosition(_obj->GetTrans()->GetPos() + Vector2(0, 2));
		_obj->SetDirection(Dir::Down);
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
