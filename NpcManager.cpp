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

	//isactive가 false인 npc벡터를 찾아서
//false인 애가 있으면 지워버려
	for (int i = 0; i < _vNpc.size(); ++i)
	{
		if (!_vNpc[i]->GetIsActive())
		{
			_vNpc.erase(_vNpc.begin() + i);
		}

	}
	
	cout << _vNpc.size() << endl;

	//4마리 될 때까지 새로 만들기
	//_counter++;
	//if (_counter > RND->getFromIntTo(10, 100))
	//{
	//	for (int i = 0; i < 4; i++) //4마리 될때까지 새로 만들어
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


	//엔피씨 벡터 사이즈가 지정한숫자(예를들면4)보다 작으면 새로 만들어라
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
