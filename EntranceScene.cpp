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

void EntranceScene::Render()
{
	Scene::Render();

	GRAPHICMANAGER->Text(Vector2(10, 6), L"Entrance Scene", 20, 200, 30, ColorF::Aqua);
}
