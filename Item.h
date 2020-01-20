#pragma once
#include "Object.h"

enum EItemType
{
	useable,
	another
};

class Item : public Object
{

protected:

	EItemType _type;

	int _price, _itemCount;

	Sprite* _image;



public:
	Item();
	~Item();

	virtual void Init(EItemType type, string ImageKey, int price, int itemCount = 1);
	virtual void Update();
	virtual void Render();

	//Get Something
	int GetItemCount() { return _itemCount; }
	int GetPrice() { return _price; }
	EItemType GetType() { return _type; }

	//Set Something
	void SetItemCount(int count) {
		_itemCount = count;
	}

	void SetPrice(int price) {
		_price = price;
	}

	static Item* CreateItem(string MobName);

};

