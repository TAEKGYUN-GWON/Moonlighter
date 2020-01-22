#include "stdafx.h"
#include "NpcShopState.h"
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
	//���� ������
	//Npc���¸� IDLE�� �ΰ� In()���� StateIn()�� �ҷ��༭ ����
	//if (â���ڸ��� ������)
	{
		cout << "NPCIDLE:stateIn" << endl;
		StateStay(npc);
	}
	//else if (â���ڸ��� ���� ��������)
	{
		//���� ã�´�(â���� ã��)
		//â���� ������� �ű�� ���� 
		//â���� ����� ������ ��ĭ���� ������
	
	}
}

void NpcIdle::StateStay(Npc* npc)
{

	if (!_isFunctionDone) //���� �� ��������
	{
		_counter++; //�����ؼ�
		if (_counter > RND->getFromIntTo(1, 10)) //���ð� ���ļ�
		{
			cout << "NPCIDLE:statestay" << endl;
			_counter = 0;
			_isFunctionDone = true;
			StateOut(npc); //IDLE���¿��� ��������
		}

	}
}

void NpcIdle::StateOut(Npc* npc)
{
	//���� EXIT�� DECIDE �� ��� ���·� ���� ���ؾ���
	int a = RND->getInt(4);
	cout << "NpcIdle: StateOut" << endl;
	if (a < 3 && a >= 0) //0, 1, 2�� ��
	{
		cout << "NPC IDLE�� ���ư� �ٽ� ���" << endl;
		npc->SetNpcState(NpcIdle::GetInstance());//IDLE ���·� ����
		_isFunctionDone = false; //���⼭ �ǵ�����..�ٸ��ֵ� �� �� �ְ�
	}
	else if (a == 3) //3�� ��
	{
		cout << "NPCEXIT:Getinstance , ���� ����" << endl;
		npc->SetNpcState(NpcExit::GetInstance()); //EXIT ���·� ����
		_isFunctionDone = false; //���⼭ �ǵ�����..�ٸ��ֵ� �� �� �ְ�
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
	StateStay(npc); //�̷��� ���Ѵ�� �θ����ֳ�?
}

void NpcDecide::StateStay(Npc* npc)
{
	//�ӹ����鼭�� �Ұ� ����.. �׳� ����
	StateOut(npc);//�̷��� ���Ѵ�� �θ����ֳ�?
}

void NpcDecide::StateOut(Npc* npc)
{
	//���� �Ǵ��� ���⼭ �Ѵ�
	//if (������ �����Ѱ� * 1.1 ���� ũ��)
	{
		//ȭ�� �� �̹���  ����
		if (_counter > 500)
		{
			npc->SetNpcState(NpcIdle::GetInstance());
		}
	}
	//else if (������ �����Ѱ� * 1.1 �� �۰� �������� ũ��(10�ۼ�Ʈ ��δ�)
	{
		//�Ҹ������� ��� ǥ�� ����
		if (_counter > 500)
		{
			npc->SetNpcState(NpcInline::GetInstance());
		}
	}
	//else if (������ �����Ѱź��� �ΰ� 0.9���ٴ� ��δ�)
	{
		//���� �� ǥ�� ����
		if (_counter > 500)
		{
			npc->SetNpcState(NpcInline::GetInstance());
		}
	}
	//else if (������ �����Ѱ� * 0.9 (10�� �δ�)
	{
		//���� ������ �� ǥ�� ����
		if (_counter > 500)
		{
			npc->SetNpcState(NpcInline::GetInstance());
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
	//�ڿ��� ����ؼ� ������ �߰��ض�..
	//å���� _isActivated ���¸� (�ջ���� ������) �տ� ����� �ִ� ��
	//if (�տ� ����� ������) return;
	//if (�տ� ����� ������)
	{
		_checkStand->SetStandState(true); //���븦 ��������� ����
		StateStay(npc);
	}
}

void NpcInline::StateStay(Npc* npc)
{

	//�÷��̾ J�� �����⸦ ��ٷ��� �Ѵ�..
	//�Ƹ� �̷��� ���� ó�������� �����Ű�
	//�÷��̾ J�� ������ ������ Activated�� false�� �Ǿ���ϰ�
	if(!_checkStand->GetStandState()) //���� ��Ȱ��ȭ ���¸� (�÷��̾ J�����ٸ�)
	{
		StateOut(npc);
	}
}

void NpcInline::StateOut(Npc* npc)
{

	npc->SetNpcState(NpcIdle::GetInstance());

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
	StateStay(npc);
}

void NpcExit::StateStay(Npc* npc)
{
	//�ش� ���Ǿ� ���͸� �����.. ���� npc�� ����..
}

void NpcExit::StateOut(Npc* npc)
{
	//���� �ϰŵ� ��� �ɵ�..
}
