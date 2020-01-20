#include "stdafx.h"
#include "NpcState.h"


//���̺κ� ���� �𸣰��� �ϴ� �־ ����
NpcStateIdle* NpcStateIdle::instance;
NpcStateDecide* NpcStateDecide::instance;
NpcStateInline* NpcStateInline::instance;
NpcStateGoHome* NpcStateGoHome::instance;

//======================IDLE ����===========================

NpcStateIdle* NpcStateIdle::GetInstance()
{
	if (instance == nullptr)
	{
		instance = new NpcStateIdle(); //�� 
	}
	return instance;
}

void NpcStateIdle::NotBuyStuffs(Npc* npc)
{
	cout << "�̷��� ����" << endl;
}

void NpcStateIdle::Act(Npc* npc)
{
	//���̺� vector ������ _isActive = false �� ���̺��� ã�´�
	//ã������ �� ���̺� ������ �̵��Ѵ�
	//�̵� �Ϸ��ϸ� _npcState = Decide �� �Ǿ����

	//SetNpcState(npc, NpcStateDecide); //�̷��� ���ָ� �ɵ�..

	//���� ���� ������ ��𿡼� �������?
	//Npc.cpp�� update���� ���ְ��� �ϴ�
}

void NpcStateIdle::GoHome(Npc* npc)
{
	//SetNpcState(npc, NpcStateGoHome); //��Ȩ ���·� �ٲ�
}
//======================Search ����===========================
NpcStateDecide* NpcStateDecide::GetInstance()
{
	if (instance == nullptr)
	{
		instance = new NpcStateDecide();
	}
	return instance;
}

void NpcStateDecide::NotBuyStuffs(Npc* npc)
{
	//�������� �̵��ϰ�
	//SetNpcState(npc, NpcStateIdle);
	//�̰��ϰ� �������ڷ� ī���͸� ������
	//ī���Ͱ� �ٵǸ� Idle->Act ���·� ������
	//������ �Ȱ�, �������°� ����..
}

void NpcStateDecide::Act(Npc* npc)
{
	//�����ϱ�� ���������
	//���̺� �ִ� ������ ��ǥ�� ĳ�������� �پ����
	//_shopStand->SetActive(false); //���̺��� inactivate ����

}

void NpcStateDecide::GoHome(Npc* npc)
{
}
//======================Inline ����===========================
NpcStateInline* NpcStateInline::GetInstance()
{
	if (instance == nullptr)
	{
		instance = new NpcStateInline();
	}
	return instance;
}

void NpcStateInline::NotBuyStuffs(Npc* npc)
{
}

void NpcStateInline::Act(Npc* npc)
{
}

void NpcStateInline::GoHome(Npc* npc)
{
}
//======================GoHome ����===========================
NpcStateGoHome* NpcStateGoHome::GetInstance()
{
	if (instance == nullptr)
	{
		instance = new NpcStateGoHome();
	}
	return instance;
}

void NpcStateGoHome::NotBuyStuffs(Npc* npc)
{
}

void NpcStateGoHome::Act(Npc* npc)
{
}

void NpcStateGoHome::GoHome(Npc* npc)
{
}
