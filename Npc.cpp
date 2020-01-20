#include "stdafx.h"
#include "Npc.h"
#include "NpcState.h"

//��������
Npc::Npc()
{
	_npcState = NpcStateIdle::GetInstance(); //���Ⱑ ������..
}

void Npc::Init()
{
	Object::Init();

	_tag = "Npc";
	
	_trans->SetPos(WINSIZEX / 2, WINSIZEY / 2);
	_trans->SetWorldPos(Vector2(30, 50)); //���߿� �׸� ũ���� �ٲ��ֱ�, framewidth
	
	_sprite = AddComponent<Sprite>();

	_physics = AddComponent<PhysicsBody>();
	_physics->Init(BodyType::DYNAMIC, 1.0f);

	_speed = 3.0f;
}

void Npc::Release()
{
}

void Npc::Update()
{

	//========�ൿ���� �Լ��� ������============
	//SetState(NpcState * npcstate); //�̰ŵ� ����ٰ� �̷��� �ϸ� �Ǵ°�����..
	//if (�������� ������ ������)
	{
	Act();
	}
	//else if (�������� ������ ������)
	{
	NotBuyStuffs();
	}
	GoHome();
	
	Object::Update();
}

void Npc::Render()
{
}

//=============�Ʒ� �Լ����� �ൿ��=================
void Npc::SetState(NpcState* npcstate) //�޾ƿ� ����
{
	this->_npcState = npcstate;
}

void Npc::Act()
{
	_npcState->Act(this); //�޾ƿ� ���� Ŭ������ �Լ��� ������
}

void Npc::NotBuyStuffs()
{
	_npcState->NotBuyStuffs(this); //�޾ƿ� ���� Ŭ������ �Լ��� ������
}

void Npc::GoHome()
{
	_npcState->GoHome(this); //�޾ƿ� ���� Ŭ������ �Լ��� ������
}
