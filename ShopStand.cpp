#include "stdafx.h"
#include "ShopStand.h"
#include "Transform.h"

void ShopStand::Init(Vector2 pos, Vector2 scale)
{
	_tag = "ShopObject";
	_name = "ShopStand";

	_trans->SetPos(pos);
	_trans->SetScale(scale);// �̷��� �������

	_itemPos = Vector2(0, 0); //���߿� �ٲ������ ����ũ ��ǥ�� �����
	_itemImgName = ""; //�̰� ��� ������ ��� �������� �𸣰���
}

void ShopStand::Release()
{
}

void ShopStand::Update()
{
}

void ShopStand::Render()
{
}

void ShopStand::ShowItem()
{
}
