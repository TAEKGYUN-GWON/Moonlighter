#include "stdafx.h"
#include "NpcShopState.h"
#include "Npc.h"

//IDLE==========================
void NpcIdle::Enter()
{
	_state = "Idle";


}

void NpcIdle::Update()
{
	//좌표를 받아서. 계산대, 가판대 일 때 다르게 처리함
	

}

void NpcIdle::Exit()
{
}

//MOVE==========================
void NpcMove::Enter()
{
	_state = "Move";
	_timer = 0.0f;
}

void NpcMove::Update()
{
	if (_npc->GetPath()->size())
	{
		if (!_npc->GetIsAstarOn()) //갈곳이 있으면 false 상태
		{
			Vector2 a = *_npc->GetPath()->begin() - _npc->GetTrans()->GetPos(); // 가야할위치에서 내위치를 빼면, 가야되는 다음 노드가 나옴
			float b = Vector2::GetAngle( _npc->GetTrans()->GetPos(), *_npc->GetPath()->begin());
		
			_npc->GetTrans()->SetPos(_npc->GetTrans()->GetPos() + Vector2(cosf(b),-sinf(b)) * 50 * TIMEMANAGER->getElapsedTime());

			if ((int)Vector2::Distance(*_npc->GetPath()->begin(), _npc->GetTrans()->GetPos()) < (int)2)//조건 느슨하게 예외처리 해주는 부분
				_npc->GetPath()->pop_front(); //가장 첫번째 목적지 지우기, 다음 노드를 넣기 위해
		}
	
	}
	else //갈곳이 없으면 약간의 텀을 준 다음 true 만들어
	{
		_timer += TIMEMANAGER->getElapsedTime();
		if (_timer > 2)
		{
			_npc->SetIsAstarOn(true);
			_timer = 0;
			_npc->ChangeState(new NpcIdle(_npc));
		}
	}
}

void NpcMove::Exit()
{
}

//HOME==========================
void NpcHome::Enter()
{
	_state = "Home";
}

void NpcHome::Update()
{
}

void NpcHome::Exit()
{
}
