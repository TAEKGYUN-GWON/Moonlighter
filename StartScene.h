#pragma once
#include "Scene.h"
#include "Inventory.h"
class StartScene : public Scene
{
private:
	int frameX = 0;
	float count = 0;
	Object* obj;
	Inventory* inven;

public:
	virtual void Init();
	virtual void Update();
	virtual void Render();
};

