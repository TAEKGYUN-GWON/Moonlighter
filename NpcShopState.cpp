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
	//창문으로 가고싶은 상태면(입장직후는 무조건 이거)
	if (_npc->GetNpcThought() == NPCTHOUGHT::WINDOW)
	{
		_npc->ChangeState(new NpcMove(_npc));
	}
	//물건을 가격비교 해보고 사고싶은 상태면
	if (_npc->GetNpcThought() == NPCTHOUGHT::BUY)
	{
		_npc->ChangeState(new NpcMove(_npc));
	}
	//물건 비교해보고 안사고싶으면
	if (_npc->GetNpcThought() == NPCTHOUGHT::NOTBUY)
	{
		_npc->ChangeState(new NpcMove(_npc));
	}
	//집에 가고 싶으면
	if (_npc->GetNpcThought() == NPCTHOUGHT::GOHOME)
	{
		_npc->ChangeState(new NpcMove(_npc));
	}
}

void NpcIdle::Exit()
{

}

//MOVE==========================
void NpcMove::Enter()
{
	_state = "Move";
}

void NpcMove::Update()
{

	//창문으로 가고싶은 상태면(입장직후는 무조건 이거)
	if (_npc->GetNpcThought() == NPCTHOUGHT::WINDOW)
	{
		_npc->ChangeState(new NpcMove(_npc));
	}
	//물건을 가격비교 해보고 사고싶은 상태면
	if (_npc->GetNpcThought() == NPCTHOUGHT::BUY)
	{
		_npc->ChangeState(new NpcMove(_npc));
	}
	//물건 비교해보고 안사고싶으면
	if (_npc->GetNpcThought() == NPCTHOUGHT::NOTBUY)
	{
		_npc->ChangeState(new NpcMove(_npc));
	}
	//집에 가고 싶으면
	if (_npc->GetNpcThought() == NPCTHOUGHT::GOHOME)
	{
		_npc->ChangeState(new NpcHome(_npc));
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
	if (_npc->GetNpcNowPosition() == NPCNOWPOSITION::POS_DOOR)
	{
		if (_npc->GetNpcThought() == NPCTHOUGHT::GOHOME)
		{
			_npc->SetIsActive(false); //이렇게 해두면 매니저가 지움

		}

	}
}

void NpcHome::Exit()
{
}
