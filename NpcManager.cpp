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
	cout << _vNpc.size() << endl;
	   

	//�������� �����
	Release();
	
	//�浹
	CheckStandCollision(); //����
	ShopStandCollision(); //���Ǵ�

	//Astar
	//AstarFunction();



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

void NpcManager::Render()
{
}

void NpcManager::MakeNpc()
{
	_npc = Object::CreateObject<Npc>();
	_npc->SetCheckStandLink(_checkStand);
	_npc->SetIsCheckSOn(false);
	_npc->SetIsShopSOn(false);
	_npc->Move(); //astar �ϴ� ����ٰ� ��Ƴ���

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
			}
		}
	}

}

void NpcManager::AstarFunction(Vector2 destination)
{
	for (int i = 0; i < _vNpc.size(); i++)
	{
		_vNpc[i]->SetPath(_ast->pathFinder(
			_vNpc[i]->GetTrans()->GetPos(), //NPC�� ��ġ
			Vector2(destination))); //������ ��ġ
	}
}



