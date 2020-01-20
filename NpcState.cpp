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
	//�Ȼ��� �Ѱ���
	//�������� �̵��ϰ�
	//SetNpcState(npc, NpcStateIdle);
	//�̰��ϰ� �������ڷ� ī���͸� ������
	//ī���Ͱ� �ٵǸ� Idle->Act ���·� ������
	//������ �Ȱ�, �������°� ����..
}

void NpcStateDecide::Act(Npc* npc)
{
	//�����ϱ�� ����Ѱ���
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
	cout << "�Ͼ �� ���� ����" << endl;
}

void NpcStateInline::Act(Npc* npc)
{
	//Idle ���� �ٲ�����
	//����� �������ϱ� �ټ��Ⱑ �Ȱ���
	//�÷��̾ J������ ��������� �� Inline::Act �� ���;���
	//Ȥ�� �÷��̾ �ʹ� �ȴ��������� �ڵ����� ���;ߵǴµ�, ���� ���ص� �ƹ��� ��
	//SetNpcState(npc, NpcStateIdle);
}

void NpcStateInline::GoHome(Npc* npc)
{
	cout << "�̷����� �Ͼ �� ����.." << endl;
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
	cout << "�� ���¿����� �ൿ�� ����" << endl;
}

void NpcStateGoHome::Act(Npc* npc)
{
	cout << "�� ���¿����� �ൿ�� ����" << endl;
}

void NpcStateGoHome::GoHome(Npc* npc)
{
	cout << "�� ���¿����� �ൿ�� ����" << endl;
}
