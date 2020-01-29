#pragma once

#include "Item.h"
#include "Object.h"

#include "Inventory.h"
#include "Player.h"


class Smithy
{
private:

	Graphic* _blackSmith;
	Graphic* _anvil;
	Graphic* _title;
	Graphic* _itemName;
	Graphic* _upgradable;
	Graphic* _notUpgradeble;
	Graphic* _upgradeRecipe;
	Graphic* _itemList;
	Graphic* _pSword;

	Graphic* _pocket;
	Graphic* _pocketCircle;
	Graphic* _coin;

	Graphic* _material1;
	Graphic* _material2;
	Graphic* _material3;



	//대장간이 켜졌습니까?
	bool _isShow;

	Inventory* _inven;
	Player* _player;
	
	int _recipePrice;
	int _upgradeGap;

	/*재료
	크리스탈 에너지
	초록 강철
	골렘의 코어
	*/

public:

	void Init();
	void Update();
	void Release();
	void Render();


	void KeyInput();

	void ShowImage();
	void ShowUI();


	string PrintPrice(string price);

};

