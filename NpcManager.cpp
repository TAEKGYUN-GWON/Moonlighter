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

	//������ �����ϴ� ��
	//_positions[DESTINATION::WINDOW] = Vector2(523, 615);  
	//_positions[DESTINATION::STAND1] = Vector2(287, 525); 
	//_positions[DESTINATION::STAND2] = Vector2(190, 525); 
	//_positions[DESTINATION::STAND3] = Vector2(226, 675); 
	//_positions[DESTINATION::STAND4] = Vector2(316, 616); 
	//_positions[DESTINATION::CHECKSTAND] = Vector2(430, 600);
	//_positions[DESTINATION::DOOR] = Vector2(406, 734); 

	_positions[DESTINATION::DES_WINDOW] = Vector2(583, 615); //â���� (x���� ���̳ʽ� 60�Ȱ��� ����)
	_positions[DESTINATION::DES_STAND1] = Vector2(225, 525); //1��(1��и�) 
	_positions[DESTINATION::DES_STAND2] = Vector2(137, 525); //2��
	_positions[DESTINATION::DES_STAND3] = Vector2(186, 656); //3��
	_positions[DESTINATION::DES_STAND4] = Vector2(316, 560); //4��
	_positions[DESTINATION::DES_CHECKSTAND] = Vector2(435, 523); //���� ��ǥ ������
	_positions[DESTINATION::DES_DOOR] = Vector2(400, 790); //���� 
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
			_npc->Init("Girl", Vector2(400, 700));
			_npc->SetName("girl");
			_vNpc.push_back(_npc);
			return;
		}
		if (a == 1)
		{
			_npc->Init("Guy", Vector2(400, 700));
			_npc->SetName("guy");
			_vNpc.push_back(_npc);
			return;
		}
		if (a == 2)
		{
			_npc->Init("Kid", Vector2(400, 700));
			_npc->SetName("kid");
			_vNpc.push_back(_npc);
			return;
		}
		if (a == 3)
		{
_npc->Init("Lunk", Vector2(400, 700));
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
			_npc->Init("Girl", Vector2(400, 700));
			_npc->SetName("girl");
			_vNpc.push_back(_npc);
			return;
		}
		else if (_vNpc[i]->GetName() != "guy")
		{
			_npc->Init("Guy", Vector2(400, 700));
			_npc->SetName("guy");
			_vNpc.push_back(_npc);
			return;
		}
		else if (_vNpc[i]->GetName() != "kid")
		{
			_npc->Init("Kid", Vector2(400, 700));
			_npc->SetName("kid");
			_vNpc.push_back(_npc);
			return;
		}
		else if (_vNpc[i]->GetName() != "lunk")
		{
			_npc->Init("Lunk", Vector2(400, 700));
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
	//�갡 ���Ϸ��� �����ִ��� �Ŵ������� �� üũ�ϰ� �������
	for (int i = 0; i < _vNpc.size(); i++) //npc���ڸ�ŭ �˻��Ѵ�
	{

		//���տ� ����(�������)
		if (_vNpc[i]->GetTrans()->GetPos().x > 390 && _vNpc[i]->GetTrans()->GetPos().x < 410 &&
			_vNpc[i]->GetTrans()->GetPos().y > 690 && _vNpc[i]->GetTrans()->GetPos().y < 710)
		{
			//â������ ������� ����
			if (_vNpc[i]->GetNpcThought() == NPCTHOUGHT::WINDOW)
			{
				_vNpc[i]->SetNpcNowPosition(NPCNOWPOSITION::POS_DOOR); //���� ��ġ�� â���̴�
				if (_vNpc[i]->GetNpcThought() == NPCTHOUGHT::WINDOW) //â������ ������� ���¸�
				{
					AstarFunction(i, DESTINATION::DES_WINDOW); //â������ ��
				}

			}
		}
		//���տ� ����(���� �����ϴ� ����)
		if (_vNpc[i]->GetTrans()->GetPos().x > 401 && _vNpc[i]->GetTrans()->GetPos().x < 411 &&
			_vNpc[i]->GetTrans()->GetPos().y > 729 && _vNpc[i]->GetTrans()->GetPos().y < 739)
		{
			//_vNpc[i]->SetNpcThought(NPCTHOUGHT::GOHOME); //â���տ��� ���� ���ֱ� ����..
			_vNpc[i]->SetNpcNowPosition(NPCNOWPOSITION::POS_DOOR);
			//���� ����� ����� ���� ��������
			//npcstate�� �� ��ġ���� üũ�ؼ� isactive=false; ���ٰ���
		}
		//â���տ� ����
		if (_vNpc[i]->GetTrans()->GetPos().x > 518 && _vNpc[i]->GetTrans()->GetPos().x < 528 &&
			_vNpc[i]->GetTrans()->GetPos().y > 610 && _vNpc[i]->GetTrans()->GetPos().y < 620)
		{
			_vNpc[i]->SetNpcNowPosition(NPCNOWPOSITION::POS_WINDOW); //â������

			int a = RND->getInt(4); //������ ���� ����

			if (a == 0)// ��������ʹ�
			{
				_vNpc[i]->SetNpcThought(NPCTHOUGHT::GOHOME); //��������ʹ�
				AstarFunction(i, DESTINATION::DES_DOOR);
			}
			if (a == 1 || a == 2 || a == 3) //�緯����
			{
				_vNpc[i]->SetNpcThought(NPCTHOUGHT::CHOOSE); //�����ϰ�ʹ�
				for (int j = 0; j < _shopStandMgr->GetShopStandVector().size(); j++)//���Ǵ�üũ
				{

					if (_shopStandMgr->GetShopStandVector()[j]->GetIsInUse() == false && //�ƹ�������
						_shopStandMgr->GetShopStandVector()[j]->GetIsItemOn() == true) //������ ����
					{
						AstarFunction(i, j + 1); //1��и��� 1���̶�, j+1 �ϸ� �� ��и� �� ������ ��
					}
					/*else if (_shopStandMgr->GetShopStandVector()[j+1]->GetIsInUse() == false &&
						_shopStandMgr->GetShopStandVector()[j+1]->GetIsItemOn() == true)
					{
						AstarFunction(i, j + 2);
					}
					else if (_shopStandMgr->GetShopStandVector()[j + 2]->GetIsInUse() == false &&
						_shopStandMgr->GetShopStandVector()[j + 2]->GetIsItemOn() == true)
					{
						AstarFunction(i, j + 3);
					}
					else if (_shopStandMgr->GetShopStandVector()[j + 3]->GetIsInUse() == false &&
						_shopStandMgr->GetShopStandVector()[j + 3]->GetIsItemOn() == true)
					{
						AstarFunction(i, j + 4);
					}*/
				}
			}
		}
		//�ǸŴ� �տ� ����
		if (_vNpc[i]->GetTrans()->GetPos().x > 510 && _vNpc[i]->GetTrans()->GetPos().x < 520 &&
			_vNpc[i]->GetTrans()->GetPos().y > 610 && _vNpc[i]->GetTrans()->GetPos().y < 620)
		{
			_vNpc[i]->SetNpcNowPosition(NPCNOWPOSITION::POS_STAND1);
		}
		//����
		

	}

}
void NpcManager::AstarFunction(int i, int asttar)
{
	if (_vNpc[i]->GetIsAstarOn())
	{
		_vNpc[i]->SetPath(_ast->pathFinder( //��ã�� �Լ��� �θ��� //������� ���� 
			_vNpc[i]->GetTrans()->GetPos(), //NPC�� ��ġ�� ã�� //���⼭ �����°Ű���
			_positions[asttar])); //������ ��ġ�� �޾ƿ� //�� ���� �ϴ� �����־��

		_vNpc[i]->SetIsAstarOn(false);
	}
	
}



