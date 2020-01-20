#include "stdafx.h"
#include "Item.h"


Item::Item()
{

}

Item::~Item()
{

}

void Item::Init(EItemType type, int itemCount)
{
	_type = type;
	_itemCount = itemCount;
}

void Item::Update()
{

}

void Item::Render()
{

}

Item * Item::CreateItem(string MobName)
{
	Item* item = Object::CreateObject<Item>();

	//->Init()

	return item;
}
