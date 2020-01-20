#include "stdafx.h"
#include "EntranceScene.h"

void EntranceScene::Init()
{
	Scene::Init();

	_player = Object::CreateObject<Player>();
	_player->Init();
}

void EntranceScene::Update()
{
	Scene::Update();
}
