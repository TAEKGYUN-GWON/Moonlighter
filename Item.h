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

	//아이템이 소모품인지 그외 다른 모든것인지를 정한다.
	EItemType _type;

	//가격, 아이템의 수량을 나타낸다.
	int _price, _maxCount;

	//아이템이 사용할 이미지를 저장
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