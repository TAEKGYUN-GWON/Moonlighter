#pragma once
#include "Item.h"
#include "Object.h"
#include "Component.h"
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
	
	Graphic* _ui;
	Object* _select;

	multimap<string, tagItemInfo> _inven;
	multimap<string, tagItemInfo>::iterator iter;
	bool _isActive;

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
	bool GetActive() { return _isActive; }
	void SetActive(bool active) { _isActive = active; }
};