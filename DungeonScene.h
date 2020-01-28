#pragma once
#include "Scene.h"
#include "Player.h"
#include "Enemy.h"
#include "EnemyManeger.h"
#include "Dungeon.h"
#include "DungeonMgr.h"

class DungeonScene : public Scene
{
private:
	Player* _player;
	Enemy* _enemy;	//���߿� enemymaneger�� �ٲ���� �Ұ�...?

	DungeonMgr* _dMgr;

public:
	virtual void Init();
	virtual void Update();
	virtual void Render();
};

