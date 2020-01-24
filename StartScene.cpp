#include "stdafx.h"
#include "StartScene.h"
#include "DungeonScene.h"
#include "EntranceScene.h"
#include "ShopScene.h"
#include "TownScene.h"
#include "Maptool.h"

void StartScene::Init()
{
	Scene::Init();
	SCENEMANAGER->addScene("Dungeon", new DungeonScene);
	SCENEMANAGER->addScene("Town", new TownScene);
	SCENEMANAGER->addScene("Entrance", new EntranceScene);
	SCENEMANAGER->addScene("Shop", new ShopScene);
	SCENEMANAGER->addScene("Maptool", new Maptool);
}

void StartScene::Update()
{
	Scene::Update();
	if (KEYMANAGER->isOnceKeyDown('1')) SCENEMANAGER->changeScene("Dungeon");
	if (KEYMANAGER->isOnceKeyDown('2')) SCENEMANAGER->changeScene("Entrance");
	if (KEYMANAGER->isOnceKeyDown('3')) SCENEMANAGER->changeScene("Town");
	if (KEYMANAGER->isOnceKeyDown('4')) SCENEMANAGER->changeScene("Shop");
	if (KEYMANAGER->isOnceKeyDown('5')) SCENEMANAGER->changeScene("Maptool");
}

void StartScene::Render()
{
	Scene::Render();

	GRAPHICMANAGER->Text(Vector2(100, 100), "1) Dungeon Scene", 20, 300, 50, ColorF::AliceBlue);
	GRAPHICMANAGER->Text(Vector2(100, 150), "2) Town Scene", 20, 300, 50, ColorF::AntiqueWhite);
	GRAPHICMANAGER->Text(Vector2(100, 200), "3) Entrance Scene", 20, 300, 50, ColorF::Aqua);
	GRAPHICMANAGER->Text(Vector2(100, 250), "4) Shop Scene", 20, 300, 50, ColorF::Aquamarine);
	GRAPHICMANAGER->Text(Vector2(100, 300), "5) Maptool Scene", 20, 300, 50, ColorF::Azure);
}

