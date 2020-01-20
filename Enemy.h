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

//get,set함수 만들어야 함 hp라던가
//아이템 줄거...? 