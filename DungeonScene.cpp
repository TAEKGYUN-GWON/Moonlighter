#include "stdafx.h"
#include "DungeonScene.h"

void DungeonScene::Init()
{
	Scene::Init();

	_player = Object::CreateObject<Player>();
	_player->Init();
}

void DungeonScene::Update()
{
	Scene::Update();
}
