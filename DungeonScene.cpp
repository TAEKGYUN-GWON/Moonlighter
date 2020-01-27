#include "stdafx.h"
#include "DungeonScene.h"
#include "EntranceScene.h"
#include "TownScene.h"
#include "Hp.h"

void DungeonScene::Init()
{
	Scene::Init();

	cout << "´øÀü¾Àµé¾î¿È" << endl;
	SCENEMANAGER->addScene("Entrance", new EntranceScene);
	SCENEMANAGER->addScene("Town", new TownScene);



	_player = Object::CreateObject<Player>();
	_player->Init();
	//_player->GetHP()->GetCurrentHP();

	_player = (Player*)SCENEMANAGER->GetNowScene()->GetChildFromName("will");
	_dMgr = new DungeonMgr;
	_dMgr->Init();
}

void DungeonScene::Update()
{
	Scene::Update();
	if (KEYMANAGER->isOnceKeyDown('T'))
	{
		
		_player->GetTrans()->SetPos(Vector2(WINSIZEX / 2, WINSIZEY - 100));
		_player->GetComponent<PhysicsBody>()->SetBodyPosition();
	}
	_dMgr->Update();
}

void DungeonScene::Render()
{
	_dMgr->Render();
	Scene::Render();
	GRAPHICMANAGER->Text(Vector2(10, 6), L"Dungeon Scene", 20, 200, 30, ColorF::AliceBlue);

	wchar_t buffer[128];
	swprintf(buffer, 128, L"Fps : %f", TIMEMANAGER->GetFps());

	GRAPHICMANAGER->Text(Vector2(WINSIZEX / 2, 100), buffer, 20, 300, 50, ColorF::Azure);
	//wchar_t buffer[128];
	//swprintf(buffer, 128, L"c : %d", GetChildren().size());

	//GRAPHICMANAGER->Text(Vector2(WINSIZEX / 2, 200), buffer, 20, 300, 50, ColorF::Azure);


	GRAPHICMANAGER->Text(Vector2(10, 6), L"Dungeon Scene", 20, 200, 30, ColorF::AliceBlue);
}
