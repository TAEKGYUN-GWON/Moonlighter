#pragma once
#include "Object.h"
class Enemy : public Object
{
protected:
public:
	Enemy() {};
	~Enemy() {};

	virtual void Init();
	virtual void Update();
	virtual void Move();
	virtual void Render();
	virtual void Release();
};

//get,set�Լ� ������ �� hp�����
//������ �ٰ�...? 