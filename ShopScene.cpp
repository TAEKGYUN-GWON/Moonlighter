#include "stdafx.h"
#include "ShopScene.h"

void ShopScene::Init()
{
	Scene::Init();

	GRAPHICMANAGER->AddImage("ShopBg", L"resource/img/Shop/shop_background.png");
	
	GRAPHICMANAGER->AddFrameImage("Girl", L"resource/img/Shop/Girl.png", 9, 4);
	GRAPHICMANAGER->AddFrameImage("Guy", L"resource/img/Shop/Guy.png", 9, 4);
	GRAPHICMANAGER->AddFrameImage("Kid", L"resource/img/Shop/Kids.png", 6, 4);
	GRAPHICMANAGER->AddFrameImage("Lunk", L"resource/img/Shop/Lunk.png", 9, 4);

	_player = Object::CreateObject<Player>();
	_player->Init();

	_checkStand = Object::CreateObject<CheckStand>();
	_checkStand->Init(Vector2(0,0), Vector2(0,0));
	
	_npcMgr = new NpcManager; //NPC CreateObject�� NpcManager���� ���ش�.
	_npcMgr->SetCheckStandLink(_checkStand);
	_npcMgr->Init();

	_shopStandMgr = new ShopStandManager;
	_shopStandMgr->Init();

	//_npcShopState = new NpcShopState;
	//_npcShopState->SetCheckStandLink(_checkStand);
}

void ShopScene::Release()
{
	_npcMgr->Release();

	Scene::Release();
}

void ShopScene::Update()
{
	Scene::Update();
	
	_npcMgr->Update();

	if (KEYMANAGER->isOnceKeyDown('1')) SCENEMANAGER->changeScene("Dungeon");
	if (KEYMANAGER->isOnceKeyDown('2')) SCENEMANAGER->changeScene("Entrance");
	if (KEYMANAGER->isOnceKeyDown('3')) SCENEMANAGER->changeScene("Town");
	if (KEYMANAGER->isOnceKeyDown('4')) SCENEMANAGER->changeScene("Shop");
	if (KEYMANAGER->isOnceKeyDown('5')) SCENEMANAGER->changeScene("Maptool");
}

void ShopScene::Render()
{
	GRAPHICMANAGER->FindImage("ShopBg")->Render(WINSIZEX/2, WINSIZEY/2, CENTER);

	//GRAPHICMANAGER->FindImage("Girl")->FrameRender(WINSIZEX / 2, WINSIZEY / 2, 0, 0, CENTER);
	//GRAPHICMANAGER->FindImage("Guy")->FrameRender(WINSIZEX / 2 + 100, WINSIZEY / 2, 0, 0, CENTER);

	Scene::Render();
}
