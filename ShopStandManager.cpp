#include "stdafx.h"
#include "ShopStandManager.h"

void ShopStandManager::Init()
{
	//여기서 푸시백 네번 해줄거다..
	for (int i = 0; i < 4; i++)
	{


		_vShopStand.push_back(_shopStand);
	}

}

void ShopStandManager::Release()
{
}

void ShopStandManager::Update()
{
}
