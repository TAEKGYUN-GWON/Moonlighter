#pragma once
#include "Scene.h"
#include "Player.h"
#include "NpcManager.h"

class ShopScene : public Scene
{
private:
	Player* _player;
	NpcManager* _npcMgr;


public:
	virtual void Init();
	virtual void Update();
	virtual void Render();
};

