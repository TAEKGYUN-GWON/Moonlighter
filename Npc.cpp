#include "stdafx.h"
#include "Npc.h"
#include "NpcShopState.h"

void Npc::Init(string imgkey)
{
	
	Object::Init();

	_tag = "Npc";

	_sprite = AddComponent<Sprite>();
	_sprite->Init(true, true);
	_sprite->SetImgName(imgkey);

	SetNpcState(NpcIdle::GetInstance()); //�⺻ ����
	
	_trans->SetPos(392, 800); //�� �ۿ� ����
	_trans->SetScale(Vector2(
		GRAPHICMANAGER->FindImage(imgkey)->GetFrameWidth(),
		GRAPHICMANAGER->FindImage(imgkey)->GetFrameHeight()));

	_speed = 3.0f;
	//_destination = Vector2(0, 0);


	int a;

	
}

void Npc::Release()
{
	Object::Release();
}

void Npc::Update()
{

	//���� �����̶�� ��� ��
	//if (_trans->GetPos() >= Vector2(392, 500))
	//_trans->SetPos(Vector2(_trans->GetPos()+Vector2::up));

	//�������Ͽ� �Լ�
	Stay();

	//Astar �� �Լ�
	//SetPath(list<Vector2> lpath);
	Move();

	//npc �׸� ����
	_sprite->SetPosition(_trans->GetPos()); 

	Object::Update();
}

void Npc::Render()
{
	Object::Render();
	GRAPHICMANAGER->DrawEllipse(_trans->GetPos().x, _trans->GetPos().y, _trans->GetScale().x/2, _trans->GetScale().y/2);

}

void Npc::SetPath(list<Vector2> lpath)
{
	this->_lPath.clear();
	this->_lPath = lpath;
}


void Npc::Move()
{

	if (_lPath.size()) //�� ������ ���� ����
	{
		Vector2 a = *_lPath.begin() - _trans->pos; // ��������ġ���� ����ġ�� ����, ���ߵǴ� ���� ��尡 ����
		_trans->pos += a.Nomalized() * 70 * TIMEMANAGER->getElapsedTime(); //���� �����ϰ� ����ó�� ���ִ� �κ�

		if ((int)Vector2::Distance(*_lPath.begin(), _trans->pos) < (int)20)//�ٷ� ���� ��忡 �����ϸ� 
			_lPath.erase(_lPath.begin()); //���� ù��° ������ �����, ���� ��带 �ֱ� ����

	}
}

void Npc::SetNpcState(NpcShopState* npcshopstate)
{
	_npcShopState = npcshopstate;
	_npcShopState->StateIn(this);
	
}


//���� ����
void Npc::In()
{
	_npcShopState->StateIn(this);
}

void Npc::Stay()
{
	_npcShopState->StateStay(this);
}

void Npc::Out()
{
	_npcShopState->StateOut(this);
}
