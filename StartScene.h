#pragma once
#include "Scene.h"
#include "ProgressBar.h"
#include"Inventory.h"
class StartScene : public Scene
{
private:
	ProgressBar* test;
	Inventory* inven;
	Item* t;
public:
	virtual void Init();
	virtual void Update();
	virtual void Render();
};

