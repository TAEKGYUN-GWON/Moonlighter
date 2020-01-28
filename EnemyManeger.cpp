#include "stdafx.h"
#include "EnemyManeger.h"


void EnemyManeger::Init(Dungeon* parent)
{
	//�ش� �������� �����ֱ�
	_enemy = Object::CreateObject<Enemy>(parent);
	_enemy->Init();
	_enemy->GetTrans()->SetPos(WINSIZEX / 2, 0);
	_enemy->GetTrans()->SetScale(50, 50);
	_enemy->AddComponent<Sprite>();
	_astar = new Astar;
	_astar->Init(parent->GetTiles(), Dungeon_X, Dungeon_Y);

	//��������ȯ���� �÷��̾� ��������
	_player = (Player*) SCENEMANAGER->GetNowScene()->GetChildFromName("Will");
}

void EnemyManeger::Update()
{
	//vector ��ŭ ���ƾ� ����...��������� �ϴϱ�?
	//A* pos ��������
	float dis = Vector2::Distance(_player->GetTrans()->GetPos(), _enemy->GetTrans()->GetPos());
	if (dis > 100 && dis < 400)
		_enemy->SetPath(_astar->pathFinder(_enemy->GetTrans()->GetPos(),
			_player->GetTrans()->GetPos()));
}

void EnemyManeger::Release()
{
}

void EnemyManeger::Render()
{
	wchar_t buffer[128];
	swprintf(buffer, 128, L"�Ÿ� : %f", Vector2::Distance(_player->GetTrans()->GetPos(), _enemy->GetTrans()->GetPos()));

	GRAPHICMANAGER->Text(Vector2(300, 200), buffer, 20, 300, 50, ColorF::Azure);
}
