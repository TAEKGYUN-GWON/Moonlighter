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
	
	
	//enemy�� ���⼭ ������ ��� �ϱ� ��
	//���¶���� ��ġ����� �������� �����Ǹ� �����ϴ°Ÿ� ���⼭ ����� �ϳ�?
	//�׷��� ���������� ���ʹ̸޴����� �÷��̾ �ɷ� �־�� �ϳ�?
	//���ƾƾƾƾƤ�����

	void Init(Dungeon* room);
	void Update();
	void Release();
	void Render();

	void SetEnemy();
	//hp
	//���⼭ ������?
};

