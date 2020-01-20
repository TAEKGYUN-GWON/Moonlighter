#include "stdafx.h"
#include "TownScene.h"

void TownScene::Init()
{
	Scene::Init();

	_player = Object::CreateObject<Player>();
	_player->Init();
}

void TownScene::Update()
{
	Scene::Update();
}
