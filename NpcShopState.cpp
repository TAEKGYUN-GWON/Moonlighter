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
	//��ǥ�� �޾Ƽ�. ����, ���Ǵ� �� �� �ٸ��� ó����
	

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
