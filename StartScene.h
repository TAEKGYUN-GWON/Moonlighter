#pragma once
#include "Scene.h"

class StartScene : public Scene
{
private:
	UiObject* test;

public:
	virtual void Init();
	virtual void Update();
	virtual void Render();
};

