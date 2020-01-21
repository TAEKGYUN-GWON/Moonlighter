#pragma once
#include "Scene.h"

class StartScene : public Scene
{
private:
	int frameX = 0;
	float count = 0;

public:
	virtual void Init();
	virtual void Update();
	virtual void Render();
};

