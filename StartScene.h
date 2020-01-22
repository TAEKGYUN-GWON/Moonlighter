#pragma once
#include "Scene.h"
#include "Inventory.h"
class StartScene : public Scene
{
private:
	int frameX = 0;
	float count = 0;
	Inventory* inven;
public:
	virtual void Init();
	virtual void Update();
	virtual void Render();
};

