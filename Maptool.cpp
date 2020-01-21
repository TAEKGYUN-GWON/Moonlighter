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
#pragma endregion

	GRAPHICMANAGER->AddFrameImage("TileSet", L"TileSet2.png", 3, 3);
	GRAPHICMANAGER->AddFrameImage("set_tile", L"set_tile2.png", 8, 10);
	GRAPHICMANAGER->AddFrameImage("will_dungeon", L"will_dungeon.png", 10, 13);

	//obj = Object::CreateObject<Object>();
	//obj->GetTrans()->SetPos(Vector2(WINSIZEX / 2 - 300, WINSIZEY / 2));
	//Sprite* a = obj->AddComponent<Sprite>();
	//a->SetImgName("eagle");
	////a->SetFlipX(true);
	//obj->GetTrans()->SetScale(Vector2(a->GetGraphic()->GetFrameWidth(), a->GetGraphic()->GetFrameHeight()));

	SetUp();

	_isDown = false;

	_curFrameX = _curFrameY = 0;
}

void Maptool::Update()
{
	Scene::Update();

	//if (KEYMANAGER->isStayKeyDown(VK_LBUTTON))
	//{
	//	//if (PtInRect(&_btn1->GetTrans()->GetRect(), _ptMouse))
	//	//{
	//	//	_btn1->GetComponent<Sprite>()->SetRectColor(ColorF::Red);
	//	//}
	//	if (_STGround->GetIsActive() && PtInRect(&_STGround->GetTrans()->GetRect(), _ptMouse))
	//	{
	//		_STGround->GetComponent<Sprite>()->SetRectColor(ColorF::Red);
	//		
	//		_STGround->GetTrans()->SetPos(
	//		Vector2(_STGround->GetTrans()->GetPos().x + (_ptMouse.x - _prevMouse.x),
	//				_STGround->GetTrans()->GetPos().y + (_ptMouse.y - _prevMouse.y)));
	//	}
	//}

	//_STGround->GetTrans()->SetPos(Vector2((CAMERA->GetPosition().x + WINSIZEX) - (_STGround->GetTrans()->GetScale().x / 2), _STGround->GetTrans()->GetScale().y / 2 + 2));

	if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
	{
		SetMap();
	}

	if (KEYMANAGER->isOnceKeyUp('1')) _curFrameX = (_curFrameX + 1) % 3;
	if (KEYMANAGER->isOnceKeyUp('2')) _curFrameY = (_curFrameY + 1) % 2;
}

void Maptool::Render()
{
	//Scene::Render();
	char buffer[128];

	for (int i = 0; i < 25; ++i)
	{
		for (int j = 0; j < 33; ++j)
		{
			int cullX = CAMERA->GetPosition().x / TILEWIDTH;
			int cullY = CAMERA->GetPosition().y / TILEHEIGHT;

			_index = (i + cullY) * TILENUMX + (j + cullX);

			if (_index < 0 || _index >= TILENUMX * TILENUMY) continue;
			else _tiles[_index]->SetAllowsRender(false);

			_tiles[_index]->SetAllowsRender(true);
			_tiles[_index]->Render();
			sprintf_s(buffer, "%d", _index);
			GRAPHICMANAGER->DrawTextD2D(_tiles[_index]->GetTrans()->GetPos(), buffer, 10, 1.0f, ColorF::Yellow);
		}
	}

	GRAPHICMANAGER->DrawFillRect(Vector2(WINSIZEX - 150, WINSIZEY / 2), Vector2(300, WINSIZEY), 0.0f, ColorF::Aquamarine, 1.0f, CENTER, false);
	
	//GRAPHICMANAGER->DrawTextD2D(Vector2(200, 100), L"Here!!", 20, 1.0f, ColorF::White);

	for (int i = 0; i < SAMPLE_TILE_X_NUM * SAMPLE_TILE_Y_NUM; ++i)
	{
		//GRAPHICMANAGER->DrawRect(Vector2(_sampleTile[i].rcTile.left, _sampleTile[i].rcTile.top), Vector2(30, 30), 0.0f, ColorF::White, PIVOT::LEFT_TOP, 1.0f, false);
		GRAPHICMANAGER->DrawRect(Vector2(_sampleTile[i].pos.x, _sampleTile[i].pos.y), Vector2(SET_TILEWIDTH, SET_TILEHEIGHT), 0.0f, ColorF::White, PIVOT::CENTER, 1.0f, false);
	}

	GRAPHICMANAGER->DrawImage("set_tile", Vector2(WINSIZEX - 150, WINSIZEY / 4), 1.0f,  CENTER, false);
	//GRAPHICMANAGER->DrawImage("build_Board", Vector2(200, 200));
	//GRAPHICMANAGER->DrawImage("bench", Vector2(200, 500));
	//GRAPHICMANAGER->DrawImage("build_Enchant", Vector2(800, 420));
	GRAPHICMANAGER->DrawFrameImage("will_dungeon", Vector2(400, 420), 1, 1);

	sprintf_s(buffer, "%d", a);
	//GRAPHICMANAGER->DrawTextD2D(Vector2(100, WINSIZEY - 30), buffer, 20, 1.0f, ColorF::White);
	GRAPHICMANAGER->DrawTextD2D(Vector2(CAMERA->GetPosition().x + 100, CAMERA->GetPosition().y + WINSIZEY - 30), buffer, 20, 1.0f, ColorF::White);

	sprintf_s(buffer, "%f", CAMERA->GetPosition().x);
	GRAPHICMANAGER->DrawTextD2D(Vector2(CAMERA->GetPosition().x + 100, CAMERA->GetPosition().y + WINSIZEY - 60), buffer, 20, 1.0f, ColorF::White, DWRITE_TEXT_ALIGNMENT_LEADING, L"¸¼Àº°íµñ", false);

	if(_currentTile.isFrame) GRAPHICMANAGER->DrawFrameImage(_currentTile.imgKey, Vector2(_ptMouse), 0, 0, 0.85f);
	else GRAPHICMANAGER->DrawImage(_currentTile.imgKey, Vector2(_ptMouse), 0.85f);
}

void Maptool::SetUp()
{
	// TODO : button role?
	//_btn1 = Object::CreateObject<Object>();
	//_btn1->GetTrans()->SetPos(Vector2(WINSIZEX / 2, 200));
	//_btn1->GetTrans()->SetScale(Vector2(100.0f, 50.0f));
	//_btn1->AddComponent<Sprite>();

	_ctrSelect = CTRL_TERRAINDRAW;

	for (int i = 0; i < TILENUMY; ++i)
	{
		for (int j = 0; j < TILENUMX; ++j)
		{
			_index = j + TILENUMX * i;

			_tiles[_index] = new Tile;
			_tiles[_index]->Init(j, i);
			_tiles[_index]->AddComponent<Sprite>();
			_tiles[_index]->SetAllowsRender(false);
		}
	}

	for (int i = 0; i < SAMPLE_TILE_Y_NUM; ++i)
	{
		for (int j = 0; j < SAMPLE_TILE_X_NUM; ++j)
		{
			//Vector2((i % SAMPLE_TILE_X_NUM) * (100 / SAMPLE_TILE_X_NUM), (i / SAMPLE_TILE_X_NUM) * (100 / SAMPLE_TILE_Y_NUM);
			_sampleTile[i * SAMPLE_TILE_X_NUM + j].pos = { (WINSIZEX - 240) + j * SET_TILEWIDTH, 60 + i * SET_TILEHEIGHT };
			_sampleTile[i * SAMPLE_TILE_X_NUM + j].imgKey.clear();
			//_sampleTile[i * SAMPLE_TILE_X_NUM + j].frameX = 1;
			//_sampleTile[i * SAMPLE_TILE_X_NUM + j].frameY = 1;

			//SetRect(&_sampleTile[i * SAMPLE_TILE_X_NUM + j].rcTile,
			//	(WINSIZEX - 270) + j * TILEWIDTH,
			//	30 + i * TILEHEIGHT,
			//	(WINSIZEX - 270) + j * TILEWIDTH + TILEHEIGHT,
			//	i * TILEWIDTH + TILEHEIGHT);
			//_sampleTile[i * SAMPLE_TILE_X_NUM + j].pos = Vector2((i % SAMPLE_TILE_X_NUM) * (100 / SAMPLE_TILE_X_NUM), (i / SAMPLE_TILE_X_NUM) * (100 / SAMPLE_TILE_Y_NUM);
		}
	}

#pragma region TileSetting
	_mTileList.insert(make_pair(("build_fountain"), tagTile().Clone("build_fountain", Attribute::NONE, false, 1, 1)));
	_mTileList.insert(make_pair(("build_Retaile"), tagTile().Clone("build_Retaile", Attribute::NONE, false, 1, 1)));
	_mTileList.insert(make_pair(("build_Shop"), tagTile().Clone("build_Shop", Attribute::NONE, false, 1, 1)));
	_mTileList.insert(make_pair(("build_Top1"), tagTile().Clone("build_Top1", Attribute::NONE, false, 1, 1)));
	_mTileList.insert(make_pair(("build_Well"), tagTile().Clone("build_Well", Attribute::NONE, false, 1, 1)));

	_mTileList.insert(make_pair(("door"), tagTile().Clone("door", Attribute::NONE, true, 5, 1)));
	_mTileList.insert(make_pair(("doordown"), tagTile().Clone("doordown", Attribute::NONE, true, 5, 1)));
	_mTileList.insert(make_pair(("dungeonLobby_entryStructure"), tagTile().Clone("dungeonLobby_entryStructure", Attribute::NONE, false, 1, 1)));
	_mTileList.insert(make_pair(("dungeonLobby_entryStructureLeft"), tagTile().Clone("dungeonLobby_entryStructureLeft", Attribute::NONE, false, 1, 1)));
	_mTileList.insert(make_pair(("dungeonLobby_entryStructureRight"), tagTile().Clone("dungeonLobby_entryStructureRight", Attribute::NONE, false, 1, 1)));

	_mTileList.insert(make_pair(("build_Bottom3"), tagTile().Clone("build_Bottom3", Attribute::NONE, false, 1, 1)));
	_mTileList.insert(make_pair(("bench"), tagTile().Clone("bench", Attribute::NONE, false, 1, 1)));
	_mTileList.insert(make_pair(("build_Board"), tagTile().Clone("build_Board", Attribute::NONE, false, 1, 1)));
	_mTileList.insert(make_pair(("build_Bottom1"), tagTile().Clone("build_Bottom1", Attribute::NONE, false, 1, 1)));
	_mTileList.insert(make_pair(("build_Bottom2"), tagTile().Clone("build_Bottom2", Attribute::NONE, false, 1, 1)));

	_mTileList.insert(make_pair(("Village_OilLamps_1"), tagTile().Clone("Village_OilLamps_1", Attribute::NONE, false, 1, 1)));
	_mTileList.insert(make_pair(("build_Enchant"), tagTile().Clone("build_Enchant", Attribute::NONE, false, 1, 1)));
	_mTileList.insert(make_pair(("build_Forge"), tagTile().Clone("build_Forge", Attribute::NONE, false, 1, 1)));
	_mTileList.insert(make_pair(("tree"), tagTile().Clone("tree", Attribute::NONE, true, 4, 1)));
	_mTileList.insert(make_pair(("Village_OilLamps_2"), tagTile().Clone("Village_OilLamps_2", Attribute::NONE, false, 1, 1)));

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
#pragma endregion

	// 20200120 FIXME : Text¸¦ »ì·Á¶ó..!
	//obj = Object::CreateObject<Object>();
	//obj->GetTrans()->SetPos(200, 100);
	//obj->AddComponent<Text>();
	//obj->GetComponent<Text>()->CreateText(L"Where are you", 20, 200, 200, ColorF::White);
}

void Maptool::SetMap()
{
	for (int i = 0; i < TILENUMX * TILENUMY; ++i)
	{
		if ((_ptMouse.x <= WINSIZEX - 300) && PtInRect(&RectMakeCenter(_tiles[i]->GetTrans()->GetPos().x - CAMERA->GetPosition().x, _tiles[i]->GetTrans()->GetPos().y - CAMERA->GetPosition().y, TILEWIDTH, TILEHEIGHT), _ptMouse))
		{
			cout << i << endl;

			break;
		}
	}

	for (int i = 0; i < SAMPLE_TILE_X_NUM * SAMPLE_TILE_Y_NUM; ++i)
	{
		if ((_ptMouse.x > WINSIZEX - 300) && PtInRect(&RectMakeCenter(_sampleTile[i].pos.x, _sampleTile[i].pos.y, SET_TILEWIDTH, SET_TILEHEIGHT), _ptMouse))
		{
			_currentTile.imgKey = FindTile(_sampleTile[i].imgKey)->imgKey;
			_currentTile.isFrame = FindTile(_sampleTile[i].imgKey)->isFrame;
			cout << _currentTile.imgKey << endl;

			break;
		}
	}

	//_index = (i + cullY) * TILENUMX + (j + cullX);
	//a = _tiles[0]->GetTrans()->GetPos().x + (_ptMouse.x / TILEWIDTH) + TILENUMX * _tiles[0]->GetTrans()->GetPos().y + (_ptMouse.y / TILEHEIGHT);
}

tagTile* Maptool::FindTile(string imgKey)
{
	mapTileIter key = _mTileList.find(imgKey);

	if (key != _mTileList.end()) return key->second;
	return nullptr;
}
