#pragma once
#include "Object.h"
#include "Enemy.h"
#include "SlimeEnemy.h"
#include "GolemEnemy.h"
#include "MintPotEnemy.h"
#include "Boss.h"
#include "Astar.h"
#include "Player.h"
#include "Dungeon.h"

class Dungeon;

class EnemyManeger
{
private:
	Enemy* _enemy;
	Player* _player;
	Astar* _astar;
	Boss* _boss;
	vector<Enemy*> _vEnemy;
	Dungeon* _room;
public:
	
	
	//enemy를 여기서 관리해 줘야 하긴 함
	//상태라던가 배치라던가 던전룸이 생성되면 세팅하는거를 여기서 해줘야 하나?
	//그래서 던전에서는 에너미메니저와 플레이어만 걸려 있어야 하나?
	//으아아아아아ㅏㅏㄷ

	void Init(Dungeon* room);
	void Update();
	void Release();
	void Render();

	void SetEnemy();
	//hp
	//여기서 아이템?
};

