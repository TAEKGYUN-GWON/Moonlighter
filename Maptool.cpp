#include "stdafx.h"
#include "Maptool.h"

void Maptool::Init()
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

	GRAPHICMANAGER->AddImage("dungeonLobby_entryStructure", L"resource/img/Object/dungeonLobby_entryStructure.png");
	GRAPHICMANAGER->AddImage("dungeonLobby_entryStructureLeft", L"resource/img/Object/dungeonLobby_entryStructureLeft.png");
	GRAPHICMANAGER->AddImage("dungeonLobby_entryStructureRight", L"resource/img/Object/dungeonLobby_entryStructureRight.png");
	GRAPHICMANAGER->AddImage("build_Bottom3", L"resource/img/Object/build_Bottom3.png");
	GRAPHICMANAGER->AddImage("bench", L"resource/img/Object/bench.png");
	GRAPHICMANAGER->AddImage("build_Board", L"resource/img/Object/build_Board.png");
	GRAPHICMANAGER->AddImage("build_Bottom1", L"resource/img/Object/build_Bottom1.png");
	GRAPHICMANAGER->AddImage("build_Bottom2", L"resource/img/Object/build_Bottom2.png");
	GRAPHICMANAGER->AddImage("Village_OilLamps_1", L"resource/img/Object/Village_OilLamps_1.png");
	GRAPHICMANAGER->AddImage("build_Enchant", L"resource/img/Object/build_Enchant.png");
	GRAPHICMANAGER->AddImage("Village_OilLamps_2", L"resource/img/Object/Village_OilLamps_2.png");

	GRAPHICMANAGER->AddFrameImage("tree", L"resource/img/Object/tree.png", 4, 1);

	GRAPHICMANAGER->AddImage("build_Forge", L"resource/img/Object/build_Forge.png");
	GRAPHICMANAGER->AddImage("dungeonLobby_middleRighttRock", L"resource/img/Object/dungeonLobby_middleRighttRock.png");
	GRAPHICMANAGER->AddImage("forgeBoard", L"resource/img/Object/forgeBoard.png");
	GRAPHICMANAGER->AddImage("potionBoard", L"resource/img/Object/potionBoard.png");
	GRAPHICMANAGER->AddImage("empty", L"resource/img/empty.png");
#pragma endregion

#pragma region SetTilePage2
	GRAPHICMANAGER->AddImage("smallRock", L"resource/img/Object/smallRock.png");
	GRAPHICMANAGER->AddImage("smallRock_slime", L"resource/img/Object/smallRock_slime.png");
	GRAPHICMANAGER->AddImage("bigRock", L"resource/img/Object/bigRock.png");
	GRAPHICMANAGER->AddImage("book", L"resource/img/Object/book.png");
	GRAPHICMANAGER->AddImage("pot", L"resource/img/Object/pot.png");
	GRAPHICMANAGER->AddImage("pot_slime", L"resource/img/Object/pot_slime.png");
	GRAPHICMANAGER->AddImage("lathe", L"resource/img/Object/lathe.png");
	GRAPHICMANAGER->AddImage("fountain", L"resource/img/Object/fountain.png");
	GRAPHICMANAGER->AddImage("pillar", L"resource/img/Object/pillar.png");
	GRAPHICMANAGER->AddImage("skull1", L"resource/img/Object/skull1.png");
	GRAPHICMANAGER->AddImage("skull2", L"resource/img/Object/skull2.png");
	GRAPHICMANAGER->AddImage("skull3", L"resource/img/Object/skull3.png");
	GRAPHICMANAGER->AddImage("brokenPillar", L"resource/img/Object/brokenPillar.png");
#pragma endregion

	GRAPHICMANAGER->AddFrameImage("set_tile", L"set_tile3.png", 4, 6);
	GRAPHICMANAGER->AddFrameImage("set_tile_dungeon", L"set_tile_dungeon.png", 4, 6);
	GRAPHICMANAGER->AddFrameImage("will_dungeon", L"will_dungeon.png", 10, 13);

	_page = SamplePage::TOWN;

	SetUp();

	_isDown = false;

	_curFrameX = _curFrameY = 0;

	p = Object::CreateObject<Player>();
	p->Init();
	p->GetSprite()->Init(true);
	p->GetSprite()->SetImgName("will_dungeon");
	p->GetSprite()->SetFrameY(1);
	p->GetSprite()->Stop();
	p->GetSprite()->SetCameraAffect(false);

	_rcLoad = RectMakeCenter(WINSIZEX - 100, WINSIZEY - 100, 100, 30);
	_rcSave = RectMakeCenter(WINSIZEX - 100, WINSIZEY - 150, 100, 30);
}

void Maptool::Update()
{
	Scene::Update();

	if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
	{
		if (PtInRect(&_rcLoad, _ptMouse))
		{
			OPENFILENAME ofn;
			char filePathSize[1028] = "";
			ZeroMemory(&ofn, sizeof(OPENFILENAME));

			ofn.lStructSize = sizeof(OPENFILENAME);
			ofn.hwndOwner = NULL;
			ofn.lpstrFile = filePathSize;
			ofn.nMaxFile = sizeof(filePathSize);
			ofn.nFilterIndex = true;
			ofn.lpstrFileTitle = NULL;
			ofn.nMaxFileTitle = NULL;
			ofn.lpstrInitialDir = NULL;
			ofn.lpstrFilter = ("음악파일만넣어줘라");
			ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;

			if (GetOpenFileName(&ofn) == FALSE) return;

			char temp[1028];
			strncpy_s(temp, strlen(ofn.lpstrFile) + 1, ofn.lpstrFile, strlen(ofn.lpstrFile));

			char* context = NULL;
			char* token = strtok_s(temp, "\\", &context);

			while (strlen(context))
			{
				token = strtok_s(NULL, "\\", &context);
			}

			char* title = token;
			token = strtok_s(title, ".", &context);
		}
		if (PtInRect(&_rcSave, _ptMouse))
		{
			OPENFILENAME ofn;
			char filePathSize[1028] = "";
			//TCHAR filter[] = "Every file(*.*) \0*.*\0TextFile\0*.txt;*.doc\0";
			//TCHAR filter[] = "Every file(*.*) \0*.*\0TextFile\0*.txt;*.doc\0맵(.map)\0*.map\0";
			char filter[1028] = "Every file(*.*) \0*.*\0TextFile\0*.txt;*.doc\0맵(.map)\0*.map\0";

			ZeroMemory(&ofn, sizeof(OPENFILENAME));

			ofn.lStructSize = sizeof(OPENFILENAME);
			ofn.hwndOwner = NULL;
			//ofn.lpstrFile = filePathSize;
			ofn.lpstrFile = filter;
			ofn.nMaxFile = sizeof(filePathSize);
			ofn.nFilterIndex = true;
			ofn.lpstrFileTitle = NULL;
			ofn.nMaxFileTitle = NULL;
			ofn.lpstrInitialDir = NULL;
			ofn.lpstrFilter = filter;
			ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;

			if (GetSaveFileName(&ofn) == FALSE) return;
		}
	}

	if (KEYMANAGER->isStayKeyDown(VK_LBUTTON))
	{
		if (PtInRect(&_btn1->GetTrans()->GetRect(), _ptMouse))
		{
			_currentTile.imgKey = "empty";
			_currentTile.isFrame = false;
			_currentTile.size = Vector2(1, 1);
			//_currentTile.vSize[0] = Vector2(1, 1);
			_ctrSelect = Attribute::NONE_MOVE;
			//return;
		}

		SetMap();
	}

	//// 렉트 충돌부분 색 변하게 해주는 거
	//RECT temp;
	//for (int i = 0; i < TILENUMX * TILENUMY; ++i)
	//{
	//	//if ((_ptMouse.x <= WINSIZEX - 300) && PtInRect(&RectMakeCenter(_tiles[i]->GetTrans()->GetPos().x - CAMERA->GetPosition().x, _tiles[i]->GetTrans()->GetPos().y - CAMERA->GetPosition().y, TILEWIDTH, TILEHEIGHT), _ptMouse))
	//	if ((_ptMouse.x <= WINSIZEX - 300) && IntersectRect(&temp, &RectMakeCenter(_tiles[i]->GetTrans()->GetPos().x - CAMERA->GetPosition().x, _tiles[i]->GetTrans()->GetPos().y - CAMERA->GetPosition().y, TILEWIDTH, TILEHEIGHT), &RectMakeBottomCenter(_ptMouse.x, _ptMouse.y, _currentTile.colSize.x, _currentTile.colSize.y)))
	//	{
	//		//if (_tiles[i]->GetChildren().size() > 0) return;
	//
	//		_tiles[i]->GetComponent<Sprite>()->SetFillRect(true);
	//
	//		continue;
	//	}
	//	else
	//	{
	//		_tiles[i]->GetComponent<Sprite>()->SetFillRect(false);
	//	}
	//}

	//RECT temp;
	//for (int i = 0; i < TILENUMX * TILENUMY; ++i)
	//{
	//	if ((_ptMouse.x <= WINSIZEX - 300) && PtInRect(&RectMakeCenter(_tiles[i]->GetTrans()->GetPos().x - CAMERA->GetPosition().x, _tiles[i]->GetTrans()->GetPos().y - CAMERA->GetPosition().y, TILEWIDTH, TILEHEIGHT), _ptMouse))
	//	//if ((_ptMouse.x <= WINSIZEX - 300) && IntersectRect(&temp, &RectMakeCenter(_tiles[i]->GetTrans()->GetPos().x - CAMERA->GetPosition().x, _tiles[i]->GetTrans()->GetPos().y - CAMERA->GetPosition().y, TILEWIDTH, TILEHEIGHT), &RectMakeBottomCenter(_ptMouse.x, _ptMouse.y, _currentTile.colSize.x, _currentTile.colSize.y)))
	//	{
	//		//if (_tiles[i]->GetChildren().size() > 0) return;
	//
	//		_tiles[i]->GetComponent<Sprite>()->SetFillRect(true);
	//
	//		continue;
	//	}
	//	else
	//	{
	//		_tiles[i]->GetComponent<Sprite>()->SetFillRect(false);
	//	}
	//}

	if (KEYMANAGER->isStayKeyDown(VK_RBUTTON))
	{
		RemoveObject();
	}

	if (KEYMANAGER->isOnceKeyUp('1'))
	{
		_page = SamplePage::TOWN;
		SetPage();
	}
	if (KEYMANAGER->isOnceKeyUp('2'))
	{
		_page = SamplePage::DONGEON;
		SetPage();
	}
}

void Maptool::Render()
{
	Scene::Render();

	char buffer[128];
	for (int i = 0; i < 25; ++i)
	{
		for (int j = 0; j < 33; ++j)
		{
			int cullX = CAMERA->GetPosition().x / TILEWIDTH;
			int cullY = CAMERA->GetPosition().y / TILEHEIGHT;

			int index = (i + cullY) * TILENUMX + (j + cullX);

			if (index < 0 || index >= TILENUMX * TILENUMY) continue;

			if (_tiles[index]->GetAttribute() == "Wall") _tiles[index]->GetComponent<Sprite>()->SetFillRect(true);
			else if(_tiles[index]->GetAttribute() != "Wall") _tiles[index]->GetComponent<Sprite>()->SetFillRect(false);

			if (_tiles[index]->GetChildren().size() > 0) _tiles[index]->GetChildren()[0]->Render();
			sprintf_s(buffer, "%d", index);
			GRAPHICMANAGER->DrawTextD2D(_tiles[index]->GetTrans()->GetPos() + Vector2(-(TILEWIDTH / 2) + 2, TILEHEIGHT / 7), buffer, 10, 1.0f, ColorF::Yellow);
		}
	}

	GRAPHICMANAGER->DrawFillRect(Vector2(WINSIZEX - 150, WINSIZEY / 2), Vector2(300, WINSIZEY), 0.0f, ColorF::Aquamarine, 1.0f, CENTER, false);
	
	for (int i = 0; i < SAMPLE_TILE_X_NUM * SAMPLE_TILE_Y_NUM; ++i)
	{
		GRAPHICMANAGER->DrawRect(Vector2(_sampleTile[i].pos.x, _sampleTile[i].pos.y), Vector2(SET_TILEWIDTH, SET_TILEHEIGHT), 0.0f, ColorF::White, PIVOT::CENTER, 1.0f, false);
	}

	//GRAPHICMANAGER->DrawImage("set_tile", Vector2(WINSIZEX - 150, 30), 1.0f,  PIVOT::TOP, false);
	switch (_page)
	{
	case TOWN: GRAPHICMANAGER->DrawImage("set_tile", Vector2(WINSIZEX - 150, 30), 1.0f, PIVOT::TOP, false); break;
	case DONGEON: GRAPHICMANAGER->DrawImage("set_tile_dungeon", Vector2(WINSIZEX - 150, 30), 1.0f, PIVOT::TOP, false); break;
	}

	_btn1->Render();

	if (_currentTile.isFrame)
	{
		GRAPHICMANAGER->DrawFrameImage(_currentTile.imgKey, _ptMouse, 0, 0, 0.85f, _currentTile.pivot, false);
		
		// FIXME : 다시 보자
		GRAPHICMANAGER->DrawRect(_ptMouse, Vector2(_currentTile.size.x * TILEWIDTH, _currentTile.size.y * TILEHEIGHT), 0.0f, ColorF::Red, _currentTile.pivot, 1.0f, false);
		//GRAPHICMANAGER->DrawRect(_ptMouse, Vector2(_currentTile.vSize[0].x * TILEWIDTH, _currentTile.vSize[0].y * TILEHEIGHT), 0.0f, ColorF::Red, _currentTile.pivot, 1.0f, false);
	}
	else
	{
		GRAPHICMANAGER->DrawImage(_currentTile.imgKey, _ptMouse, 0.85f, _currentTile.pivot, false);
		
		// FIXME : 다시 보자
		GRAPHICMANAGER->DrawRect(_ptMouse, Vector2(_currentTile.size.x * TILEWIDTH, _currentTile.size.y * TILEHEIGHT), 0.0f, ColorF::Red, _currentTile.pivot, 1.0f, false);
		//GRAPHICMANAGER->DrawRect(_ptMouse, Vector2(_currentTile.vSize[0].x * TILEWIDTH, _currentTile.vSize[0].y * TILEHEIGHT), 0.0f, ColorF::Red, _currentTile.pivot, 1.0f, false);
	}

	GRAPHICMANAGER->DrawRect(Vector2(_rcLoad.left, _rcLoad.top), Vector2((_rcLoad.right - _rcLoad.left), (_rcLoad.bottom - _rcLoad.top)), 0.0f, ColorF::Blue, CENTER, 1.0f, false);
	GRAPHICMANAGER->DrawRect(Vector2(_rcSave.left, _rcSave.top), Vector2((_rcSave.right - _rcSave.left), (_rcSave.bottom - _rcSave.top)), 0.0f, ColorF::Red, CENTER, 1.0f, false);
}

void Maptool::Save()
{
	//HANDLE file;
	//DWORD write;
	//
	//GetWindowText(_btnSaveName, titleSave, 256);
	//
	//string str = titleSave;
	//str += ".map";
	//
	//file = CreateFile(str.c_str(), GENERIC_WRITE, 0, NULL,
	//	CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
	//
	//WriteFile(file, _tiles, sizeof(Tile) * TILEWIDTH * TILEHEIGHT, &write, NULL);
	//CloseHandle(file);
}

void Maptool::Load()
{
	//HANDLE file;
	//DWORD read;
	//
	//GetWindowText(_btnLoadName, titleLoad, 256);
	//
	//string str = titleLoad;
	//str += ".map";
	//
	////file = CreateFile(titleLoad, GENERIC_READ, 0, NULL,
	//file = CreateFile(str.c_str(), GENERIC_READ, 0, NULL,
	//	OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	//
	//ReadFile(file, _tiles, sizeof(Tile) * TILEWIDTH * TILEHEIGHT, &read, NULL);
	//
	//CloseHandle(file);
}

void Maptool::SetUp()
{
	// TODO : button role?
	_btn1 = Object::CreateObject<Object>();
	_btn1->GetTrans()->SetPos(Vector2(WINSIZEX - 200, WINSIZEY - 200));
	_btn1->GetTrans()->SetScale(Vector2(100.0f, 50.0f));
	_btn1->AddComponent<Sprite>();
	_btn1->GetComponent<Sprite>()->SetFillRect(true);
	_btn1->GetComponent<Sprite>()->SetCameraAffect(false);

	_ctrSelect = NONE_MOVE;
	_currentTile.imgKey = "empty";

	for (int i = 0; i < TILENUMY; ++i)
	{
		for (int j = 0; j < TILENUMX; ++j)
		{
			int index = j + TILENUMX * i;

			_tiles[index] = Object::CreateObject<Tile>();
			_tiles[index]->Init(j, i);
			_tiles[index]->AddComponent<Sprite>();
			_tiles[index]->SetAttribute("None");
		}
	}
	for (int i = 0; i < SAMPLE_TILE_Y_NUM; ++i)
	{
		for (int j = 0; j < SAMPLE_TILE_X_NUM; ++j)
		{
			//Vector2((i % SAMPLE_TILE_X_NUM) * (100 / SAMPLE_TILE_X_NUM), (i / SAMPLE_TILE_X_NUM) * (100 / SAMPLE_TILE_Y_NUM);
			_sampleTile[i * SAMPLE_TILE_X_NUM + j].pos = { (WINSIZEX - 240) + j * SET_TILEWIDTH, 60 + i * SET_TILEHEIGHT };
			_sampleTile[i * SAMPLE_TILE_X_NUM + j].imgKey.clear();
		}
	}

	TileSetting();
}

void Maptool::SetMap()
{
	//RECT temp;
	for (int i = 0; i < TILENUMX * TILENUMY; ++i)
	{
		if ((_ptMouse.x <= WINSIZEX - 300) && PtInRect(&RectMakeCenter(_tiles[i]->GetTrans()->GetPos().x - CAMERA->GetPosition().x, _tiles[i]->GetTrans()->GetPos().y - CAMERA->GetPosition().y, TILEWIDTH, TILEHEIGHT), _ptMouse))
		//if ((_ptMouse.x <= WINSIZEX - 300) && IntersectRect(&temp , &RectMakeCenter(_tiles[i]->GetTrans()->GetPos().x - CAMERA->GetPosition().x, _tiles[i]->GetTrans()->GetPos().y - CAMERA->GetPosition().y, TILEWIDTH, TILEHEIGHT), &RectMake(_ptMouse.x, _ptMouse.y + GRAPHICMANAGER->FindImage(_currentTile.imgKey)->GetFrameHeight() / 2, _currentTile.colSize.x, _currentTile.colSize.y)))
		{
			if (_tiles[i]->GetChildren().size() > 0) return;

			if (_currentTile.imgKey == "empty" && _ctrSelect == Attribute::NONE_MOVE)
			{
				_tiles[i]->SetAttribute("Wall");
			}
			else
			{
				SetAttribute(i, _currentTile.startPos, _currentTile.size, _currentTile.startPos2, _currentTile.size2, FindTile(_currentTile.imgKey)->attribute);

				_tiles[i]->AddChild(Object::CreateObject<Object>());
				
				_tiles[i]->GetChildren()[0]->GetTrans()->SetPos(_tiles[i]->GetTrans()->GetPos() + Vector2(0, TILEHEIGHT / 2));
				if(_currentTile.pivot == RIGHT_BOTTOM) _tiles[i]->GetChildren()[0]->GetTrans()->SetPos(_tiles[i]->GetTrans()->GetPos() + Vector2(TILEWIDTH / 2, TILEHEIGHT / 2));

				_tiles[i]->GetChildren()[0]->GetTrans()->SetScale(GRAPHICMANAGER->FindImage(_currentTile.imgKey)->GetFrameWidth(), GRAPHICMANAGER->FindImage(_currentTile.imgKey)->GetFrameHeight());
				_tiles[i]->GetChildren()[0]->GetTrans()->SetRect();

				if (_currentTile.isFrame)
				{
					_tiles[i]->GetChildren()[0]->AddComponent<Sprite>()->Init(true, true);
					_tiles[i]->GetChildren()[0]->GetComponent<Sprite>()->SetImgName(_currentTile.imgKey);
					_tiles[i]->GetChildren()[0]->GetComponent<Sprite>()->SetFPS(0.5f);
					_tiles[i]->GetChildren()[0]->GetComponent<Sprite>()->SetPivot(_currentTile.pivot);
				}
				else
				{
					_tiles[i]->GetChildren()[0]->AddComponent<Sprite>()->SetImgName(_currentTile.imgKey);
					_tiles[i]->GetChildren()[0]->GetComponent<Sprite>()->SetPivot(_currentTile.pivot);
				}

				break;
			}
		}
	}

	for (int i = 0; i < SAMPLE_TILE_X_NUM * SAMPLE_TILE_Y_NUM; ++i)
	{
		if ((_ptMouse.x > WINSIZEX - 300) && PtInRect(&RectMakeCenter(_sampleTile[i].pos.x, _sampleTile[i].pos.y, SET_TILEWIDTH, SET_TILEHEIGHT), _ptMouse))
		{
			_currentTile.imgKey = FindTile(_sampleTile[i].imgKey)->imgKey;
			_currentTile.isFrame = FindTile(_sampleTile[i].imgKey)->isFrame;

			//_currentTile.vStartPos = FindTile(_sampleTile[i].imgKey)->vStartPos;
			//_currentTile.vSize = FindTile(_sampleTile[i].imgKey)->vSize;
			_currentTile.startPos = FindTile(_sampleTile[i].imgKey)->startPos;
			_currentTile.size = FindTile(_sampleTile[i].imgKey)->size;
			_currentTile.startPos2 = FindTile(_sampleTile[i].imgKey)->startPos2;
			_currentTile.size2 = FindTile(_sampleTile[i].imgKey)->size2;

			_currentTile.pivot = FindTile(_sampleTile[i].imgKey)->pivot;

			break;
		}
	}
}

void Maptool::RemoveObject()
{
	for (int i = 0; i < TILENUMX * TILENUMY; ++i)
	{
		if (_tiles[i]->GetChildren().size())
		{
			if ((_ptMouse.x <= WINSIZEX - 300) && PtInRect(&RectMakeRightBottom(_tiles[i]->GetChildren()[0]->GetTrans()->GetPos().x - CAMERA->GetPosition().x, _tiles[i]->GetChildren()[0]->GetTrans()->GetPos().y - CAMERA->GetPosition().y, _tiles[i]->GetChildren()[0]->GetTrans()->GetScale().x, _tiles[i]->GetChildren()[0]->GetTrans()->GetScale().y), _ptMouse))
			{
				string s = _tiles[i]->GetChildren()[0]->GetComponent<Sprite>()->GetImgKey();
				SetAttribute(i, FindTile(s)->startPos, FindTile(s)->size, FindTile(s)->startPos2, FindTile(s)->size2, "None");

				if (_tiles[i]->GetChildren().size() <= 0) return;
				_tiles[i]->RemoveChild(_tiles[i]->GetChildren()[0]);

				break;
			}
		}

		//if ((_ptMouse.x <= WINSIZEX - 300) && PtInRect(&RectMakeCenter(_tiles[i]->GetTrans()->GetPos().x - CAMERA->GetPosition().x, _tiles[i]->GetTrans()->GetPos().y - CAMERA->GetPosition().y, TILEWIDTH, TILEHEIGHT), _ptMouse))
		//{
		//	_tiles[i]->SetAttribute("None");
		//
		//	if (_tiles[i]->GetChildren().size() <= 0) return;
		//	_tiles[i]->RemoveChild(_tiles[i]->GetChildren()[0]);
		//
		//	break;
		//}
	}
}

void Maptool::SetAttribute(int curIdx, Vector2 StartPos, Vector2 size, Vector2 StartPos2, Vector2 size2, string attribute)
{
	int start = (curIdx - (TILENUMX * (StartPos.y - 1))) - (StartPos.x - 1);

	for (int i = 0; i < size.y; ++i)
	{
		for (int j = 0; j < size.x; ++j)
		{
			if (start + j + (TILENUMX * i) < 0)continue;

			_tiles[start + j + (TILENUMX * i)]->SetAttribute(attribute);
		}
	}

	start = (curIdx - (TILENUMX * (StartPos2.y - 1))) - (StartPos2.x - 1);

	for (int i = 0; i < size2.y; ++i)
	{
		for (int j = 0; j < size2.x; ++j)
		{
			if (start + j + (TILENUMX * i) < 0)continue;

			_tiles[start + j + (TILENUMX * i)]->SetAttribute(attribute);
		}
	}
}

int Maptool::FindId()
{
	for (int i = 0; i < TILENUMX * TILENUMY; ++i)
	{
		if ((_ptMouse.x <= WINSIZEX - 300) && PtInRect(&RectMakeCenter(_tiles[i]->GetTrans()->GetPos().x - CAMERA->GetPosition().x, _tiles[i]->GetTrans()->GetPos().y - CAMERA->GetPosition().y, TILEWIDTH, TILEHEIGHT), _ptMouse))
		{
			return _tiles[i]->GetId();
		}
	}
	return -1;
}

tagTile* Maptool::FindTile(string imgKey)
{
	mapTileIter key = _mTileList.find(imgKey);

	if (key != _mTileList.end()) return key->second;
	return nullptr;
}

void Maptool::TileSetting()
{
#pragma region Town
	_mTileList.insert(make_pair(("build_fountain"), tagTile().Clone("build_fountain", "Wall", false, 1, 1, PIVOT::RIGHT_BOTTOM, Vector2(3, 1), Vector2(3, 1))));
	_mTileList.insert(make_pair(("build_Retaile"), tagTile().Clone("build_Retaile", "Wall", false, 1, 1, PIVOT::RIGHT_BOTTOM, Vector2(12, 14), Vector2(12, 12), Vector2(10, 2), Vector2(3, 2))));
	//_mTileList.insert(make_pair(("build_Retaile"), tagTile().Clone("build_Retaile", "Wall", false, 1, 1, PIVOT::RIGHT_BOTTOM)));

	//Vector2 v[] = { Vector2(12, 14), Vector2(10, 2) };
	//Vector2 s[] = {Vector2(12, 12), Vector2(3, 2)};
	//_mTileList.find("build_Retaile")->second->Setting(v, s, 2);

	_mTileList.insert(make_pair(("build_Shop"), tagTile().Clone("build_Shop", "Wall", false, 1, 1, PIVOT::RIGHT_BOTTOM, Vector2(17, 12), Vector2(17, 12))));
	_mTileList.insert(make_pair(("build_Top1"), tagTile().Clone("build_Top1", "Wall", false, 1, 1, PIVOT::RIGHT_BOTTOM, Vector2(11, 10), Vector2(11, 10))));
	_mTileList.insert(make_pair(("build_Well"), tagTile().Clone("build_Well", "Wall", false, 1, 1, PIVOT::RIGHT_BOTTOM, Vector2(4, 3), Vector2(4, 3))));

	_mTileList.insert(make_pair(("door"), tagTile().Clone("door", "Wall", true, 5, 1, PIVOT::RIGHT_BOTTOM, Vector2(5, 1), Vector2(2, 1), Vector2(2, 1), Vector2(2, 1))));
	_mTileList.insert(make_pair(("doordown"), tagTile().Clone("doordown", "Wall", true, 5, 1, PIVOT::RIGHT_BOTTOM, Vector2(5, 3), Vector2(2, 1), Vector2(2, 3), Vector2(2, 1))));
	_mTileList.insert(make_pair(("dungeonLobby_entryStructure"), tagTile().Clone("dungeonLobby_entryStructure", "Wall", false, 1, 1, PIVOT::RIGHT_BOTTOM, Vector2(12, 1), Vector2(4, 1), Vector2(4, 1), Vector2(4, 1))));
	_mTileList.insert(make_pair(("dungeonLobby_entryStructureLeft"), tagTile().Clone("dungeonLobby_entryStructureLeft", "Wall", false, 1, 1, PIVOT::RIGHT_BOTTOM, Vector2(4, 2), Vector2(4, 2))));
	_mTileList.insert(make_pair(("dungeonLobby_entryStructureRight"), tagTile().Clone("dungeonLobby_entryStructureRight", "Wall", false, 1, 1, PIVOT::RIGHT_BOTTOM, Vector2(4, 2), Vector2(4, 2))));

	_mTileList.insert(make_pair(("build_Bottom3"), tagTile().Clone("build_Bottom3", "Wall", false, 1, 1, PIVOT::BOTTOM, Vector2(1, 1), Vector2(1, 1))));
	_mTileList.insert(make_pair(("bench"), tagTile().Clone("bench", "Wall", false, 1, 1, PIVOT::RIGHT_BOTTOM, Vector2(5, 3), Vector2(5, 3))));
	_mTileList.insert(make_pair(("build_Board"), tagTile().Clone("build_Board", "Wall", false, 1, 1, PIVOT::RIGHT_BOTTOM, Vector2(7, 1), Vector2(7, 1))));
	_mTileList.insert(make_pair(("build_Bottom1"), tagTile().Clone("build_Bottom1", "Wall", false, 1, 1, PIVOT::RIGHT_BOTTOM, Vector2(11, 10), Vector2(11, 10), Vector2(16, 3), Vector2(1, 1))));
	_mTileList.insert(make_pair(("build_Bottom2"), tagTile().Clone("build_Bottom2", "Wall", false, 1, 1, PIVOT::RIGHT_BOTTOM, Vector2(11, 10), Vector2(11, 10))));

	_mTileList.insert(make_pair(("Village_OilLamps_1"), tagTile().Clone("Village_OilLamps_1", "Wall", false, 1, 1, PIVOT::BOTTOM, Vector2(1, 1), Vector2(1, 1))));
	_mTileList.insert(make_pair(("build_Enchant"), tagTile().Clone("build_Enchant", "Wall", false, 1, 1, PIVOT::RIGHT_BOTTOM, Vector2(20, 6), Vector2(20, 6), Vector2(11, 16), Vector2(8, 10))));
	_mTileList.insert(make_pair(("build_Forge"), tagTile().Clone("build_Forge", "Wall", false, 1, 1, PIVOT::RIGHT_BOTTOM, Vector2(1, 1), Vector2(1, 1))));
	_mTileList.insert(make_pair(("tree"), tagTile().Clone("tree", "Wall", true, 4, 1, PIVOT::RIGHT_BOTTOM, Vector2(5, 1), Vector2(3, 1), Vector2(5, 1), Vector2(3, 1))));
	_mTileList.insert(make_pair(("Village_OilLamps_2"), tagTile().Clone("Village_OilLamps_2", "Wall", false, 1, 1, PIVOT::BOTTOM, Vector2(1, 1), Vector2(1, 1))));
	_mTileList.insert(make_pair(("dungeonLobby_middleRighttRock"), tagTile().Clone("dungeonLobby_middleRighttRock", "Wall", false, 1, 1, PIVOT::RIGHT_BOTTOM, Vector2(2, 1), Vector2(2, 1))));

	_mTileList.insert(make_pair(("forgeBoard"), tagTile().Clone("forgeBoard", "Wall", false, 1, 1, PIVOT::RIGHT_BOTTOM, Vector2(2, 1), Vector2(2, 1))));
	_mTileList.insert(make_pair(("potionBoard"), tagTile().Clone("potionBoard", "Wall", false, 1, 1, PIVOT::RIGHT_BOTTOM, Vector2(2, 1), Vector2(2, 1))));

	_mTileList.insert(make_pair(("empty"), tagTile().Clone("empty", "None", false, 1, 1, PIVOT::RIGHT_BOTTOM, Vector2(1, 1), Vector2(1, 1))));
#pragma endregion

#pragma region Dungeon
	_mTileList.insert(make_pair(("bigRock"), tagTile().Clone("bigRock", "Wall", false, 1, 1, PIVOT::BOTTOM, Vector2(1, 1), Vector2(1, 1))));
	_mTileList.insert(make_pair(("book"), tagTile().Clone("book", "Wall", false, 1, 1, PIVOT::BOTTOM, Vector2(1, 1), Vector2(1, 1))));
	_mTileList.insert(make_pair(("brokenPillar"), tagTile().Clone("brokenPillar", "Wall", false, 1, 1, PIVOT::BOTTOM, Vector2(1, 1), Vector2(1, 1))));
	_mTileList.insert(make_pair(("fountain"), tagTile().Clone("fountain", "Wall", false, 1, 1, PIVOT::BOTTOM, Vector2(1, 1), Vector2(1, 1))));
	_mTileList.insert(make_pair(("lathe"), tagTile().Clone("lathe", "Wall", false, 1, 1, PIVOT::BOTTOM, Vector2(1, 1), Vector2(1, 1))));
	_mTileList.insert(make_pair(("pillar"), tagTile().Clone("pillar", "Wall", false, 1, 1, PIVOT::BOTTOM, Vector2(1, 1), Vector2(1, 1))));
	_mTileList.insert(make_pair(("pot"), tagTile().Clone("pot", "Wall", false, 1, 1, PIVOT::BOTTOM, Vector2(1, 1), Vector2(1, 1))));
	_mTileList.insert(make_pair(("pot_slime"), tagTile().Clone("pot_slime", "Wall", false, 1, 1, PIVOT::BOTTOM, Vector2(1, 1), Vector2(1, 1))));
	_mTileList.insert(make_pair(("skull1"), tagTile().Clone("skull1", "Wall", false, 1, 1, PIVOT::BOTTOM, Vector2(1, 1), Vector2(1, 1))));
	_mTileList.insert(make_pair(("skull2"), tagTile().Clone("skull2", "Wall", false, 1, 1, PIVOT::BOTTOM, Vector2(1, 1), Vector2(1, 1))));
	_mTileList.insert(make_pair(("skull3"), tagTile().Clone("skull3", "Wall", false, 1, 1, PIVOT::BOTTOM, Vector2(1, 1), Vector2(1, 1))));
	_mTileList.insert(make_pair(("smallRock"), tagTile().Clone("smallRock", "Wall", false, 1, 1, PIVOT::BOTTOM, Vector2(1, 1), Vector2(1, 1))));
	_mTileList.insert(make_pair(("smallRock_slime"), tagTile().Clone("smallRock_slime", "Wall", false, 1, 1, PIVOT::BOTTOM, Vector2(1, 1), Vector2(1, 1))));
#pragma endregion

	SetPage();
}

void Maptool::SetPage()
{
	switch (_page)
	{
	case TOWN:
	{
		_sampleTile[0].imgKey = _mTileList.find("build_fountain")->second->imgKey;
		_sampleTile[1].imgKey = _mTileList.find("build_Retaile")->second->imgKey;
		_sampleTile[2].imgKey = _mTileList.find("build_Shop")->second->imgKey;
		_sampleTile[3].imgKey = _mTileList.find("build_Top1")->second->imgKey;
		_sampleTile[4].imgKey = _mTileList.find("build_Well")->second->imgKey;
		_sampleTile[5].imgKey = _mTileList.find("door")->second->imgKey;
		_sampleTile[6].imgKey = _mTileList.find("doordown")->second->imgKey;
		_sampleTile[7].imgKey = _mTileList.find("dungeonLobby_entryStructure")->second->imgKey;
		_sampleTile[8].imgKey = _mTileList.find("dungeonLobby_entryStructureLeft")->second->imgKey;
		_sampleTile[9].imgKey = _mTileList.find("dungeonLobby_entryStructureRight")->second->imgKey;
		_sampleTile[10].imgKey = _mTileList.find("build_Bottom3")->second->imgKey;
		_sampleTile[11].imgKey = _mTileList.find("bench")->second->imgKey;
		_sampleTile[12].imgKey = _mTileList.find("build_Board")->second->imgKey;
		_sampleTile[13].imgKey = _mTileList.find("build_Bottom1")->second->imgKey;
		_sampleTile[14].imgKey = _mTileList.find("build_Bottom2")->second->imgKey;
		_sampleTile[15].imgKey = _mTileList.find("Village_OilLamps_1")->second->imgKey;
		_sampleTile[16].imgKey = _mTileList.find("build_Enchant")->second->imgKey;
		_sampleTile[17].imgKey = _mTileList.find("build_Forge")->second->imgKey;
		_sampleTile[18].imgKey = _mTileList.find("tree")->second->imgKey;
		_sampleTile[19].imgKey = _mTileList.find("Village_OilLamps_2")->second->imgKey;
		_sampleTile[20].imgKey = _mTileList.find("dungeonLobby_middleRighttRock")->second->imgKey;
		_sampleTile[21].imgKey = _mTileList.find("forgeBoard")->second->imgKey;
		_sampleTile[22].imgKey = _mTileList.find("potionBoard")->second->imgKey;
		_sampleTile[23].imgKey = _mTileList.find("empty")->second->imgKey;
	}
	break;
	case DONGEON:
	{
		_sampleTile[0].imgKey = _mTileList.find("smallRock")->second->imgKey;
		_sampleTile[1].imgKey = _mTileList.find("smallRock_slime")->second->imgKey;
		_sampleTile[2].imgKey = _mTileList.find("bigRock")->second->imgKey;
		_sampleTile[3].imgKey = _mTileList.find("book")->second->imgKey;
		_sampleTile[4].imgKey = _mTileList.find("pot")->second->imgKey;
		_sampleTile[5].imgKey = _mTileList.find("pot_slime")->second->imgKey;
		_sampleTile[6].imgKey = _mTileList.find("lathe")->second->imgKey;
		_sampleTile[7].imgKey = _mTileList.find("fountain")->second->imgKey;
		_sampleTile[8].imgKey = _mTileList.find("pillar")->second->imgKey;
		_sampleTile[9].imgKey = _mTileList.find("skull1")->second->imgKey;
		_sampleTile[10].imgKey = _mTileList.find("skull2")->second->imgKey;
		_sampleTile[11].imgKey = _mTileList.find("skull3")->second->imgKey;
		_sampleTile[12].imgKey = _mTileList.find("brokenPillar")->second->imgKey;
		_sampleTile[13].imgKey = _mTileList.find("empty")->second->imgKey;
		_sampleTile[14].imgKey = _mTileList.find("empty")->second->imgKey;
		_sampleTile[15].imgKey = _mTileList.find("empty")->second->imgKey;
		_sampleTile[16].imgKey = _mTileList.find("empty")->second->imgKey;
		_sampleTile[17].imgKey = _mTileList.find("empty")->second->imgKey;
		_sampleTile[18].imgKey = _mTileList.find("empty")->second->imgKey;
		_sampleTile[19].imgKey = _mTileList.find("empty")->second->imgKey;
		_sampleTile[20].imgKey = _mTileList.find("empty")->second->imgKey;
		_sampleTile[21].imgKey = _mTileList.find("empty")->second->imgKey;
		_sampleTile[22].imgKey = _mTileList.find("empty")->second->imgKey;
		_sampleTile[23].imgKey = _mTileList.find("empty")->second->imgKey;
	}
	break;
	case PAGE_END: break;
	}
}
