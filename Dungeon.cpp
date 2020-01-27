#include "stdafx.h"
#include "Dungeon.h"

void Dungeon::Init()
{
	Scene::Init();
	_name = "Dungeon";
	SetParent(SCENEMANAGER->GetNowScene());

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
	GRAPHICMANAGER->AddImage("Dungeon", L"resource/img/Dungeon/background.png");
	GRAPHICMANAGER->AddImage("empty", L"resource/img/empty.png");
	//_player = Object::CreateObject<Player>();
	//_player->Init(this);
	SetUp();
	_eMgr->Init(this);
}

void Dungeon::Update()
{
	Scene::Update();
	_eMgr->Update();
}

void Dungeon::Render()
{
	GRAPHICMANAGER->FindImage("Dungeon")->Render(0,0, PIVOT::LEFT_TOP);

	Scene::Render();
}

void Dungeon::SetUp()
{

	for (int i = 0; i < Dungeon_Y; ++i)
	{
		for (int j = 0; j < Dungeon_X; ++j)
		{
			int index = j + Dungeon_X * i;

			_tiles[index] = Object::CreateObject<Tile>(this);
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
	
	string a = "Dungeon";

	char buffer[128];
	sprintf_s(buffer, "%d.map", RND->getFromIntTo(1, 8));
	string b = buffer;

	string str = a + b;

	//file = CreateFile(titleLoad, GENERIC_READ, 0, NULL,
	file = CreateFile(str.c_str(), GENERIC_READ, 0, NULL,
		OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

	if (file != INVALID_HANDLE_VALUE)
	{
		//MessageBox(_hWnd, "load วัดู", str.c_str(), MB_OK);

		ReadFile(file, _tagTiles, sizeof(tagTile) * Dungeon_X * Dungeon_Y, &read, NULL);
		CloseHandle(file);

		for (int i = 0; i < Dungeon_X * Dungeon_Y; i++)
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
			}
		}
	}
	else MessageBox(_hWnd, "can not found the file.", str.c_str(), MB_OK);

}
