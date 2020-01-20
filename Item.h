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

	//아이템이 소모품인지 그외 다른 모든것인지를 정한다.
	EItemType _type;
	
	//가격, 아이템의 수량을 나타낸다.
	int _price, _itemCount;

	//아이템이 사용할 이미지를 저장
	Sprite* _image;

public:
	Item();
	~Item();

	virtual void Init(EItemType types, int itemCount);
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

