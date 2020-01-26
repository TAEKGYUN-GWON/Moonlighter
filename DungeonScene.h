#pragma once
#include "Scene.h"
#include "Player.h"
#include "Enemy.h"
#include "EnemyManeger.h"
#include "Dungeon.h"

class DungeonScene : public Scene
{
private:
	Player* _player;
	Enemy* _enemy;	//���߿� enemymaneger�� �ٲ���� �Ұ�...?
	Dungeon* _dungeon;


public:
	virtual void Init();
	virtual void Update();
	virtual void Render();
};

