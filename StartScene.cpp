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
	if (KEYMANAGER->isOnceKeyDown(VK_F1)) 
	{
		SCENEMANAGER->changeScene("Dungeon");
		cout << "������" << endl;
	}
	if (KEYMANAGER->isOnceKeyDown(VK_F2)) 
	{
		SCENEMANAGER->changeScene("Entrance");
		cout << "�����Ա���" << endl;
	}
	if (KEYMANAGER->isOnceKeyDown(VK_F3)) 
	{
		SCENEMANAGER->changeScene("Town");
		cout << "������" << endl;
	}
	if (KEYMANAGER->isOnceKeyDown(VK_F4))
	{
		SCENEMANAGER->changeScene("Shop");
		cout << "������" << endl;
	}
}


