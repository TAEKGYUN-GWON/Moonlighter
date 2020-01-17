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
}

void StartScene::Update()
{
	Scene::Update();
	
}

