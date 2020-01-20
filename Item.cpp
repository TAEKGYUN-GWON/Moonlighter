#include "stdafx.h"
#include "Item.h"


Item::Item()
{

}

Item::~Item()
{

}

void Item::Init(EItemType type, string ImageKey, int price, int itemCount)
{
	
	
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
