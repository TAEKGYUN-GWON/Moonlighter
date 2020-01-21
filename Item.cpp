#include "stdafx.h"
#include "Item.h"
#include "Potion.h"

void Item::Init()
{
	_tag = "Item";
	_maxCount = 1;
	_price = 0;
}

void Item::Update()
{
	super::Update();

}
