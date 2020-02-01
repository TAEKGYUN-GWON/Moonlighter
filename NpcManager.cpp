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

	//Positions[0] = Vector2(520, 615); //â����
	////Positions[1] = Vector2(200,515); //1��(1��и�)
	//Positions[1] = Vector2(200,450); //1��(1��и�)
	//Positions[2] = Vector2(210,515); //2��
	//Positions[3] = Vector2(156,625); //3��
	//Positions[4] = Vector2(320,620); //4��
	//Positions[5] = Vector2(430,620); //����
	
	_positions[DESTINATION::WINDOW] = Vector2(520, 550); //â����
	//Positions[1] = Vector2(200,515); //1��(1��и�)
	_positions[DESTINATION::STAND1] = _shopStandMgr->GetShopStandVector()[0]->GetTrans()->GetPos()
		+ Vector2(50.0f, 0.0f); //1��(1��и�)
	_positions[DESTINATION::STAND2] = _shopStandMgr->GetShopStandVector()[1]->GetTrans()->GetPos() 
		+ Vector2(-50.0f, 0); //2��
	_positions[DESTINATION::STAND3] = _shopStandMgr->GetShopStandVector()[2]->GetTrans()->GetPos()
		+ Vector2(-50.0f, 0.0f); //3��
	_positions[DESTINATION::STAND4] = _shopStandMgr->GetShopStandVector()[0]->GetTrans()->GetPos()
		+ Vector2(50.0f, 0.0f); //4��
	_positions[DESTINATION::CHECKSTAND] = Vector2(430, 550); //����
}								  

void NpcManager::Update()
{
	//NPC�� 4�� �̸��̸� �� �־����	
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
	   

	//�������� �����
	Release();
	
	//�浹
	//CheckStandCollision(); //����
	//ShopStandCollision(); //���Ǵ�

	//Astar
	SetAstar();
	//AstarFunction(); //�̰� �ϴ� ġ��..

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
	//isactive�� false�� npc���͸� ã�Ƽ�
	//false�� �ְ� ������ ��������
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
	npc->SetIsAstarOn(true); //ast ����������

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


//����� �浹
void NpcManager::CheckStandCollision()
{
	for (int i = 0; i < _vNpc.size(); i++)
	{
		int D = getDistance(
			_vNpc[i]->GetTrans()->GetPos().x, //���Ǿ� ��ġ��
			_vNpc[i]->GetTrans()->GetPos().y,
			_checkStand->GetTrans()->GetPos().x,// ���� ��ġ
			_checkStand->GetTrans()->GetPos().y); 
		//�Ÿ��� ������ ���Ѱź��� �۾ƾ� �浹��
		if (D < _vNpc[i]->GetTrans()->GetScale().x / 2 + _checkStand->GetTrans()->GetScale().x / 2)
		{
			_vNpc[i]->SetIsCheckSOn(true); //NPC�� ����� �浹�� On!!!!!!!!!
			_checkStand->SetStandisInUse(true); //���밡 ����� ON!!!!!!!!!
		}
	}
}

//���Ǵ�� �浹
void NpcManager::ShopStandCollision()
{
	for (int i = 0; i < _vNpc.size(); i++)
	{
		for (int j = 0; j < _shopStandMgr->GetShopStandVector().size(); j++)
		{
			int D = getDistance(
				_vNpc[i]->GetTrans()->GetPos().x, //���Ǿ� ��ġ��
				_vNpc[i]->GetTrans()->GetPos().y,
				_shopStandMgr->GetShopStandVector()[j]->GetTrans()->GetPos().x, //���̺���ġ
				_shopStandMgr->GetShopStandVector()[j]->GetTrans()->GetPos().y);
			//�Ÿ��� ������ ���Ѱź��� �۾ƾ� �浹��
			if (D < _vNpc[i]->GetTrans()->GetScale().x / 2 + _shopStandMgr->GetShopStandVector()[j]->GetTrans()->GetScale().x / 2)
			{
				_vNpc[i]->SetIsShopSOn(true); //NPC�� ���Ǵ�� �浹�� On!!!!!!!!!
				_shopStandMgr->GetShopStandVector()[j]->SetIsInUse(true); //���Ǵ밡 ����� ON!!!!!!!!!

				cout << "���Ǵ�!!!" << endl;
			}
		}
	}
}

//���� ������ ����ٰ� �ɾ��༭ ��ġ�� �Ű������
void NpcManager::SetAstar()
{
	//���ݺ��� ���� �� �ɾ���� ��
	// if �ӿ��� �ٽ� state�� �ִ� npc�� bool�߿� �޾ƿͼ� ���ǰɾ�ߵɰ� ����
	
	for (int i = 0; i < _vNpc.size(); i++) //npc���ڸ�ŭ �˻��Ѵ�
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
	//if (_vNpc[i]->GetState() == (NpcShopState*)NpcIdle::GetInstance()) //idle�����ϋ�
	if (_vNpc[i]->GetIsAstarOn())
	{
		_vNpc[i]->SetPath(_ast->pathFinder( //��ã�� �Լ��� �θ��� //������� ���� 
			_vNpc[i]->GetTrans()->GetPos(), //NPC�� ��ġ�� ã�� //���⼭ �����°Ű���
			_positions[astar])); //������ ��ġ�� �޾ƿ� //�� ���� �ϴ� �����־��

		_vNpc[i]->SetIsAstarOn(false);
		_vNpc[i]->ChangeState(new NpcMove(_vNpc[i]));
	}
	
}



