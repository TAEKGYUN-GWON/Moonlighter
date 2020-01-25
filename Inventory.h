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
	Graphic* _select;
	Vector2 pos;
	multimap<string, tagItemInfo> _inven;
	multimap<string, tagItemInfo>::iterator iter;
	bool _isActive;
	int _money=0;

public:

	Inventory();
	~Inventory();

	void Init();
	void Update();
	void Release();
	void Render();
	void Insert(Item* item);
	void Remove(string name, int num);

	int FindItemSome(string name);

	void Quantity();
	bool GetActive() { return _isActive; }
	void SetActive(bool active) { _isActive = active; }
	void KeyCon();
	void PosCorrection();
	void AddMoney(int money) { _money += money; }
	bool DeductionMoney(int money);
	int GetMoney() { return _money; }
};