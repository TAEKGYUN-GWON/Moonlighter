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
	
	Positions[DESTINATION::WINDOW] = Vector2(520, 615); //â����
	//Positions[1] = Vector2(200,515); //1��(1��и�)
	//Positions[DESTINATION::STAND1] = Vector2(200, 450); //1��(1��и�)
	Positions[DESTINATION::STAND1] = Vector2(350, 555); //1��(1��и�)
	Positions[DESTINATION::STAND2] = Vector2(210, 515); //2��
	Positions[DESTINATION::STAND3] = Vector2(156, 625); //3��
	Positions[DESTINATION::STAND4] = Vector2(320, 620); //4��
	Positions[DESTINATION::CHECKSTAND] = Vector2(430, 620); //����
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
	CheckStandCollision(); //����
	ShopStandCollision(); //���Ǵ�

	//Astar
	SetAstar();
	//AstarFunction(); //�̰� �ϴ� ġ��..



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
	_npc = Object::CreateObject<Npc>();
	_npc->SetCheckStandLink(_checkStand);
	_npc->SetIsCheckSOn(false);
	_npc->SetIsShopSOn(false);
	_npc->SetIsAstarOn(true); //ast ����������
	//_npc->SetDestination(Vector2(392, 700)); //�����ϸ� ������ �����
	//_npc->Move(); //astar �ϴ� ����ٰ� ��Ƴ���

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
		//if (_vNpc[i]->GetIsAstarOn())
		if (_vNpc[i]->GetState() == NpcIdle::GetInstance())
		{
			int a = RND->getInt(5);
			AstarFunction(i, a); //for�� ���ư� i��, ������ ��
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
	//if (_vNpc[i]->GetState() == (NpcShopState*)NpcIdle::GetInstance()) //idle�����ϋ�
	if (_vNpc[i]->GetIsAstarOn())
	{
		_vNpc[i]->SetPath(_ast->pathFinder( //��ã�� �Լ��� �θ��� //������� ���� 
			_vNpc[i]->GetTrans()->GetPos(), //NPC�� ��ġ�� ã�� //���⼭ �����°Ű���
			Positions[asttar])); //������ ��ġ�� �޾ƿ� //�� ���� �ϴ� �����־��

		_vNpc[i]->SetIsAstarOn(false);
	}
	
}



