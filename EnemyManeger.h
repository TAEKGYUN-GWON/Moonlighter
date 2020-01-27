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
	//�� ����� ����?
	//enemy�� ���⼭ ������ ��� �ϱ� ��
	//���¶���� ��ġ����� �������� �����Ǹ� �����ϴ°Ÿ� ���⼭ ����� �ϳ�?
	//�׷��� ���������� ���ʹ̸޴����� �÷��̾ �ɷ� �־�� �ϳ�?
	//
	//���ƾƾƾƾƤ�����

	void Init();
	void Update();
	void Release();
	void Render();

	//hp
	//���⼭ ������?
};

