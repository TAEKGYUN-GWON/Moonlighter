#pragma once
#include "Scene.h"
#include "Player.h"

class TownScene : public Scene
{
private:
	Player* _player;

public:
	virtual void Init();
	virtual void Update();
};

