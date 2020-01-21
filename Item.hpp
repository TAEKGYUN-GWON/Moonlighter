#pragma once
#include"Item.h"


template <typename T>
T* Item::CreateItem(string MobName, Vector2 pos)
{
	T* item = CreateObject<T>();

	item->Init(pos);

	return item;
}

