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

	_dungeon = new Dungeon;
	_dungeon->Init();
	_player = Object::CreateObject<Player>();
	_player->Init();
	//_player->GetHP()->GetCurrentHP();

	_enemy = Object:: CreateObject<Enemy>();
	_enemy->Init();

	_player = (Player*)SCENEMANAGER->GetNowScene()->GetChildFromName("will");
}

void DungeonScene::Update()
{
	Scene::Update();



	if (KEYMANAGER->isOnceKeyDown('T'))
	{
		_dungeon->Release();
		_dungeon = new Dungeon;
		_dungeon->Init();
		_player->GetTrans()->SetPos(Vector2(WINSIZEX / 2, WINSIZEY - 100));
		_player->GetComponent<PhysicsBody>()->SetBodyPosition();
	}
	_dungeon->Update();
}

void DungeonScene::Render()
{
	_dungeon->Render();
	Scene::Render();
	GRAPHICMANAGER->Text(Vector2(10, 6), L"Dungeon Scene", 20, 200, 30, ColorF::AliceBlue);
}
