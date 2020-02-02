#include "stdafx.h"
#include "TownScene.h"
#include"Inventory.h"

void TownScene::Init()
{
	Scene::Init();

#pragma region SetTilePage1
	GRAPHICMANAGER->AddImage("build_fountain", L"resource/img/Object/build_fountain.png");
	GRAPHICMANAGER->AddImage("build_Retaile", L"resource/img/Object/build_Retaile.png");
	GRAPHICMANAGER->AddImage("build_Shop", L"resource/img/Object/build_Shop.png");
	GRAPHICMANAGER->AddImage("build_Top1", L"resource/img/Object/build_Top1.png");
	GRAPHICMANAGER->AddImage("build_Well", L"resource/img/Object/build_Well.png");

	GRAPHICMANAGER->AddFrameImage("door", L"resource/img/Object/door.png", 5, 1);
	GRAPHICMANAGER->AddFrameImage("doordown", L"resource/img/Object/doordown.png", 5, 1);

	GRAPHICMANAGER->AddImage("dgLobbyEntry", L"resource/img/Object/dgLobbyEntry.png");
	GRAPHICMANAGER->AddImage("dgLobbyLeft", L"resource/img/Object/dgLobbyLeft.png");
	GRAPHICMANAGER->AddImage("dgLobbyRight", L"resource/img/Object/dgLobbyRight.png");
	GRAPHICMANAGER->AddImage("build_Bottom3", L"resource/img/Object/build_Bottom3.png");
	GRAPHICMANAGER->AddImage("bench", L"resource/img/Object/bench.png");
	GRAPHICMANAGER->AddImage("buildBoard", L"resource/img/Object/buildBoard.png");
	GRAPHICMANAGER->AddImage("build_Bottom1", L"resource/img/Object/build_Bottom1.png");
	GRAPHICMANAGER->AddImage("build_Bottom2", L"resource/img/Object/build_Bottom2.png");
	GRAPHICMANAGER->AddImage("VillageLamps1", L"resource/img/Object/VillageLamps1.png");
	GRAPHICMANAGER->AddImage("build_Enchant", L"resource/img/Object/build_Enchant.png");
	GRAPHICMANAGER->AddImage("VillageLamps2", L"resource/img/Object/VillageLamps2.png");

	GRAPHICMANAGER->AddFrameImage("tree", L"resource/img/Object/tree.png", 4, 1);

	GRAPHICMANAGER->AddImage("build_Forge", L"resource/img/Object/build_Forge.png");
	GRAPHICMANAGER->AddImage("dungeonRock", L"resource/img/Object/dungeonRock.png");
	GRAPHICMANAGER->AddImage("forgeBoard", L"resource/img/Object/forgeBoard.png");
	GRAPHICMANAGER->AddImage("potionBoard", L"resource/img/Object/potionBoard.png");
	GRAPHICMANAGER->AddImage("empty", L"resource/img/empty.png");
#pragma endregion

	GRAPHICMANAGER->AddImage("town_map", L"resource/img/Map/map.png");

	GRAPHICMANAGER->AddFrameImage("set_tile", L"set_tile3.png", 4, 6);
	GRAPHICMANAGER->AddFrameImage("set_tile_dungeon", L"set_tile_dungeon.png", 4, 6);

	_smith = GRAPHICMANAGER->AddFrameImage("Smith", L"resource/img/Smithy/Smith_Dott.png", 4, 1);

	_j = GRAPHICMANAGER->AddImage("j", L"resource/img/Smithy/J.png");



	_frameCount = _frameX = 0;

	SetUp();

	_player = Object::CreateObject<Player>();
	_player->Init();

	_player->GetTrans()->SetPos(Vector2(2000, 1500));

	_player->GetPhysics()->SetBodyPosition();

	_player->GetSprite()->SetPosition(_player->GetTrans()->GetPos() + Vector2(0,-14));

	

	_smithy = new Smithy;
	_smithy->Init(_player->GetInventory());



	//_smithy->SetSmithPos(_smith->GetTrans()->GetPos());

}

void TownScene::Update()
{
	Scene::Update();

	_smithy->Update();

	_frameCount++;
	if (_frameCount >= 5)
	{
		_frameX++;
		//_frameCount = 0;

		if (_frameX >= 4)
			_frameX = 0;
	}

	CAMERA->SetPos(Vector2(_player->GetTrans()->GetPos().x - 650, _player->GetTrans()->GetPos().y - 450));
}

void TownScene::SetUp()
{
	for (int i = 0; i < TILENUMY; ++i)
	{
		for (int j = 0; j < TILENUMX; ++j)
		{
			int index = j + TILENUMX * i;

			_tiles[index] = Object::CreateObject<Tile>();
			_tiles[index]->Init(j, i);
			_tiles[index]->AddComponent<Sprite>();
			_tiles[index]->SetAttribute("None");

			

			_tagTiles[index].attribute = "None";
			_tagTiles[index].imgKey = "None";
			_tagTiles[index].isFrame = false;
			_tagTiles[index].pivot = PIVOT::CENTER;

		}
	}


	HANDLE file;
	DWORD read;

	//string str = titleLoad;
	//str += ".map";
	string str = "Town.map";

	//file = CreateFile(titleLoad, GENERIC_READ, 0, NULL,
	file = CreateFile(str.c_str(), GENERIC_READ, 0, NULL,
		OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

	if (file != INVALID_HANDLE_VALUE)
	{
		//MessageBox(_hWnd, "load วัดู", str.c_str(), MB_OK);

		ReadFile(file, _tagTiles, sizeof(tagTile) * TILENUMX * TILENUMY, &read, NULL);
		CloseHandle(file);

		for (int i = 0; i < TILENUMX * TILENUMY; i++)
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

void TownScene::Render()
{
	GRAPHICMANAGER->DrawImage("town_map", Vector2(0, 0), 1.0f, LEFT_TOP, true);


	Scene::Render();

	_player->GetInventory()->Render();

	_smithy->Render();

	if (!_smithy->GetSmithy())
	{
		_smith->FrameRender(Vector2(2470, 1080), _frameX, 1, PIVOT::CENTER);

		if (ShowJ())
		{
			_j->Render(Vector2(2520, 1040), 1.f, PIVOT::CENTER, true);
		}
	}

	if (_smithy->GetSmithy())
	{
		if (!(_player->GetTrans()->GetPos().x > 2470 - 200 && _player->GetTrans()->GetPos().y >= 1080
			&& _player->GetTrans()->GetPos().x < 2470 + 200 && _player->GetTrans()->GetPos().y <= 1080 + 200))
		{
			_smithy->SetShow(false);
		}
	}

	 
}

bool TownScene::ShowJ()
{

	if (_player->GetTrans()->GetPos().x > 2470 - 200 && _player->GetTrans()->GetPos().y >= 1080
		&& _player->GetTrans()->GetPos().x < 2470 + 200 && _player->GetTrans()->GetPos().y <= 1080 + 250)
	{
		_smithy->SetIn(true);
		return true;
	}
	else
	{
		_smithy->SetIn(false);
		return false;
	}
}

void TownScene::CreateNPC()
{
	Npc* npc;

	for (int i = 0; i < _vNpc.size(); i++)
	{
		if (_vNpc[i]->GetName() != "girl")
		{
			npc->Init("Girl");
			npc->SetName("girl");
			_vNpc.push_back(npc);
			return;
		}
		else if (_vNpc[i]->GetName() != "guy")
		{
			npc->Init("Guy");
			npc->SetName("guy");
			_vNpc.push_back(npc);
			return;
		}
		else if (_vNpc[i]->GetName() != "kid")
		{
			npc->Init("Kid");
			npc->SetName("kid");
			_vNpc.push_back(npc);
			return;
		}
		else if (_vNpc[i]->GetName() != "lunk")
		{
			npc->Init("Lunk");
			npc->SetName("lunk");
			_vNpc.push_back(npc);
			return;
		}
	}
}
