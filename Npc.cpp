#include "stdafx.h"
#include "Npc.h"
#include "NpcShopState.h"


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
	Object::Release();
}

void Npc::Update()
{
	In();
	//�Ʒ� �Լ����� In���� �����ְ� �������..
	//Stay();
	//Out();
	
	Object::Update();
}

void Npc::Render()
{
	Object::Render();
}

//���� ����
void Npc::In()
{
	_npcState->StateIn(this);
}

void Npc::Stay()
{
	_npcState->StateStay(this);
}

void Npc::Out()
{
	_npcState->StateOut(this);
}
