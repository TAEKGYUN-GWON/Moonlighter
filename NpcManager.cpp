#include "stdafx.h"
#include "NpcManager.h"
#include "ShopStandManager.h"

void NpcManager::Init(ShopScene* parent)
{
	_counter = 0;
	_timer = RND->getFromIntTo(30, 100);

	_ast = new Astar;
	_ast->Init(parent->GetTiles(), SHOPTILEMAXX, SHOPTILEMAXY);
	//int a;

	//Positions[0] = Vector2(520, 615); //창문앞
	////Positions[1] = Vector2(200,515); //1번(1사분면)
	//Positions[1] = Vector2(200,450); //1번(1사분면)
	//Positions[2] = Vector2(210,515); //2번
	//Positions[3] = Vector2(156,625); //3번
	//Positions[4] = Vector2(320,620); //4번
	//Positions[5] = Vector2(430,620); //계산대
	
	_positions[DESTINATION::WINDOW] = Vector2(520, 550); //창문앞
	//Positions[1] = Vector2(200,515); //1번(1사분면)
	_positions[DESTINATION::STAND1] = _shopStandMgr->GetShopStandVector()[0]->GetTrans()->GetPos()
		+ Vector2(50.0f, 0.0f); //1번(1사분면)
	_positions[DESTINATION::STAND2] = _shopStandMgr->GetShopStandVector()[1]->GetTrans()->GetPos() 
		+ Vector2(-50.0f, 0); //2번
	_positions[DESTINATION::STAND3] = _shopStandMgr->GetShopStandVector()[2]->GetTrans()->GetPos()
		+ Vector2(-50.0f, 0.0f); //3번
	_positions[DESTINATION::STAND4] = _shopStandMgr->GetShopStandVector()[0]->GetTrans()->GetPos()
		+ Vector2(50.0f, 0.0f); //4번
	_positions[DESTINATION::CHECKSTAND] = Vector2(430, 550); //계산대
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

	//if (KEYMANAGER->isOnceKeyDown('L')) MakeNpc();
	   

	//집에가면 지우기
	Release();
	
	//충돌
	//CheckStandCollision(); //계산대
	//ShopStandCollision(); //가판대

	//Astar
	SetAstar();
	//AstarFunction(); //이건 일단 치워..

	for (int i = 0; i < _vNpc.size(); ++i)
	{
		_vNpc[i]->Update();
	}

	//if (_vNpc.size())
	//{
	//	cout << "ASTAR ON : " << _vNpc[0]->GetIsAstarOn() << endl;
	//	if (_vNpc[0]->GetPath().size())
	//	{
	//		cout << "Path size : " << _vNpc[0]->GetPath().size() << endl;
	//	}
	//}
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

void NpcManager::MakeNpc()
{
	Npc* npc = Object::CreateObject<Npc>();
	npc->SetIsCheckSOn(false);
	npc->SetIsShopSOn(false);
	npc->SetIsAstarOn(true); //ast 받을지말지

	if (_vNpc.size() < 4)
	{
		int a = RND->getInt(4);

		if (a ==0)
		{
			npc->Init("Girl");
			npc->SetName("girl");
			_vNpc.push_back(npc);
			return;
		}
		if (a == 1)
		{
			npc->Init("Guy");
			npc->SetName("guy");
			_vNpc.push_back(npc);
			return;
		}
		if (a == 2)
		{
			npc->Init("Kid");
			npc->SetName("kid");
			_vNpc.push_back(npc);
			return;
		}
		if (a == 3)
		{
			npc->Init("Lunk");
			npc->SetName("lunk");
			_vNpc.push_back(npc);
			return;
		}
	}

	else
	{
		for (int i = 0; i < _vNpc.size(); i++)
		{
			if (_vNpc[i]->GetName() != "girl")
			{
				npc->Init("Girl");
				npc->SetName("girl");
				_vNpc.push_back(npc);
				return;
			}
			else if (_vNpc[i]->GetName() != "guy")
			{
				npc->Init("Guy");
				npc->SetName("guy");
				_vNpc.push_back(npc);
				return;
			}
			else if (_vNpc[i]->GetName() != "kid")
			{
				npc->Init("Kid");
				npc->SetName("kid");
				_vNpc.push_back(npc);
				return;
			}
			else if (_vNpc[i]->GetName() != "lunk")
			{
				npc->Init("Lunk");
				npc->SetName("lunk");
				_vNpc.push_back(npc);
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

				cout << "가판대!!!" << endl;
			}
		}
	}
}

//상태 조건을 여기다가 걸어줘서 위치를 옮겨줘야함
void NpcManager::SetAstar()
{
	//지금보다 조건 더 걸어줘야 함
	// if 속에서 다시 state에 있는 npc의 bool중에 받아와서 조건걸어야될거 있음
	
	for (int i = 0; i < _vNpc.size(); i++) //npc숫자만큼 검사한다
	{

		if (_vNpc[i]->GetState()->GetStateType() == "Idle")
		{
			int a = RND->getInt(DESTINATION::STAND4);
			AstarFunction(i, a);
		}
	}
}

void NpcManager::AstarFunction(int i, int astar)
{
	//if (_vNpc[i]->GetState() == (NpcShopState*)NpcIdle::GetInstance()) //idle상태일떄
	if (_vNpc[i]->GetIsAstarOn())
	{
		_vNpc[i]->SetPath(_ast->pathFinder( //길찾기 함수를 부른다 //여기까지 들어옴 
			_vNpc[i]->GetTrans()->GetPos(), //NPC의 위치를 찾고 //여기서 터지는거같음
			_positions[astar])); //가야할 위치를 받아옴 //이 숫자 일단 랜덤넣어둠

		_vNpc[i]->SetIsAstarOn(false);
		_vNpc[i]->ChangeState(new NpcMove(_vNpc[i]));
	}
	
}



