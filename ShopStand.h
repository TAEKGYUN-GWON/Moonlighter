#pragma once
#include "Object.h"
#include "Item.h"

#include"Maptool.h"
#define SHOPTILEMAXX 22
#define SHOPTILEMAXY 28
class ShopScene;
class ShopStand :public Object
{
private:
	Vector2 _itemPos; //������ �̹��� ������ ��ǥ
	string _item; //�ö� ������ �̹��� ����
	//bool _isActive; //�θ� ���, �̹��� �ö󰡸� true ����
	Tile* _tiles[SHOPTILEMAXX * SHOPTILEMAXY];
	tagTile _tagTiles[SHOPTILEMAXX * SHOPTILEMAXY];
	//Item* _item;

	bool _isItemOn;

	bool _isInUse; //npc�� �浹�ؼ� ������̸� �������

public:

	virtual void Init(Vector2 pos, Vector2 scale);
	virtual void Release()override;
	virtual void Update()override;
	virtual void Render()override;

	//�̹��� ������ �κ��丮���� ��� �� �� ����..
	void SetItem(string item); //�÷��̾ ������ �����ϱ�
	void BuyItem();


	bool GetActive() { return _isActive; }
	void SetActive(bool isActive) { _isActive = isActive; }

	bool GetIsInUse() { return _isInUse; }
	void SetIsInUse(bool isinuse) { _isInUse = isinuse; }

	bool GetIsItemOn() { return _isItemOn; }
	Vector2 GetItemPos() { return _itemPos; }



};

