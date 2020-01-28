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

	//�ڿ��⼭ npc�� ast ���� �Ű������� ��ǥ�� �־�����ϴ°Ű���

	//if (â���ڸ��� ������)
	//{
		cout << "NPCIDLE:stateIn ���� �������" << endl;
	//	StateStay(npc);
	//}
	//else if (â���ڸ��� ���� ��������)
	//{
		//���� ã�´�(â���� ã��)
		//â���� ������� �ű�� ���� 
		//â���� ����� ������ ��ĭ���� ������
	
	//}
}

void NpcIdle::StateStay(Npc* npc)
{

	_counter++; //�����ؼ�
	if (_counter > RND->getFromIntTo(60, 100)) //���ð� ���ļ� //�̰� StateIn �����ð��� ������
	{
		cout << "NPCIDLE:statestay��" << endl;
		_counter = 0;

		StateOut(npc); //IDLE���¿��� ��������
	}

}

void NpcIdle::StateOut(Npc* npc)
{
	//���� EXIT�� DECIDE �� ��� ���·� ���� ���ؾ���
	int a = RND->getInt(4); // 75%Ȯ���� ���Ǵ�� ��
	cout << "NpcIdle: StateOut ����" << endl;
	if (a < 3 && a >= 0) //0, 1, 2�� ��
	{
		cout << "NpcIdle:StateOut:�ǸŴ�� �̵�, decide�� ��" << endl;
		npc->SetNpcState(NpcDecide::GetInstance());//NpcDecide ���·� ����
	}
	else if (a == 3) //3�� ��
	{
		cout << "NpdIdle,StateOut:������� ���" << endl;
		npc->SetNpcState(NpcExit::GetInstance()); //EXIT ���·� ����
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
	_counter++;
	
	//�׽�Ʈ��
	int a = RND->getInt(2);
	switch (a)
	{
	case 0:
		//ȭ�� �� �̹���  ����
		if (_counter > 500)
		{
			cout << "�Ȼ��� ���, Idle�� ���ư�" << endl;
			_counter = 0;
			npc->SetNpcState(NpcIdle::GetInstance());
		}
		break;
	case 1:
		//���� ������ �� ǥ�� ����
		if (_counter > 500)
		{
			cout << "���� ���, Inline���� ��" << endl;
			_counter = 0;
			npc->SetNpcState(NpcInline::GetInstance());
		}
		break;
	}
	//{
	//	//ȭ�� �� �̹���  ����
	//	if (_counter > 500)
	//	{
	//		cout << "�Ȼ��� ���, Idle�� ���ư�" << endl;
	//		npc->SetNpcState(NpcIdle::GetInstance());
	//	}
	//}
	////else if (������ �����Ѱ� * 1.1 �� �۰� �������� ũ��(10�ۼ�Ʈ ��δ�)
	//{
	//	//�Ҹ������� ��� ǥ�� ����
	//	if (_counter > 500)
	//	{
	//		npc->SetNpcState(NpcInline::GetInstance());
	//	}
	//}
	////else if (������ �����Ѱź��� �ΰ� 0.9���ٴ� ��δ�)
	//{
	//	//���� �� ǥ�� ����
	//	if (_counter > 500)
	//	{
	//		npc->SetNpcState(NpcInline::GetInstance());
	//	}
	//}
	//else if (������ �����Ѱ� * 0.9 (10�� �δ�)
	//{
	//	//���� ������ �� ǥ�� ����
	//	if (_counter > 500)
	//	{
	//		cout << "���� ���, Inline���� ��" << endl;
	//		npc->SetNpcState(NpcInline::GetInstance());
	//	}
	//}
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
	SetCheckStandLink (npc->GetCheckStand()); //�̰� �Ⱦ��� ū�ϳ� npcmanager�� collision���� ���ִµ� �ٸ���
	cout << "Inline ���� ������." << endl;
	
	//���� �����̰� �ϱⰡ �������.. �ϴ� üũ ���ϰ� �Ѿ����
	if (npc->GetIsCheckSOn() == true)return;//����� �浹���̸� ����, �տ� ����ִ°���
	else if (npc->GetIsCheckSOn() == false) //���밡 ���������
	{
		cout << "���븦 ���� ���" << endl;
		_checkStand->SetStandisInUse(true); //���븦 ��������� ����
		StateStay(npc);

	}
}

void NpcInline::StateStay(Npc* npc)
{
	cout << "�ټ��� ��ٸ��� ��" << endl;
	if (npc->GetIsCheckSOn() == true) //�浹���ϋ�
	{
		if (KEYMANAGER->isOnceKeyDown('J')) //���̸� ������
		{
			_checkStand->SetStandisInUse(false); //��Ȱ��Ű��
			npc->SetIsCheckSOn(false); //�浹�� �ƴѰɷ� ó��
			//�ڿ��⼭ �����۰� �Ǹž��� �޾ƾ���
		}

	}
	//�÷��̾ J�� �����⸦ ��ٷ��� �Ѵ�..
	if(_checkStand->GetStandisInUse() == false) //���� ��Ȱ��ȭ ���¸� (�÷��̾ J�����ٸ�)
	{
		cout << "���� ���" << endl;
		StateOut(npc);
	}
	//�Ƹ� �̷��� ���� ó�������� �����Ű�
	//�÷��̾ J�� ������ ������  �Ǿ���ϰ�
}

void NpcInline::StateOut(Npc* npc)
{

	cout << "IDLE�� ���ư���" << endl;
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
	StateOut(npc);
}

void NpcExit::StateOut(Npc* npc)
{
	//���� �ְ�?
	if (npc->GetIsActive())	cout << "�ڡ����� ���١ڡ�" << endl;
	//��ǥ�� ���⼭ �������� �̵�������
	//�������� �̵������� ȭ�鿡�� ������� isactive �� false��Ų��.
	npc->SetIsActive(false);
	//���⼭ npc�� isactive=false; ��Ű��, ���ʹ� �Ŵ������� ����
}
