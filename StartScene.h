#pragma once
#include "Scene.h"
#include "Inventory.h"
#include "UiManager.h"
class StartScene : public Scene
{
private:
	UiObject* test;
	UiManager* ui;
	Inventory* inven;
public:
	virtual void Init();
	virtual void Update();
	virtual void Render();
};

