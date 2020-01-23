#include "stdafx.h"
#include "ShopStand.h"
#include "Transform.h"

void ShopStand::Init(Vector2 pos, Vector2 scale)
{
	_tag = "ShopObject";
	_name = "ShopStand";

	_trans->SetPos(pos);
	_trans->SetScale(scale);// 이런거 해줘야함

	_itemPos = Vector2(0, 0); //나중에 바꿔줘야함 데스크 좌표의 가운데로
	_itemImgName = ""; //이거 어떡함 아이템 어떻게 관리할지 모르겠음
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
