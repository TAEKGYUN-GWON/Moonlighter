#pragma once
#include "Item.h"

struct tagItemInfo
{
	tagItemInfo(Item* item, int some)
	{
		this->item = item;
		this->some = some;
	}
	tagItemInfo(Item* item)
	{
		this->item = item;
		this->some = 1;
	}
	Item* item;
	int some;
};

class Inventory
{
private:
	

	multimap<string, tagItemInfo> _inven;
	multimap<string, tagItemInfo>::iterator iter;


public:



	Inventory();
	~Inventory();

	void Init();
	void Update();
	void Release();

	void Insert(Item* item);
	void Remove(string name, int num);

};