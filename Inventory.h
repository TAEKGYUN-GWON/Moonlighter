#pragma once
#include "Item.h"
class Inventory
{
private:
	
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