#include "stdafx.h"
#include "ShopStand.h"
#include "Transform.h"
#include "Sprite.h"
#include"ShopScene.h"

void ShopStand::Init(Vector2 pos, Vector2 scale)
{
	_tag = "ShopObject";

	//���Ǵ��� ��Ʈ �����
	_trans->SetPos(pos);
	_trans->SetScale(scale);


	_itemPos = _trans->GetPos(); //�̰� �������� ���� �𸣰ڴ�..
	//�ھ����� �̹��� ������(_itemImgName) ������� SetImgName���� ����

	_isInUse = false;
	_isItemOn = false;
}

void ShopStand::Release()
{

	Object::Release();
}

void ShopStand::Update()
{

	//BuyItem();

	Object::Update();
}

void ShopStand::Render()
{
	GRAPHICMANAGER->DrawEllipse(
		_trans->GetPos().x, _trans->GetPos().y, 
		_trans->GetScale().x+10, _trans->GetScale().y+10);

	Object::Render();
}

void ShopStand::SetItem(string item)
{
	_item = item;
	_isItemOn = true;
}

void ShopStand::BuyItem()
{
	//������ ���
	_isItemOn = false; //������ ����
}

