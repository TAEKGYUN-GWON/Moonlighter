#include "stdafx.h"
#include "ShopScene.h"

void ShopScene::Init()
{
	Scene::Init();

	GRAPHICMANAGER->AddImage("ShopBg", L"resource/img/Shop/shop_background.png");

	_player = Object::CreateObject<Player>();
	_player->Init();

	//�ڡڡ���ġ �ٽ���� ������ �ٽ� �־����
	_checkStand = Object::CreateObject<CheckStand>();
	_checkStand->Init(Vector2(WINSIZEX/2, WINSIZEY/2), Vector2(50, 50));

	
	_npcMgr = new NpcManager; //NPC CreateObject�� NpcManager���� ���ش�.
	_npcMgr->SetCheckStandLink(_checkStand);
	_npcMgr->Init();


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
	_npcMgr->Update();

	Scene::Update();
}

void ShopScene::Render()
{
	GRAPHICMANAGER->FindImage("ShopBg")->Render(WINSIZEX/2, WINSIZEY/2, CENTER);
	_player->Render();

	Scene::Render();
}
