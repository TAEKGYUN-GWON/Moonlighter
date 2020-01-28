#pragma once

#include "Item.h"
#include "Object.h"


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

	//���尣�� �������ϱ�?
	bool _isShow;

public:

	void Init();
	void Update();
	void Release();
	void Render();

	void KeyInput();

};

