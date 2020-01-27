#pragma once
#include "Object.h"
#include "Enemy.h"
#include "SlimeEnemy.h"
#include "GolemEnemy.h"
#include "Boss.h"
#include "Astar.h"
#include "Player.h"


class EnemyManeger
{
private:
	Enemy* _enemy;
	Boss* _boss;
	vector<Enemy*> _vEnemy;

public:
	//a* 
	Astar* _astar;
	list<Vector2> pathFinder(Vector2 start, Vector2 end);
	
	Player* _player;
	//뭘 해줘야 하지?
	//enemy를 여기서 관리해 줘야 하긴 함
	//상태라던가 배치라던가 던전룸이 생성되면 세팅하는거를 여기서 해줘야 하나?
	//그래서 던전에서는 에너미메니저와 플레이어만 걸려 있어야 하나?
	//
	//으아아아아아ㅏㅏㄷ

	void Init();
	void Update();
	void Release();
	void Render();

	//hp
	//여기서 아이템?
};

