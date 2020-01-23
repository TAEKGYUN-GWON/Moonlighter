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

	//isactive가 false인 npc벡터를 찾아서
	//false인 애가 있으면 지워버려
	for (int i = 0; i < _vNpc.size(); ++i)
	{
		if (_npc->GetIsActive()) return; //액티브면 다시찾아
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
	//엔피씨 벡터 사이즈가 지정한숫자(예를들면4)보다 작으면 새로 만들어라

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
