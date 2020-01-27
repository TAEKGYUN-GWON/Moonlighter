#include "stdafx.h"
#include "ShopStandManager.h"

void ShopStandManager::Init()
{
	//여기서 푸시백 네번 해줄거다..
	{
		_shopStand = Object::CreateObject<ShopStand>();
		_shopStand->Init(Vector2(263, 573), Vector2(25, 25));

		_vShopStand.push_back(_shopStand);
	}
	{
		_shopStand = Object::CreateObject<ShopStand>();
		_shopStand->Init(Vector2(213, 573), Vector2(25, 25));

		_vShopStand.push_back(_shopStand);
	}
	{
		_shopStand = Object::CreateObject<ShopStand>();
		_shopStand->Init(Vector2(213, 623), Vector2(25, 25));

		_vShopStand.push_back(_shopStand);
	}
	{
		_shopStand = Object::CreateObject<ShopStand>();
		_shopStand->Init(Vector2(263, 623), Vector2(25, 25));

		_vShopStand.push_back(_shopStand);
	}
}

void ShopStandManager::Release()
{
}

void ShopStandManager::Update()
{
}
