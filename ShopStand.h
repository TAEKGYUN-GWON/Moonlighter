#pragma once
#include "Object.h"
#include "Item.h"
#include"Maptool.h"

class ShopStand :public Object
{
private:
	Vector2 _itemPos; //아이템 이미지 보여줄 좌표
	string _itemImgName; //올라갈 아이템 이미지 네임
	//bool _isActive; //부모꺼 사용, 이미지 올라가면 true 상태
	Tile* _tiles[TILENUMX * TILENUMY];
	tagTile _tagTiles[TILENUMX * TILENUMY];
	Item* _item;

public:

	virtual void Init(Vector2 pos, Vector2 scale);
	virtual void Release()override;
	virtual void Update()override;
	virtual void Render()override;

	void ShowItem(); //아이템 보여주는 함수


	bool GetActive() { return _isActive; }
	void SetActive(bool isActive) { _isActive = isActive; }
	Vector2 GetItemPos() { return _itemPos; }

	//이미지 네임은 인벤토리에서 줘야 할 것 같음..
	void SetImgName(string itemImgName) { _itemImgName = itemImgName; }


};

