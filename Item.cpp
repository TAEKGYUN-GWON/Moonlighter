#include "stdafx.h"
#include "Item.h"
#include "Potion.h"

void Item::Init()
{
	Object::Init();
	_tag = "Item";
	_maxCount = 1;
	_price = 0;
	_image = AddComponent<Sprite>();
}

void Item::Update()
{
	Object::Update();
}
