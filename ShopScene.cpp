#include "stdafx.h"
#include "ShopScene.h"

void ShopScene::Init()
{
	Scene::Init();

	_player = Object::CreateObject<Player>();
	_player->Init();
}

void ShopScene::Update()
{
	Scene::Update();
}
