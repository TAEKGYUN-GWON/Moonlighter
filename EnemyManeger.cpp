#include "stdafx.h"
#include "EnemyManeger.h"


void EnemyManeger::Init(Dungeon* parent)
{
	//해당 던전씬에 물려주기
	_enemy = Object::CreateObject<Enemy>(parent);
	_enemy->Init();
	_enemy->GetTrans()->SetPos(WINSIZEX / 2, 0);
	_enemy->GetTrans()->SetScale(50, 50);
	_enemy->AddComponent<Sprite>();
	_astar = new Astar;
	_astar->Init(parent->GetTiles(), Dungeon_X, Dungeon_Y);

	//강제형변환으로 플레이어 가져오기
	_player = (Player*) SCENEMANAGER->GetNowScene()->GetChildFromName("Will");
}

void EnemyManeger::Update()
{
	//vector 만큼 돌아야 겠지...생성해줘야 하니까?
	//A* pos 가져오기
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
	swprintf(buffer, 128, L"거리 : %f", Vector2::Distance(_player->GetTrans()->GetPos(), _enemy->GetTrans()->GetPos()));

	GRAPHICMANAGER->Text(Vector2(300, 200), buffer, 20, 300, 50, ColorF::Azure);
}
