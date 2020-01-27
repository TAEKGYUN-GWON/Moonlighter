#include "stdafx.h"
#include "EnemyManeger.h"


void EnemyManeger::Init(Dungeon* parent)
{
	//�ش� �������� �����ֱ�
	_enemy = Object::CreateObject<Enemy>(parent);
	_enemy->Init();

	//��������ȯ���� �÷��̾� ��������
	_player = (Player*) SCENEMANAGER->GetNowScene()->GetChildFromName("Will");
}

void EnemyManeger::Update()
{
	//vector ��ŭ ���ƾ� ����...��������� �ϴϱ�?
	//�Ƹ� �ϴ� ���� �ɾ��ٵ�
	//A* pos ��������
	_enemy->SetPath(_astar->pathFinder(_enemy->GetTrans()->GetPos(),
		_player->GetTrans()->GetPos()));
}

void EnemyManeger::Release()
{
}

void EnemyManeger::Render()
{
}
