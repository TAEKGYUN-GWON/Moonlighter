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

	//�������� �Ҹ�ǰ���� �׿� �ٸ� ���������� ���Ѵ�.
	EItemType _type;
	
	//����, �������� ������ ��Ÿ����.
	int _price, _itemCount;

	//�������� ����� �̹����� ����
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

