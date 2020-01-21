#pragma once
#include "Object.h"

enum class EItemType
{
	useable,
	etc
};

class Item : public Object
{

protected:

	typedef Object super;

	//�������� �Ҹ�ǰ���� �׿� �ٸ� ���������� ���Ѵ�.
	EItemType _type;

	//����, �������� ������ ��Ÿ����.
	int _price, _itemCount;

	//�������� ����� �̹����� ����
	Sprite* _image;

public:
	Item() {}
	~Item() {}

	virtual void Init();
	virtual void Init(Vector2 pos) = 0;
	virtual void Update();

	//Get Something
	int GetItemCount() { return _itemCount; }
	int GetPrice() { return _price; }
	EItemType GetType() { return _type; }

	//Set Something
	void SetItemCount(int count) {
		_itemCount += count;
	}

	void SetPrice(int price) {
		_price = price;
	}
	template <typename T>
	static T* CreateItem(string MobName, Vector2 pos);

};

#include"Item.hpp"