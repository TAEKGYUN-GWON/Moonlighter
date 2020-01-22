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
	//엔피씨 벡터 사이즈가 지정한숫자(예를들면4)보다 작으면 새로 만들어라
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
