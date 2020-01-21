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
	int _price, _maxCount;

	//�������� ����� �̹����� ����
	Sprite* _image;

public:
	Item() {}
	~Item() {}

	virtual void Init();
	virtual void Init(Vector2 pos) = 0;
	virtual void Update();

	//Get Something
	int GetMaxCount() { return _maxCount; }
	int GetPrice() { return _price; }
	Vector2 GetPos() { return _trans->GetPos(); }
	EItemType GetType() { return _type; }

	//Set Something
	//void SetItemCount(int count) {
	//	_MaxCount += count;
	//}

	void SetPrice(int price) {
		_price = price;
	}

	void setPos(Vector2 pos) { _trans->SetPos(pos); }

	template <typename T>
	static T* CreateItem(Vector2 pos);

};

#include"Item.hpp"