#pragma once
#include "Object.h"
#include "Ability.h"
#include "Player.h"

class BossBasic;
class BossIdle;
class BossAttack;
class BossHit;
class BossDead;


//���� ���� ����
enum PHASE
{
	ROCK,
	HAND,
	SLIME
};

class Boss : public Object
{
protected:
	Sprite* _sprite;
	PhysicsBody* _physics;
	Player* _player;
	float _speed; //���� �־�� �ϳ�?

	Ability* _ability;
	int _angle;
	
	list<Vector2> _path;

public:
	Boss();
	~Boss();

	PHASE _phase;

	int maxFrameX;
	int frameY;


	void Init(Vector2 pos);
	void Update();
	void Render();
	void Release();
	
	
	void Attack();
	void RockAtk();
	void BslimeAtk();

	//��ų(?)���� �Լ��� ����
	//�׸��� ���ÿ��� ����ġ���ϰ�
	//������ ������Ʈ�� �ɾ��ָ� �ǳ�??

	Ability* GetHP() { return _ability; }
	PhysicsBody* GetPhysics() { return _physics; }
	Sprite* GetSprite() { return _sprite; }
	Player* GetPlayer() { return _player; }
	PHASE GetPhase() { return _phase; }

	
};