#include "stdafx.h"
#include "DungeonScene.h"
#include "EntranceScene.h"
#include "TownScene.h"

void DungeonScene::Init()
{
	Scene::Init();

	cout << "´øÀü¾Àµé¾î¿È" << endl;
	SCENEMANAGER->addScene("Entrance", new EntranceScene);
	SCENEMANAGER->addScene("Town", new TownScene);


	_player = Object::CreateObject<Player>();
	_player->Init();

	_enemy = Object:: CreateObject<Enemy>();
	_enemy->Init();
}

void DungeonScene::Update()
{
	Scene::Update();
	//if (KEYMANAGER->isOnceKeyDown())
}
