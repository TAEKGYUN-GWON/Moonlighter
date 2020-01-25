#pragma once
#include "Object.h"

class Bullet : public Object
{
private:
	Sprite* _sprite;
	PhysicsBody* _physics;
	float _speed;
	//오브젝트풀 변수로....

public:
	void Init(string imgKey, string tag, string name); //오브젝트풀에 담아라
	virtual void Update(); //move
	void Fire(Vector2 pos, float angle, float speed);	//여기서 꺼내기!
	void Move(); //화면밖에 나가면 돌아가라 
};