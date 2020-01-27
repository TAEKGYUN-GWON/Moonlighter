#pragma once
#include "ShopStand.h"

class ShopStandManager
{
private:
	
	ShopStand* _shopStand;
	vector<ShopStand*> _vShopStand;


public:
	void Init();
	void Release();
	void Update();


};

