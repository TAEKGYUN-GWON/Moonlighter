#include "stdafx.h"
#include "StartScene.h"
#include "DungeonScene.h"
#include "EntranceScene.h"
#include "ShopScene.h"
#include "TownScene.h"
void StartScene::Init()
{
	Scene::Init();
	SCENEMANAGER->addScene("Dungeon", new DungeonScene);
	SCENEMANAGER->addScene("Town", new TownScene);
	SCENEMANAGER->addScene("Entrance", new EntranceScene);
	SCENEMANAGER->addScene("Shop", new ShopScene);
	inven = new Inventory;
	inven->Init();

	obj = Object::CreateObject<Object>();
	auto b = obj->GetTrans();
	b->SetPos(100, 100);
	b->SetScale(100, 100);
	obj->AddComponent<Sprite>();
	obj->SetCameraAffect(false);
	
	int a;
}

void StartScene::Update()
{
	Scene::Update();
	
	if (KEYMANAGER->isOnceKeyDown('1')) SCENEMANAGER->changeScene("Dungeon");
	if (KEYMANAGER->isOnceKeyDown('2')) SCENEMANAGER->changeScene("Entrance");
	if (KEYMANAGER->isOnceKeyDown('3')) SCENEMANAGER->changeScene("Town");
	if (KEYMANAGER->isOnceKeyDown('4')) SCENEMANAGER->changeScene("Shop");

	inven->Update();
}

void StartScene::Render()
{
	Scene::Render();
	inven->Render();
}

