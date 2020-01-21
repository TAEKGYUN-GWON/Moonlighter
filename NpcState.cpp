#include "stdafx.h"
#include "NpcState.h"
#include "Npc.h"

NpcIdle* NpcIdle::instance;
NpcDecide* NpcDecide::instance;
NpcInline* NpcInline::instance;
NpcExit* NpcExit::instance;

NpcIdle* NpcIdle::GetInstance()
{
	if (instance == nullptr)
	{
		instance = new NpcIdle();
	}
	return instance;
}

//==================���=====================
void NpcIdle::StateIn(Npc* npc)
{
	//�ϴ� ����� ���;��ϹǷ� ���� ���� �鿩���������..
	//���� ã�´�
	//â���� ������
	//â���� ����� ������ ��ĭ���� ������
}

void NpcIdle::StateStay(Npc* npc)
{
	//if ()//â�� �ڸ��� �����ϸ�
	{
		_counter++; //�����ؼ�
		if (_counter > RND->getFromIntTo(300, 1000)) //���ð� ���ļ�
		{
			StateOut(npc); //IDLE���¿��� ��������
		}

	}
}

void NpcIdle::StateOut(Npc* npc)
{
	//���� EXIT�� DECIDE �� ��� ���·� ���� ���ؾ���
	int a = RND->getInt(4);

	if (a < 3 && a >= 0) //0, 1, 2�� ��
	{
		_npc->SetNpcState(NpcIdle::GetInstance());//IDLE ���·� ����
	}
	else if (a == 3) //3�� ��
	{
		_npc->SetNpcState(NpcExit::GetInstance()); //EXIT ���·� ����
	}
}

NpcDecide* NpcDecide::GetInstance()
{
	if (instance == nullptr)
	{
		instance = new NpcDecide();
	}
	return instance;
}

//==================�츻=====================
void NpcDecide::StateIn(Npc* npc)
{
	//���ͼ� �Ұ� ����.. �ٷ� stay �ҷ�
	StateStay(npc);
}

void NpcDecide::StateStay(Npc* npc)
{
	//�ӹ����鼭�� �Ұ� ����.. �׳� ����
	StateOut(npc);
}

void NpcDecide::StateOut(Npc* npc)
{
	//���� �Ǵ��� ���⼭ �Ѵ�
	//if (������ �����Ѱ� * 1.1 ���� ũ��)
	{
		//ȭ�� �� �̹���  ����
		if (_counter > 500)
		{
			_npc->SetNpcState(NpcIdle::GetInstance());
		}
	}
	//else if (������ �����Ѱ� * 1.1 �� �۰� �������� ũ��(10�ۼ�Ʈ ��δ�)
	{
		//�Ҹ������� ��� ǥ�� ����
		if (_counter > 500)
		{
			_npc->SetNpcState(NpcInline::GetInstance());
		}
	}
	//else if (������ �����Ѱź��� �ΰ� 0.9���ٴ� ��δ�)
	{
		//���� �� ǥ�� ����
		if (_counter > 500)
		{
			_npc->SetNpcState(NpcInline::GetInstance());
		}
	}
	//else if (������ �����Ѱ� * 0.9 (10�� �δ�)
	{
		//���� ������ �� ǥ�� ����
		if (_counter > 500)
		{
			_npc->SetNpcState(NpcInline::GetInstance());
		}
	}
}

NpcInline* NpcInline::GetInstance()
{
	if (instance == nullptr)
	{
		instance = new NpcInline();
	}
	return instance;
}

//==================�ټ���=====================
void NpcInline::StateIn(Npc* npc)
{
}

void NpcInline::StateStay(Npc* npc)
{
}

void NpcInline::StateOut(Npc* npc)
{
}

NpcExit* NpcExit::GetInstance()
{
	if (instance == nullptr)
	{
		instance = new NpcExit();
	}
	return instance;
}

//==================������=====================
void NpcExit::StateIn(Npc* npc)
{
}

void NpcExit::StateStay(Npc* npc)
{
}

void NpcExit::StateOut(Npc* npc)
{
}
