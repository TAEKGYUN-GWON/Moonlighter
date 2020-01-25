#pragma once
#include "Scene.h"
#include"Inventory.h"
#include"UiManager.h"

class StartScene : public Scene
{
private:
	UiObject* test;
	Inventory* inven;
	UiManager* ui;
public:
	virtual void Init();
	virtual void Update();
	virtual void Render();
};

