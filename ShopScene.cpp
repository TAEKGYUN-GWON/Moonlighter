#include "stdafx.h"
#include "ShopScene.h"
#include "Inventory.h"

void ShopScene::Init()
{
	Scene::Init();

	_name = "Shop";

	GRAPHICMANAGER->AddImage("ShopBg", L"resource/img/Shop/shop_background.png");
	GRAPHICMANAGER->AddImage("empty", L"resource/img/empty.png");
	GRAPHICMANAGER->AddFrameImage("Girl", L"resource/img/Shop/Girl.png", 9, 4);
	GRAPHICMANAGER->AddFrameImage("Guy", L"resource/img/Shop/Guy.png", 9, 4);
	GRAPHICMANAGER->AddFrameImage("Kid", L"resource/img/Shop/Kids.png", 6, 4);
	GRAPHICMANAGER->AddFrameImage("Lunk", L"resource/img/Shop/Lunk.png", 9, 4);
	GRAPHICMANAGER->AddFrameImage("Door", L"resource/img/Shop/shop_door.png", 5, 1);

	_player = Object::CreateObject<Player>();
	_player->Init();

	//계산대
	_checkStand = Object::CreateObject<CheckStand>();
	_checkStand->Init();
	
	//가판대 쇼케이스
	_shopStandMgr = new ShopStandManager; //가판대
	_shopStandMgr->Init();

	SetUp();
	_npcMgr = new NpcManager; //NPC CreateObject는 NpcManager에서 해준다.
	_npcMgr->SetCheckStandLink(_checkStand); //이게 npcmanager를 거쳐서 state로 간다
	_npcMgr->SetShopStandMgrLink(_shopStandMgr); //엔피씨가 충돌할 스탠드는 이것이다
	_npcMgr->Init(this);

	//_checkStand->SetNpc(_npcMgr->GetNpcVector());
	_shopDoor = Object::CreateObject<ShopDoor>();
	_shopDoor->Init();
	

}

void ShopScene::Release()
{
	_npcMgr->Release(); //비어있음
	

	Scene::Release();
}

void ShopScene::Update()
{
	_npcMgr->Update();
	_shopDoor->Update();

	if (KEYMANAGER->isOnceKeyDown('1')) SCENEMANAGER->changeScene("Dungeon");
	if (KEYMANAGER->isOnceKeyDown('2')) SCENEMANAGER->changeScene("Entrance");
	if (KEYMANAGER->isOnceKeyDown('3')) SCENEMANAGER->changeScene("Town");
	if (KEYMANAGER->isOnceKeyDown('4')) SCENEMANAGER->changeScene("Shop");
	if (KEYMANAGER->isOnceKeyDown('5')) SCENEMANAGER->changeScene("Maptool");
	
	Scene::Update();
}

void ShopScene::Render()
{
	GRAPHICMANAGER->FindImage("ShopBg")->Render(0, 0, LEFT_TOP);

	Scene::Render();

	//창가 동그라미
	GRAPHICMANAGER->DrawEllipse(520, 615, 30, 30);

	//마우스 좌표
	wchar_t buffer[128];
	swprintf(buffer, 128, L"x: %d, y:%d", 
		(int)(_ptMouse.x+CAMERA->GetPosition().x) / TILEWIDTH, 
		(int)(_ptMouse.y+CAMERA->GetPosition().y) / TILEHEIGHT);
	GRAPHICMANAGER->Text(Vector2(WINSIZEX / 2, WINSIZEY / 2), buffer, 20, 500, 300, ColorF::White);

	swprintf(buffer, 128, L"x: %f, y:%f", _ptMouse.x + CAMERA->GetPosition().x, _ptMouse.y + CAMERA->GetPosition().y);
	GRAPHICMANAGER->Text(Vector2(WINSIZEX / 2, WINSIZEY / 2 - 100), buffer, 20, 500, 300, ColorF::White);

	// npc 상태 표시
	if (_npcMgr->GetNpcVector().size())
	{
		if (_npcMgr->GetNpcVector()[0]->GetStatePointer()->GetState() == "Idle")
		{
			GRAPHICMANAGER->Text(Vector2(WINSIZEX / 2, 200), L"Idle", 20, 100, 30, ColorF::AntiqueWhite);
		}
		else if (_npcMgr->GetNpcVector()[0]->GetStatePointer()->GetState() == "Move")
		{
			GRAPHICMANAGER->Text(Vector2(WINSIZEX / 2, 200), L"Decide", 20, 100, 30, ColorF::AntiqueWhite);
		}
	}

	_player->GetInventory()->Render();
}

void ShopScene::SetUp()
{
	
	for (int i = 0; i < SHOPTILEMAXY; ++i)
	{
		for (int j = 0; j < SHOPTILEMAXX; ++j)
		{
			int index = j + SHOPTILEMAXX * i;

			Tile* tile = Object::CreateObject<Tile>();
			tile->Init(j, i);
			tile->AddComponent<Sprite>();
			tile->SetAttribute("None");
			_tiles.push_back(tile);

			_tagTiles[index].attribute = "None";
			_tagTiles[index].imgKey = "None";
			_tagTiles[index].isFrame = false;
			_tagTiles[index].pivot = PIVOT::CENTER;
		}
	}

	HANDLE file;
	DWORD read;

	string str = "shop.map";

	//file = CreateFile(titleLoad, GENERIC_READ, 0, NULL,
	file = CreateFile(str.c_str(), GENERIC_READ, 0, NULL,
		OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

	if (file != INVALID_HANDLE_VALUE)
	{
		//MessageBox(_hWnd, "load 한다", str.c_str(), MB_OK);

		ReadFile(file, _tagTiles, sizeof(tagTile) * SHOPTILEMAXX * SHOPTILEMAXY, &read, NULL);
		CloseHandle(file);

		for (int i = 0; i < SHOPTILEMAXX * SHOPTILEMAXY; i++)
		{
			// _tiles[] initialization
			_tiles[i]->SetImgName("None");
			_tiles[i]->SetAttribute("None");
			_tiles[i]->SetIsFrame(false);
			_tiles[i]->SetPivot(PIVOT::CENTER);

			if (_tiles[i]->GetChildren().size() > 0) _tiles[i]->RemoveChild(_tiles[i]->GetChildren()[0]);


			// value setting
			_tiles[i]->SetAttribute(_tagTiles[i].attribute);
			_tiles[i]->SetImgName(_tagTiles[i].imgKey);
			_tiles[i]->SetIsFrame(_tagTiles[i].isFrame);
			_tiles[i]->SetPivot(_tagTiles[i].pivot);


			if (_tiles[i]->GetImgName() != "None")
			{
				_tiles[i]->AddChild(Object::CreateObject<Object>());

				_tiles[i]->GetChildren()[0]->GetTrans()->SetPos(_tiles[i]->GetTrans()->GetPos() + Vector2(0, TILEHEIGHT / 2));
				if (_tiles[i]->GetPivot() == RIGHT_BOTTOM) _tiles[i]->GetChildren()[0]->GetTrans()->SetPos(_tiles[i]->GetTrans()->GetPos() + Vector2(TILEWIDTH / 2, TILEHEIGHT / 2));

				_tiles[i]->GetChildren()[0]->GetTrans()->SetScale(GRAPHICMANAGER->FindImage(_tiles[i]->GetImgName())->GetFrameWidth(), GRAPHICMANAGER->FindImage(_tiles[i]->GetImgName())->GetFrameHeight());
				_tiles[i]->GetChildren()[0]->GetTrans()->SetRect();

				if (_tiles[i]->GetIsFrame())
				{
					_tiles[i]->GetChildren()[0]->AddComponent<Sprite>()->Init(true, true);
					_tiles[i]->GetChildren()[0]->GetComponent<Sprite>()->SetImgName(_tiles[i]->GetImgName());
					_tiles[i]->GetChildren()[0]->GetComponent<Sprite>()->SetFPS(0.5f);
					_tiles[i]->GetChildren()[0]->GetComponent<Sprite>()->SetPivot(_tiles[i]->GetPivot());
				}
				else
				{
					_tiles[i]->GetChildren()[0]->AddComponent<Sprite>()->SetImgName(_tiles[i]->GetImgName());
					_tiles[i]->GetChildren()[0]->GetComponent<Sprite>()->SetPivot(_tiles[i]->GetPivot());
				}

				_tiles[i]->GetChildren()[0]->GetComponent<Sprite>()->SetPosition(_tiles[i]->GetChildren()[0]->GetTrans()->GetPos());
				_tiles[i]->GetChildren()[0]->GetComponent<Sprite>()->SetSize(_tiles[i]->GetChildren()[0]->GetTrans()->GetScale());
			}
		}
	}
	else MessageBox(_hWnd, "can not found the file.", str.c_str(), MB_OK);

}

