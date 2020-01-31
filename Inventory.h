#pragma once
#include "Item.h"
#include "Object.h"
#include "Component.h"
struct tagItemInfo
{
	tagItemInfo(string name, int some)
	{
		this->item = item;
		this->some = some;
	}
	tagItemInfo(Item* item,Vector2 pos)
	{
		this->item = item->GetComponent<Sprite>()->GetImgKey();
		this->some = 1;
		this->pos = pos;
	}
	string item;
	int some;
	Vector2 pos;
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

	int _atk;

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


	int GetATK() { return _atk; }
	void SetATK(int atk) { _atk = atk; }
};