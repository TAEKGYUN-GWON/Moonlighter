#pragma once
#include "Object.h"

class Bullet : public Object
{
private:
	Sprite* _sprite;
	PhysicsBody* _physics;
	float _speed;
	//������ƮǮ ������....

public:
	void Init(string imgKey, string tag, string name); //������ƮǮ�� ��ƶ�
	virtual void Update(); //move
	void Fire(Vector2 pos, float angle, float speed);	//���⼭ ������!
	void Move(); //ȭ��ۿ� ������ ���ư��� 
};