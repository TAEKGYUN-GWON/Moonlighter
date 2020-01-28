#include "stdafx.h"
#include "ShopStandManager.h"

void ShopStandManager::Init()
{

	//1사분면부터 반시계 방향으로 1, 2, 3, 4순서로 들어감.
	{
		_shopStand = Object::CreateObject<ShopStand>();
		_shopStand->Init(Vector2(263, 573), Vector2(25, 25));
		_shopStand->SetIsInUse(false);
		

		_vShopStand.push_back(_shopStand);
	}
	{
		_shopStand = Object::CreateObject<ShopStand>();
		_shopStand->Init(Vector2(213, 573), Vector2(25, 25));
		_shopStand->SetIsInUse(false);

		_vShopStand.push_back(_shopStand);
	}
	{
		_shopStand = Object::CreateObject<ShopStand>();
		_shopStand->Init(Vector2(213, 623), Vector2(25, 25));
		_shopStand->SetIsInUse(false);

		_vShopStand.push_back(_shopStand);
	}
	{
		_shopStand = Object::CreateObject<ShopStand>();
		_shopStand->Init(Vector2(263, 623), Vector2(25, 25));
		_shopStand->SetIsInUse(false);

		_vShopStand.push_back(_shopStand);
	}
}

void ShopStandManager::Release()
{
}

void ShopStandManager::Update()
{
}
