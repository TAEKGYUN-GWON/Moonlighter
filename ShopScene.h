#pragma once
#include "Scene.h"
#include "Player.h"
#include "NpcManager.h"
#include "CheckStand.h"
#include "NpcShopState.h"
#include "ShopStandManager.h"
#include "Maptool.h"

class ShopScene : public Scene
{
private:
	Player* _player;
	NpcManager* _npcMgr;			 //npc �Ŵ���
	CheckStand* _checkStand;		 //����
	NpcShopState* _npcShopState;	 //Npc ����
	ShopStandManager* _shopStandMgr; //���Ǵ� �Ŵ���
	Tile* _tiles[TILENUMX * TILENUMY];
	tagTile _tagTiles[TILENUMX * TILENUMY];

public:
	virtual void Init()override;
	virtual void Release()override;
	virtual void Update()override;
	virtual void Render()override;
	void SetUp();
};

