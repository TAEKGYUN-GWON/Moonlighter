#pragma once
#include "Scene.h"
#include "Player.h"

class ShopScene : public Scene
{
private:
	Player* _player;

public:
	virtual void Init();
	virtual void Update();
	virtual void Render();
};

