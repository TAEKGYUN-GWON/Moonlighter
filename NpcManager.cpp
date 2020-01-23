#include "stdafx.h"
#include "NpcManager.h"

void NpcManager::Init()
{
	_counter = 0;

	for (int i = 0; i < 4; i++)
	{
		_npc = Object::CreateObject<Npc>();
		_npc->Init();
		_npc->SetCheckStandLink(_checkStand);

		_vNpc.push_back(_npc);

	}

}

void NpcManager::Update()
{

	//isactive�� false�� npc���͸� ã�Ƽ�
	//false�� �ְ� ������ ��������
	for (int i = 0; i < _vNpc.size(); ++i)
	{
		if (_npc->GetIsActive()) return; //��Ƽ��� �ٽ�ã��
		_vNpc.erase(_vNpc.begin() + i);

	}


	//_counter++;

	//if (_counter > RND->getInt(500))
	////if (_counter > RND->getFromIntTo(10, 200))
	//{
	//	for (int i = 0; i < 4; i++)
	//	{
	//		_npc = Object::CreateObject<Npc>();
	//		_npc->Init();
	//		_npc->SetCheckStandLink(_checkStand);

	//		_counter = 0;
	//		_vNpc.push_back(_npc);
	//		break;
	//	}

	//}

	//if (_vNpc.size() < 4)
	//{
	//	_npc = Object::CreateObject<Npc>();
	//	_npc->Init();

	//	_vNpc.push_back(_npc);
	//	cout << _vNpc.size() << endl;
	//}
	//���Ǿ� ���� ����� �����Ѽ���(�������4)���� ������ ���� ������

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
