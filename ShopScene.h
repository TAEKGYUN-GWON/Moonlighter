#pragma once
#include "Scene.h"
#include "Player.h"
#include "NpcManager.h"
#include "CheckStand.h"
#include "NpcShopState.h"

class ShopScene : public Scene
{
private:
	Player* _player;
	NpcManager* _npcMgr;
	CheckStand* _checkStand; //°è»ê´ë
	NpcShopState* _npcShopState;


public:
	virtual void Init();
	virtual void Update();
	virtual void Render();
};

