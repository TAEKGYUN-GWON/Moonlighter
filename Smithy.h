#pragma once

#include "Item.h"
#include "Object.h"

#include <vector>

#include "Inventory.h"
#include "Player.h"

#include <tuple>


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

	Graphic* _mOn1;
	Graphic* _mOn2;
	Graphic* _mOn3;

	string standardStr;
	wstring printStr;

	//���尣�� �������ϱ�?
	bool _isShow;

	Inventory* _inven;
	Player* _player;
	
	int _recipePrice;
	int _upgradeGap;
	
	/*���
	ũ����Ż ������
	�ʷ� ��ö
	���� �ھ�
	*/

	//map<Graphic*, int> _mRecipe;

	tuple<string, int, int> a;

	vector<tuple<string, string, int, int>> _vMaterialCount;
	

public:

	void Init(Inventory* inven);
	void Update();
	void Release();
	void Render();


	void KeyInput();

	void ShowImage();
	void ShowUI();

	void Buy();
	void Upgrade();



	void PrintRecipe();

};

