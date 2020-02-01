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
	
	Positions[DESTINATION::WINDOW] = Vector2(520, 615); //창문앞
	//Positions[1] = Vector2(200,515); //1번(1사분면)
	//Positions[DESTINATION::STAND1] = Vector2(200, 450); //1번(1사분면)
	Positions[DESTINATION::STAND1] = Vector2(350, 555); //1번(1사분면)
	Positions[DESTINATION::STAND2] = Vector2(210, 515); //2번
	Positions[DESTINATION::STAND3] = Vector2(156, 625); //3번
	Positions[DESTINATION::STAND4] = Vector2(320, 620); //4번
	Positions[DESTINATION::CHECKSTAND] = Vector2(430, 620); //계산대
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
	CheckStandCollision(); //계산대
	ShopStandCollision(); //가판대

	//Astar
	SetAstar();
	//AstarFunction(); //이건 일단 치워..



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
	_npc = Object::CreateObject<Npc>();
	_npc->SetCheckStandLink(_checkStand);
	_npc->SetIsCheckSOn(false);
	_npc->SetIsShopSOn(false);
	_npc->SetIsAstarOn(true); //ast 받을지말지
	//_npc->SetDestination(Vector2(392, 700)); //시작하면 문으로 들어가라고
	//_npc->Move(); //astar 일단 여기다가 담아놓음

	if (_vNpc.size() < 4)
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
			else if (_vNpc[i]->GetName() != "guy")
			{
				_npc->Init("Guy");
				_npc->SetName("guy");
				_vNpc.push_back(_npc);
				return;
			}
			else if (_vNpc[i]->GetName() != "kid")
			{
				_npc->Init("Kid");
				_npc->SetName("kid");
				_vNpc.push_back(_npc);
				return;
			}
			else if (_vNpc[i]->GetName() != "lunk")
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
		//if (_vNpc[i]->GetIsAstarOn())
		if (_vNpc[i]->GetState() == NpcIdle::GetInstance())
		{
			int a = RND->getInt(5);
			AstarFunction(i, a); //for문 돌아간 i와, 목적지 ㅇ
		}
		//else if (_vNpc[i]->GetState() == NpcDecide::GetInstance())
		//{
		//	int a = RND->getInt(5);
		//	//AstarFunction(i, DESTINATION::WINDOW);
		//	AstarFunction(i, a);
		//}
		//else if (_vNpc[i]->GetState() == NpcInline::GetInstance())
		//{
		//	int a = RND->getInt(5);
		//	//AstarFunction(i, DESTINATION::WINDOW);
		//	AstarFunction(i, a);
		//}
		//else if (_vNpc[i]->GetState() == NpcExit::GetInstance())
		//{
		//	int a = RND->getInt(5);
		//	//AstarFunction(i, DESTINATION::WINDOW);
		//	AstarFunction(i, a);
		//}
	}

}
void NpcManager::AstarFunction(int i, int asttar)
{
	//if (_vNpc[i]->GetState() == (NpcShopState*)NpcIdle::GetInstance()) //idle상태일떄
	if (_vNpc[i]->GetIsAstarOn())
	{
		_vNpc[i]->SetPath(_ast->pathFinder( //길찾기 함수를 부른다 //여기까지 들어옴 
			_vNpc[i]->GetTrans()->GetPos(), //NPC의 위치를 찾고 //여기서 터지는거같음
			Positions[asttar])); //가야할 위치를 받아옴 //이 숫자 일단 랜덤넣어둠

		_vNpc[i]->SetIsAstarOn(false);
	}
	
}



