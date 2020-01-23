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

	//�������� �Ҹ�ǰ���� �׿� �ٸ� ���������� ���Ѵ�.
	EItemType _type;

	//����, �������� ������ ��Ÿ����.
	int _price, _maxCount;

	//�������� ����� �̹����� ����
	Sprite* _image;

public:

	virtual void Init();
	virtual void Init(Vector2 pos) {};
	virtual void Update();
	Sprite* GetSprite() { return _image; }
	//Get Something
	int GetMaxCount() { return _maxCount; }
	int GetPrice() { return _price; }
	EItemType GetType() { return _type; }

	//Set Something
	//void SetItemCount(int count) {
	//	_MaxCount += count;
	//}

	void SetPrice(int price) {
		_price = price;
	}
	void SetMaxCount(int num) { _maxCount = num; }
	template <typename T>
	static T* CreateItem(string MobName, Vector2 pos);

};

#include"Item.hpp"