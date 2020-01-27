#include "stdafx.h"
#include "EnemyManeger.h"


void EnemyManeger::Init(Dungeon* parent)
{
	//해당 던전씬에 물려주기
	_enemy = Object::CreateObject<Enemy>(parent);
	_enemy->Init();
	_astar = new Astar;
	_astar->Init();

	//강제형변환으로 플레이어 가져오기
	_player = (Player*) SCENEMANAGER->GetNowScene()->GetChildFromName("Will");
}

void EnemyManeger::Update()
{
	//vector 만큼 돌아야 겠지...생성해줘야 하니까?
	//A* pos 가져오기
	_enemy->SetPath(_astar->pathFinder(_enemy->GetTrans()->GetPos(),
		_player->GetTrans()->GetPos()));
}

void EnemyManeger::Release()
{
}

void EnemyManeger::Render()
{
}
