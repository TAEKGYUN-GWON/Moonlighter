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

	Object* obj = Object::CreateObject<Object>();
	obj->GetTrans()->SetPos(100, 500);
	obj->SetCameraAffect(false);
	obj->AddComponent<Text>()->CreateText(L"test", 20, 200, 500, ColorF::Red);
	//obj->GetComponent<Text>()->SetCameraEffected(obj->GetCameraAffect());
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
	GRAPHICMANAGER->DrawTextD2D(Vector2(100, 200), "fhdkdkkfk", 20, 1.0f, ColorF::Red, DWRITE_TEXT_ALIGNMENT_LEADING, L"¸¼Àº°íµñ", false);
	GRAPHICMANAGER->DrawTextD2D(Vector2(100, 300), "fhdkdkkfk", 20, 1.0f, ColorF::Red, DWRITE_TEXT_ALIGNMENT_TRAILING, L"¸¼Àº°íµñ", false);
	GRAPHICMANAGER->DrawTextD2D(Vector2(100, 400), "fhdkdkkfk", 20, 1.0f, ColorF::Red, DWRITE_TEXT_ALIGNMENT_CENTER, L"¸¼Àº°íµñ", false);
	GRAPHICMANAGER->DrawTextD2D(Vector2(100, 500), "camera No!", 20, 1.0f, ColorF::Red, DWRITE_TEXT_ALIGNMENT_LEADING, L"¸¼Àº°íµñ", true);

	
}

