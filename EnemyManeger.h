#pragma once
#include "Object.h"
#include "Enemy.h"
#include "SlimeEnemy.h"
#include "GolemEnemy.h"
#include "Boss.h"


class EnemyManeger
{
private:
	Enemy* _enemy;
	Boss* _boss;
	vector<Enemy*> _vEnemy;

public:

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

