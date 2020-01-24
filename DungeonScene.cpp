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

	//GRAPHICMANAGER->DrawTextD2D(Vector2(WINSIZEX / 2, 30), )
}
