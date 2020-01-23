#pragma once
#include "Object.h"
class ShopStand :public Object
{
private:
	Vector2 _itemPos; //������ �̹��� ������ ��ǥ
	string _itemImgName; //�ö� ������ �̹��� ����
	//bool _isActive; //�θ� ���, �̹��� �ö󰡸� true ����


public:

	virtual void Init(Vector2 pos, Vector2 scale);
	virtual void Release()override;
	virtual void Update()override;
	virtual void Render()override;

	void ShowItem(); //������ �����ִ� �Լ�


	bool GetActive() { return _isActive; }
	void SetActive(bool isActive) { _isActive = isActive; }
	Vector2 GetItemPos() { return _itemPos; }
	void SetImgName(string itemImgName) { _itemImgName = itemImgName; }


};

