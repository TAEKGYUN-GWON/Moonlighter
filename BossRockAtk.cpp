#include "stdafx.h"
#include "BossRockAtk.h"
#include "BossIdle.h"

void BossRockAtk::Enter()
{
	_count = timer = 0;
	rocks = _boss->GetRocks();
	_Bstate = "Attack";
	_state = ROCKATK::START;

}

void BossRockAtk::Update()
{
	if (_count == rocks.size()) 
	{ 
		_state = ROCKATK::END;
		_count = 0;
	}

	timer += TIMEMANAGER->getElapsedTime();

	if (timer >= 0.3f)
	{
		switch (_state)
		{
		case ROCKATK::START:
		{
			rocks[_count]->SetIsActive(true);
			rocks[_count]->GetComponent<PhysicsBody>()->SetBodyActive(true);
		}
			break;
		case ROCKATK::END:
		{
			rocks[_count]->SetIsActive(false); 
			rocks[_count]->GetComponent<PhysicsBody>()->SetBodyActive(false);
		}
			break;
		}
		timer = 0;
		_count++;
	}

	if (_count == rocks.size() && _state == ROCKATK::END)
		_boss->SetState(new BossIdle(_boss));
}

void BossRockAtk::Exit()
{
}
