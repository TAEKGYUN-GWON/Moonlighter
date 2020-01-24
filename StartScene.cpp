#include "stdafx.h"
#include "StartScene.h"
#include "DungeonScene.h"
#include "EntranceScene.h"
#include "ShopScene.h"
#include "TownScene.h"
#include "Maptool.h"
#include "UiManager.h"
#include "Potions.h"
void StartScene::Init()
{
	Scene::Init();
	SCENEMANAGER->addScene("Dungeon", new DungeonScene);
	SCENEMANAGER->addScene("Town", new TownScene);
	SCENEMANAGER->addScene("Entrance", new EntranceScene);
	SCENEMANAGER->addScene("Shop", new ShopScene);
	SCENEMANAGER->addScene("Maptool", new Maptool);
	GRAPHICMANAGER->AddImage("Potion_S", L"resource/img/Items/Potion_S.png");


	GRAPHICMANAGER->AddFrameImage("hp", L"resource/img/UI/Hpbar.png", 1, 6);
	test = new ProgressBar;
	test->Init(Vector2(WINSIZEX / 2, WINSIZEY / 2), "hp");
	UiManager::getSingleton()->Init();
	t = Item::CreateItem<Potion_S>(Vector2(WINSIZEX / 3, WINSIZEY / 2));
}

void StartScene::Update()
{
	Scene::Update();
	test->Update();

	if (KEYMANAGER->isOnceKeyDown('1')) SCENEMANAGER->changeScene("Dungeon");
	if (KEYMANAGER->isOnceKeyDown('2')) SCENEMANAGER->changeScene("Entrance");
	if (KEYMANAGER->isOnceKeyDown('3')) SCENEMANAGER->changeScene("Town");
	if (KEYMANAGER->isOnceKeyDown('4')) SCENEMANAGER->changeScene("Shop");
	if (KEYMANAGER->isOnceKeyDown('5')) SCENEMANAGER->changeScene("Maptool");
	if (KEYMANAGER->isOnceKeyDown('6')) test->SetGauge(50,100);
}

void StartScene::Render()
{
	Scene::Render();
	char buffer[128];

	sprintf_s(buffer, "%f, %f", CAMERA->GetPosition().x, CAMERA->GetPosition().y);
	GRAPHICMANAGER->DrawTextD2D(Vector2(WINSIZEX / 2, 100), buffer, 20 ,1,ColorF::Red, DWRITE_TEXT_ALIGNMENT_LEADING, L"¸¼Àº°íµñ", false);
	sprintf_s(buffer, "1¹øÀº ´øÀü¾À", t->GetTrans()->GetScale().x, t->GetTrans()->GetScale().y);
	GRAPHICMANAGER->DrawTextD2D(Vector2(WINSIZEX / 2, WINSIZEY/2), buffer, 20 ,1,ColorF::Red, DWRITE_TEXT_ALIGNMENT_LEADING, L"¸¼Àº°íµñ", false);
	//GRAPHICMANAGER->DrawTextD2D(Vector2(-300, 0), buffer, 20, 1.0f, ColorF::Red, DWRITE_TEXT_ALIGNMENT_LEADING, L"¸¼Àº°íµñ", false);
	test->Render();
	UiManager::getSingleton()->Render();
}

