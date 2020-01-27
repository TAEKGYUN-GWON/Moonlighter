#include "stdafx.h"
#include "NpcManager.h"

void NpcManager::Init()
{
	_counter = 0;
	_timer = RND->getFromIntTo(30, 100);

	//_name 넣어준것은..
	//상점 나가서 벡터 삭제되면 다시 넣어줘야하는데
	//어떤애가 없는지 찾아서 넣어주려고..


}

void NpcManager::Update()
{

	//NPC가 4명 미만이면 더 넣어줘라	
	if (_vNpc.size() < 4)
	{
		_counter++;
		if (_counter == _timer)
		{
			MakeNpc();
			_counter = 0;
			_timer = RND->getFromIntTo(30, 100);
		}
	}
	cout << _vNpc.size() << endl;
	   

	//지우기
	Release();
	
	//Astar
	AstarFunction();



}

void NpcManager::Release()
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
}

void NpcManager::Render()
{
}

void NpcManager::MakeNpc()
{
	_npc = Object::CreateObject<Npc>();
	_npc->SetCheckStandLink(_checkStand);

	if (_vNpc.size() <= 0)
	{
		int a = RND->getInt(4);

		if (a ==0)
		{
			_npc->Init("Girl");
			_npc->SetName("girl");
			_vNpc.push_back(_npc);
			return;
		}
		if (a == 1)
		{
			_npc->Init("Guy");
			_npc->SetName("guy");
			_vNpc.push_back(_npc);
			return;
		}
		if (a == 2)
		{
			_npc->Init("Kid");
			_npc->SetName("kid");
			_vNpc.push_back(_npc);
			return;
		}
		if (a == 3)
		{
			_npc->Init("Lunk");
			_npc->SetName("lunk");
			_vNpc.push_back(_npc);
			return;
		}
	}

	else
	{
		for (int i = 0; i < _vNpc.size(); i++)
		{
			if (_vNpc[i]->GetName() != "girl")
			{
				_npc->Init("Girl");
				_npc->SetName("girl");
				_vNpc.push_back(_npc);
				return;
			}
			if (_vNpc[i]->GetName() != "guy")
			{
				_npc->Init("Guy");
				_npc->SetName("guy");
				_vNpc.push_back(_npc);
				return;
			}
			if (_vNpc[i]->GetName() != "kid")
			{
				_npc->Init("Kid");
				_npc->SetName("kid");
				_vNpc.push_back(_npc);
				return;
			}
			if (_vNpc[i]->GetName() != "lunk")
			{
				_npc->Init("Lunk");
				_npc->SetName("lunk");
				_vNpc.push_back(_npc);
				return;
			}
		}
	}
}

void NpcManager::AstarFunction()
{
	for (int i = 0; i < _vNpc.size(); i++)
	{
		_vNpc[i]->SetPath(_ast->pathFinder(
			_vNpc[i]->GetTrans()->GetPos(), //NPC의 위치
			Vector2(0, 0))); //가야할 위치
	}
}

void NpcManager::CheckStandCollision()
{
}

void NpcManager::ShopStandCollision()
{
}

