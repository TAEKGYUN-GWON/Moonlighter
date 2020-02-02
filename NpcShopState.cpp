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
	//â������ ������� ���¸�(�������Ĵ� ������ �̰�)
	if (_npc->GetNpcThought() == NPCTHOUGHT::WINDOW)
	{
		_npc->ChangeState(new NpcMove(_npc));
	}
	//������ ���ݺ� �غ��� ������ ���¸�
	if (_npc->GetNpcThought() == NPCTHOUGHT::BUY)
	{
		_npc->ChangeState(new NpcMove(_npc));
	}
	//���� ���غ��� �Ȼ�������
	if (_npc->GetNpcThought() == NPCTHOUGHT::NOTBUY)
	{
		_npc->ChangeState(new NpcMove(_npc));
	}
	//���� ���� ������
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

	//â������ ������� ���¸�(�������Ĵ� ������ �̰�)
	if (_npc->GetNpcThought() == NPCTHOUGHT::WINDOW)
	{
		_npc->ChangeState(new NpcMove(_npc));
	}
	//������ ���ݺ� �غ��� ������ ���¸�
	if (_npc->GetNpcThought() == NPCTHOUGHT::BUY)
	{
		_npc->ChangeState(new NpcMove(_npc));
	}
	//���� ���غ��� �Ȼ�������
	if (_npc->GetNpcThought() == NPCTHOUGHT::NOTBUY)
	{
		_npc->ChangeState(new NpcMove(_npc));
	}
	//���� ���� ������
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
			_npc->SetIsActive(false); //�̷��� �صθ� �Ŵ����� ����

		}

	}
}

void NpcHome::Exit()
{
}
