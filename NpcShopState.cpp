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
}

void NpcMove::Update()
{
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
