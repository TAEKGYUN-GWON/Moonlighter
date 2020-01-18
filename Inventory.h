#pragma once
#include "Item.h"
class Inventory
{
private:
	vector<Item*> _itemList;


public:
	Inventory();
	~Inventory();
};