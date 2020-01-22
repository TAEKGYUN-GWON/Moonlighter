#pragma once
#include "Item.h"
#include "Object.h"

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

class Inventory : public Object
{
private:
	
	Graphic* _ui;

	multimap<string, tagItemInfo> _inven;
	multimap<string, tagItemInfo>::iterator iter;

public:



	Inventory();
	~Inventory();

	void Init();
	void Update();
	void Release();
	void Render();

	void Insert(Item* item);
	void Remove(string name, int num);

	void Quantity();

};