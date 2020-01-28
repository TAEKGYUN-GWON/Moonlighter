#include "stdafx.h"
#include "StartScene.h"
#include "DungeonScene.h"
#include "EntranceScene.h"
#include "ShopScene.h"
#include "TownScene.h"
#include "Maptool.h"
#include "TestScene.h"

void StartScene::Init()
{
	Scene::Init();
	SCENEMANAGER->addScene("Dungeon", new DungeonScene);
	SCENEMANAGER->addScene("Town", new TownScene);
	SCENEMANAGER->addScene("Entrance", new EntranceScene);
	SCENEMANAGER->addScene("Shop", new ShopScene);
	SCENEMANAGER->addScene("Maptool", new Maptool);
	SCENEMANAGER->addScene("test", new TestScene);
	GraphicsManager::getSingleton()->AddImage("dd", L"eagle.png");
	GraphicsManager::getSingleton()->AddFrameImage("d2", L"fatkachu.png",4,1);
	GRAPHICMANAGER->AddFrameImage("bn", L"blueNumber.png", 4, 1);

	GRAPHICMANAGER->AddImage("coin", L"resource/img/UI/coin.png");
	GRAPHICMANAGER->AddImage("moneyBag", L"resource/img/UI/moneyBag.png");
	GRAPHICMANAGER->AddImage("UI_Bag", L"resource/img/UI/UI_Bag.png");
	GRAPHICMANAGER->AddImage("UI_Potion", L"resource/img/UI/UI_Potion.png");
	GRAPHICMANAGER->AddImage("heart", L"resource/img/UI/heart.png");
	GRAPHICMANAGER->AddImage("heart", L"resource/img/UI/heart.png");
	GRAPHICMANAGER->AddFrameImage("UI_WeaponSwap", L"resource/img/UI/UI_WeaponSwap.png", 4, 2);

	//ui = new UiManager;
	//ui->Init();
	inven = new Inventory;
	inven->Init();
	//ui->SetInvenLink(inven);

	obj = Object::CreateObject<Object>();
	obj->GetTrans()->SetPos(Vector2(WINSIZEX / 2, 200));
	obj->AddComponent<Sprite>()->Init();
	obj->GetComponent<Sprite>()->SetImgName("dd");
	obj->GetComponent<Sprite>()->SetPosition(obj->GetTrans()->GetPos());
	auto a = GRAPHICMANAGER->FindImage("dd");
	obj->GetComponent<Sprite>()->SetSize(Vector2(a->GetFrameWidth(), a->GetFrameHeight()));
	//obj->GetTrans()->SetScale(Vector2(obj->GetComponent<Sprite>()->GetGraphic()->GetFrameWidth(), obj->GetComponent<Sprite>()->GetGraphic()->GetFrameWidth()));
	obj->GetTrans()->SetScale(Vector2(100, 50));
}

void StartScene::Update()
{
	Scene::Update();
	if (KEYMANAGER->isOnceKeyDown('1'))
	{
		SCENEMANAGER->changeScene("Dungeon");
	}
	if (KEYMANAGER->isOnceKeyDown('2')) SCENEMANAGER->changeScene("Town");
	if (KEYMANAGER->isOnceKeyDown('3')) SCENEMANAGER->changeScene("Entrance");
	if (KEYMANAGER->isOnceKeyDown('4')) SCENEMANAGER->changeScene("Shop");
	if (KEYMANAGER->isOnceKeyDown('5')) SCENEMANAGER->changeScene("Maptool");
	if (KEYMANAGER->isOnceKeyDown('0')) SCENEMANAGER->changeScene("test");
	inven->Update();
}

void StartScene::Render()
{
	Scene::Render();

	GRAPHICMANAGER->Text(Vector2(100, 100), L"1) Dungeon Scene", 20, 300, 50, ColorF::AliceBlue);
	GRAPHICMANAGER->Text(Vector2(100, 150), L"2) Town Scene", 20, 300, 50, ColorF::AntiqueWhite);
	GRAPHICMANAGER->Text(Vector2(100, 200), L"3) Entrance Scene", 20, 300, 50, ColorF::Aqua);
	GRAPHICMANAGER->Text(Vector2(100, 250), L"4) Shop Scene", 20, 300, 50, ColorF::Aquamarine);
	GRAPHICMANAGER->Text(Vector2(100, 300), L"5) Maptool Scene", 20, 300, 50, ColorF::Azure);

	wchar_t buffer[128];
	swprintf(buffer, 128, L"Camera X : %f\nCamera Y : %f", CAMERA->GetPosition().x, CAMERA->GetPosition().y);
	GRAPHICMANAGER->Text(Vector2(WINSIZEX/2, 100), buffer, 20, 300, 50, ColorF::Azure);

	GRAPHICMANAGER->DrawFrameImage("bn", Vector2(WINSIZEX / 2, 400), 0, 0, Vector2(320, 50));
	GRAPHICMANAGER->DrawFrameImage("bn", Vector2(WINSIZEX / 2, 460), 1, 0, Vector2(320, 50));
	GRAPHICMANAGER->DrawFrameImage("bn", Vector2(WINSIZEX / 2, 520), 2, 0, Vector2(320, 50));
	GRAPHICMANAGER->DrawFrameImage("bn", Vector2(WINSIZEX / 2, 580), 3, 0, Vector2(320, 50));

	GRAPHICMANAGER->DrawRect(Vector2(WINSIZEX / 2, 400), Vector2(80, 50), 0.0f, ColorF::Red);
	GRAPHICMANAGER->DrawRect(Vector2(WINSIZEX / 2, 460), Vector2(80, 50), 0.0f, ColorF::Red);
	GRAPHICMANAGER->DrawRect(Vector2(WINSIZEX / 2, 520), Vector2(80, 50), 0.0f, ColorF::Red);
	GRAPHICMANAGER->DrawRect(Vector2(WINSIZEX / 2, 580), Vector2(80, 50), 0.0f, ColorF::Red);

	//swprintf(buffer, 128, L"test X : %f\test Y : %f", test->GetTrans()->GetPos().x, test->GetTrans()->GetPos().y);
	//GRAPHICMANAGER->Text(Vector2(WINSIZEX / 2, 400), buffer, 20, 300, 50, ColorF::Azure);
	//ui->Render();
	inven->Render();
}

