#include "stdafx.h"
#include "NpcManager.h"

void NpcManager::Init()
{
	_counter = 0;

	{
		_npc = Object::CreateObject<Npc>();
		_npc->SetCheckStandLink(_checkStand);
		_npc->Init("Girl");

		_vNpc.push_back(_npc);
	}
	{
		_npc = Object::CreateObject<Npc>();
		_npc->SetCheckStandLink(_checkStand);
		_npc->Init("Guy");

		_vNpc.push_back(_npc);
	}
	{
		_npc = Object::CreateObject<Npc>();
		_npc->SetCheckStandLink(_checkStand);
		_npc->Init("Kid");

		_vNpc.push_back(_npc);
	}
	{
		_npc = Object::CreateObject<Npc>();
		_npc->SetCheckStandLink(_checkStand);
		_npc->Init("Lunk");

		_vNpc.push_back(_npc);
	}

}

void NpcManager::Update()
{

	//isactive�� false�� npc���͸� ã�Ƽ�
//false�� �ְ� ������ ��������
	for (int i = 0; i < _vNpc.size(); ++i)
	{
		if (!_vNpc[i]->GetIsActive())
		{
			_vNpc.erase(_vNpc.begin() + i);
		}

	}
	
	cout << _vNpc.size() << endl;

	//4���� �� ������ ���� �����
	//_counter++;
	//if (_counter > RND->getFromIntTo(10, 100))
	//{
	//	for (int i = 0; i < 4; i++) //4���� �ɶ����� ���� �����
	//	{
	//		_npc = Object::CreateObject<Npc>();
	//		_npc->Init();
	//		_npc->SetCheckStandLink(_checkStand);

	//		_vNpc.push_back(_npc);
	//		_counter = 0;
	//		break;
	//	}
	//	
	//}


	//���Ǿ� ���� ����� �����Ѽ���(�������4)���� ������ ���� ������
	_counter++;
	//if (_counter > RND->getFromIntTo(50, 100))
	//{
	//	if (_vNpc.size() < 4)
	//	{
	//		_npc = Object::CreateObject<Npc>();
	//		_npc->Init();
	//		_npc->SetCheckStandLink(_checkStand);

	//		_vNpc.push_back(_npc);
	//		_counter = 0;
	//	}
	//}
}

void NpcManager::Release()
{

}

void NpcManager::Render()
{
}

void NpcManager::CheckStandCollision()
{
}

void NpcManager::ShopStandCollision()
{
}
