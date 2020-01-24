#pragma once
#include "Scene.h"

class StartScene : public Scene
{
private:
	RECT _rc[3];


public:
	virtual void Init();
	virtual void Update();
	virtual void Render();
};

