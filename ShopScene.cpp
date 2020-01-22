#include "stdafx.h"
#include "ShopScene.h"

void ShopScene::Init()
{
	Scene::Init();

	GRAPHICMANAGER->AddImage("ShopBg", L"resource/img/Shop/shop_background.png");

	_player = Object::CreateObject<Player>();
	_player->Init();

	_checkStand = Object::CreateObject<CheckStand>();
	_checkStand->Init();
	
	_npcMgr = new NpcManager; //NPC CreateObject는 NpcManager에서 해준다.
	_npcMgr->SetCheckStandLink(_checkStand);
	_npcMgr->Init();


	//_npcShopState = new NpcShopState;
	//_npcShopState->SetCheckStandLink(_checkStand);
}

void ShopScene::Update()
{
	_npcMgr->Update();
	Scene::Update();
}

void ShopScene::Render()
{
	GRAPHICMANAGER->FindImage("ShopBg")->Render(WINSIZEX/2, WINSIZEY/2, CENTER);
	_player->Render();
}
