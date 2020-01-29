#include "stdafx.h"
#include "EnemyManeger.h"


void EnemyManeger::Init(Dungeon* room)
{
	//해당 던전씬에 물려주기
	_astar = new Astar;
	_astar->Init(room->GetTiles(), Dungeon_X, Dungeon_Y);

	//강제형변환으로 플레이어 가져오기
	_player = (Player*) SCENEMANAGER->GetNowScene()->GetChildFromName("Will");
	_room = room;
	SetEnemy();
}

void EnemyManeger::Update()
{
	//vector 만큼 돌아야 겠지...생성해줘야 하니까?
	//각각의 enemy의 state를 변경? slime 은 slime 어택 골렘은 골렘어택?

	for (Enemy* e : _vEnemy)
	{
		if (e->GetMove())
		{
			if(Vector2::Distance(_player->GetTrans()->GetPos(), e->GetTrans()->GetPos()) > 80 &&
				Vector2::Distance(_player->GetTrans()->GetPos(), e->GetTrans()->GetPos()) < 600)
				e->SetPath(_astar->pathFinder(e->GetTrans()->GetPos() - _room->GetTrans()->GetPos(), _player->GetTrans()->GetPos() - _room->GetTrans()->GetPos()));
		}
		if (dynamic_cast<GolemEnemy*>(e))
		{
			if (Vector2::Distance(_player->GetTrans()->GetPos(), e->GetTrans()->GetPos()) <= GolemEnemy::GetAtkRange() && !dynamic_cast<EnemyAttack*>(e->GetState()))
			{ 
				e->SetAtk(true);
			}
		}
	}
	//_enemy->SetMove(false);
	//에너미가 탐색하는거 실시간으로 해야해..............

}

void EnemyManeger::Release()
{
	for (Enemy* e : _vEnemy)
	{
		SCENEMANAGER->GetNowScene()->GetWorld()->DestroyBody(e->GetComponent<PhysicsBody>()->GetBody());
	
		e->Release();
	}
	_vEnemy.clear();
}

void EnemyManeger::Render()
{

}

void EnemyManeger::SetEnemy()
{
	int rand = RND->getFromIntTo(2, 10);
	for (int i = 0; i < rand; i++)
	{
		int Ernad = RND->getInt(3);
		switch (Ernad)
		{
		case 0:
		{
			int size = RND->getFromIntTo(2, 5);
			for (int i = 0; i < size; i++)
			{
				SlimeEnemy* enemy = Object::CreateObject<SlimeEnemy>();
				Vector2 start(_room->GetTrans()->GetPos() + Vector2(160, 104));
				Vector2 end(_room->GetTrans()->GetPos() + Vector2(TILEWIDTH * Dungeon_X, TILEHEIGHT * Dungeon_Y) - Vector2(160, 104));
				Vector2 ePos(RND->getFromFloatTo(start.x, end.x), RND->getFromFloatTo(start.y, end.y));
				enemy->Init(ePos);
				_vEnemy.push_back(enemy);
			}
		}
		break;

		case 1:
		{
				GolemEnemy* enemy = Object::CreateObject<GolemEnemy>();
				Vector2 start(_room->GetTrans()->GetPos() + Vector2(160, 104));
				Vector2 end(_room->GetTrans()->GetPos() + Vector2(TILEWIDTH * Dungeon_X, TILEHEIGHT * Dungeon_Y) - Vector2(160, 104));
				Vector2 ePos(RND->getFromFloatTo(start.x, end.x), RND->getFromFloatTo(start.y, end.y));
				enemy->Init(ePos);
				_vEnemy.push_back(enemy);

		}
			
		break;

		case 2:
		{
			MintPotEnemy* enemy = Object::CreateObject<MintPotEnemy>();
			Vector2 start(_room->GetTrans()->GetPos() + Vector2(160, 104));
			Vector2 end(_room->GetTrans()->GetPos() + Vector2(TILEWIDTH * Dungeon_X, TILEHEIGHT * Dungeon_Y) - Vector2(160, 104));
			Vector2 ePos(RND->getFromFloatTo(start.x, end.x), RND->getFromFloatTo(start.y, end.y));
			enemy->Init(ePos);
			_vEnemy.push_back(enemy);
		}
		break;

		}
	}
}
