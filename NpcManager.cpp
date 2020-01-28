#include "stdafx.h"
#include "NpcManager.h"
#include "ShopStandManager.h"
void NpcManager::Init(ShopScene* parent)
{
	_counter = 0;
	_timer = RND->getFromIntTo(30, 100);

	

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
	   

	//집에가면 지우기
	Release();
	
	//충돌
	CheckStandCollision(); //계산대
	ShopStandCollision(); //가판대

	//Astar
	//AstarFunction();



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
	_npc->SetIsCheckSOn(false);
	_npc->SetIsShopSOn(false);
	_npc->Move(); //astar 일단 여기다가 담아놓음

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

//계산대랑 충돌
void NpcManager::CheckStandCollision()
{
	for (int i = 0; i < _vNpc.size(); i++)
	{
		int D = getDistance(
			_vNpc[i]->GetTrans()->GetPos().x, //엔피씨 위치랑
			_vNpc[i]->GetTrans()->GetPos().y,
			_checkStand->GetTrans()->GetPos().x,// 계산대 위치
			_checkStand->GetTrans()->GetPos().y); 
		//거리가 반지름 더한거보다 작아야 충돌임
		if (D < _vNpc[i]->GetTrans()->GetScale().x / 2 + _checkStand->GetTrans()->GetScale().x / 2)
		{
			_vNpc[i]->SetIsCheckSOn(true); //NPC가 계산대랑 충돌중 On!!!!!!!!!
			_checkStand->SetStandisInUse(true); //계산대가 사용중 ON!!!!!!!!!
		}
	}
}

//가판대랑 충돌
void NpcManager::ShopStandCollision()
{
	for (int i = 0; i < _vNpc.size(); i++)
	{
		for (int j = 0; j < _shopStandMgr->GetShopStandVector().size(); j++)
		{

			int D = getDistance(
				_vNpc[i]->GetTrans()->GetPos().x, //엔피씨 위치랑
				_vNpc[i]->GetTrans()->GetPos().y,
				_shopStandMgr->GetShopStandVector()[j]->GetTrans()->GetPos().x, //테이블위치
				_shopStandMgr->GetShopStandVector()[j]->GetTrans()->GetPos().y);
			//거리가 반지름 더한거보다 작아야 충돌임
			if (D < _vNpc[i]->GetTrans()->GetScale().x / 2 + _shopStandMgr->GetShopStandVector()[j]->GetTrans()->GetScale().x / 2)
			{
				_vNpc[i]->SetIsShopSOn(true); //NPC가 가판대랑 충돌중 On!!!!!!!!!
				_shopStandMgr->GetShopStandVector()[j]->SetIsInUse(true); //가판대가 사용중 ON!!!!!!!!!
			}
		}
	}

}

void NpcManager::AstarFunction(Vector2 destination)
{
	for (int i = 0; i < _vNpc.size(); i++)
	{
		_vNpc[i]->SetPath(_ast->pathFinder(
			_vNpc[i]->GetTrans()->GetPos(), //NPC의 위치
			Vector2(destination))); //가야할 위치
	}
}



