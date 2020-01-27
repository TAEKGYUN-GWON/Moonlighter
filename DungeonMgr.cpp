#include "stdafx.h"
#include "DungeonMgr.h"

void DungeonMgr::Init()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			Dungeon* room = new Dungeon;
			room->Init(Vector2(i * TILEWIDTH * Dungeon_X, j * TILEHEIGHT * Dungeon_Y));
			_rooms.push_back(room);
		}
	}
}

void DungeonMgr::Update()
{
	for (Dungeon* d : _rooms)
		d->Update();
}

void DungeonMgr::Render()
{
	wchar_t buffer[128];
	int a = 0;
	for (Dungeon* d : _rooms)
	{
		if (d->GetTrans()->GetPos().x < CAMERA->GetPosition().x || d->GetTrans()->GetPos().x > CAMERA->GetPosition().x + WINSIZEX ||
			d->GetTrans()->GetPos().y < CAMERA->GetPosition().y || d->GetTrans()->GetPos().y > CAMERA->GetPosition().y + WINSIZEY) 
			d->Render();
	}
	for (int i = 0; i < _rooms.size(); i++)
	{
		a++;
		swprintf(buffer, 128, L"c : %d", _rooms[i]->GetChildren().size());

		GRAPHICMANAGER->Text(Vector2(WINSIZEX / 2, 50 + a * 50), buffer, 10, 300, 50, ColorF::Azure);

	}
}
