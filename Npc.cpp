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
	
	_trans->SetPos(400, 700); //�� �ۿ� ����
	_trans->SetScale(Vector2(
		GRAPHICMANAGER->FindImage(imgkey)->GetFrameWidth(),
		GRAPHICMANAGER->FindImage(imgkey)->GetFrameHeight()));

	_sprite->SetPosition(_trans->GetPos());

	//_destination = Vector2(340, 200);
}

void Npc::Release()
{
	Object::Release();
}

void Npc::Update()
{

	Object::Update();
	//���� �����̶�� ��� ��
	//if (_trans->GetPos() >= Vector2(392, 500))
	//_trans->SetPos(Vector2(_trans->GetPos()+Vector2::up));

	//�������Ͽ� �Լ�
	//In(); //in, stay �Ѵ� �صθ� �ֵ��� �� �ٸ��� ���ڴ�� ������
	Stay(); //�̷��� �θ� �������� �ѵθ� ���ƿ�

	//Astar �� �Լ�
	//SetPath(list<Vector2> lpath);
	Move();

	//npc �׸� ����
	_sprite->SetPosition(_trans->GetPos()); 

}

void Npc::Render()
{
	Object::Render();

	//�̰� ���ϸ� �ڲ� ��ü�Ҹ��� ���׶�̰� ���Ǿ�ó�� ������.. erase�Ҷ� false ����
	if (_isActive)
	{
		GRAPHICMANAGER->DrawEllipse(
			_trans->GetPos().x, 
			_trans->GetPos().y, 
			_trans->GetScale().x / 2, 
			_trans->GetScale().y / 2);
	}

	wchar_t buffer[128];
	swprintf(buffer, 128, L"x: %1.f, y:%1.f", _trans->GetPos().x , _trans->GetPos().y);
	GRAPHICMANAGER->Text(Vector2(_trans->GetPos().x, _trans->GetPos().y), buffer, 20, 500, 300, ColorF::White);
}

void Npc::SetPath(list<Vector2> lpath)
{
	this->_lPath.clear();
	this->_lPath = lpath;
}


void Npc::Move()
{
	if (_lPath.size()) 
	{
		if (!_isAstarOn) //������ ������ false ����
		{

			Vector2 a = *_lPath.begin() - _trans->GetPos(); // ��������ġ���� ����ġ�� ����, ���ߵǴ� ���� ��尡 ����
			_trans->pos += a.Nomalized() * NPDSPEED * TIMEMANAGER->getElapsedTime(); 

			if ((int)Vector2::Distance(*_lPath.begin(), _trans->GetPos()) < (int)10)//���� �����ϰ� ����ó�� ���ִ� �κ�
				_lPath.erase(_lPath.begin()); //���� ù��° ������ �����, ���� ��带 �ֱ� ����
		}

	}
	else //������ ������ true �����
		_isAstarOn = true;
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
