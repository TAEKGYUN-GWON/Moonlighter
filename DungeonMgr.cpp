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

	for (Dungeon* d : _rooms)
			d->Render();

}
