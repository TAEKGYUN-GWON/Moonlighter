#include "stdafx.h"
#include "NpcManager.h"
#include "Npc.h"

void NpcManager::Init()
{
	for (int i =0; i < 4; i++)
	{
		_npc = Object::CreateObject<Npc>();
		_npc->Init();

		_vNpc.push_back(_npc);
	}

}

void NpcManager::Update()
{
	if (_vNpc.size() < 5)
	{
		_npc = Object::CreateObject<Npc>();
		_npc->Init();

		_vNpc.push_back(_npc);
	}
	//���Ǿ� ���� ����� �����Ѽ���(�������4)���� ������ ���� ������
	StateControl();
	cout << _vNpc.size() << endl;
}

void NpcManager::Release()
{
}

void NpcManager::Render()
{
}

void NpcManager::StateControl()
{
}
