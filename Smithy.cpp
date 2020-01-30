#include "stdafx.h"
#include "Smithy.h"
#include "Component.h"

void Smithy::Init()
{
	_blackSmith = GRAPHICMANAGER->AddImage("blackSmith", L"resource/img/Smithy/BlackSmith.png");
	_anvil = GRAPHICMANAGER->AddImage("anvil", L"resource/img/Smithy/Anvil.png");
	_title = GRAPHICMANAGER->AddImage("titleBass", L"resource/img/Smithy/Title_Bass.png");
	_itemName = GRAPHICMANAGER->AddImage("nameBass", L"resource/img/Smithy/Name_Bass.png");
	_upgradable = GRAPHICMANAGER->AddImage("upgradable", L"resource/img/Smithy/Upgradable.png");
	_notUpgradeble = GRAPHICMANAGER->AddImage("notUpgradable", L"resource/img/Smithy/NotUpgradable.png");
	_upgradeRecipe = GRAPHICMANAGER->AddImage("upgradeRecipe", L"resource/img/Smithy/Upgrade.png");
	_itemList = GRAPHICMANAGER->AddImage("itemList", L"resource/img/Smithy/Reinforce_ItemList.png");
	_pSword = GRAPHICMANAGER->AddImage("pSword", L"resource/img/Smithy/Will's_Sword.png");
	_pocket = GRAPHICMANAGER->AddImage("pocket", L"resource/img/Smithy/Gold5.png");
	_pocketCircle = GRAPHICMANAGER->AddImage("pocketCicle", L"resource/img/Smithy/Pocket_Circle.png");


	_material1 = GRAPHICMANAGER->AddImage("material1", L"resource/img/Smithy/material1.png");
	_material2 = GRAPHICMANAGER->AddImage("material2", L"resource/img/Smithy/material2.png");
	_material3 = GRAPHICMANAGER->AddImage("material3", L"resource/img/Smithy/material3.png");
	
	_mOn1 = GRAPHICMANAGER->AddImage("onCheck1", L"resource/img/Smithy/Upgradable.png");
	_mOn2 = GRAPHICMANAGER->AddImage("onCheck2", L"resource/img/Smithy/Upgradable.png");
	_mOn3 = GRAPHICMANAGER->AddImage("onCheck3", L"resource/img/Smithy/Upgradable.png");

	_coin = GRAPHICMANAGER->AddImage("coin", L"resource/img/Smithy/Coin.png");

	//_recipePrice = 100;
	_upgradeGap = 10;

	_player = (Player*)SCENEMANAGER->GetNowScene()->GetChildFromName("Will");

	_inven = new Inventory();
	_inven->Init();
	_inven->AddMoney(135948788);
	_inven->SetATK(30);

	_recipePrice = _inven->GetATK() / 10 * 0.4 * 2316;



	/*for (int i = 0; i < 3; i++)
	{
		_mRecipe.insert(make_pair(new Graphic(), 2));
	}*/

	_vMaterialCount.push_back(make_tuple(_material3->GetImageKey(), _mOn3->GetImageKey(), 2, _inven->FindItemSome(_mOn1->GetImageKey())));

	_vMaterialCount.push_back(make_tuple(_material2->GetImageKey(), _mOn2->GetImageKey(), 2, _inven->FindItemSome(_mOn1->GetImageKey())));
	_vMaterialCount.push_back(make_tuple(_material1->GetImageKey(), _mOn1->GetImageKey(), 2, _inven->FindItemSome(_mOn1->GetImageKey())));


	_isShow = false;
}

void Smithy::Update()
{
	KeyInput();
}

void Smithy::Release()
{
	
}

void Smithy::Render()
{
	if (_isShow)
	{
		ShowImage();
		ShowUI();
	}

}

void Smithy::KeyInput()
{
	if (KEYMANAGER->isOnceKeyDown(VK_NUMPAD0))
	{
		_isShow = !_isShow;
	}

	if (_isShow)
	{
		if (KEYMANAGER->isOnceKeyDown(VK_SPACE))
		{
			_inven->DeductionMoney(5000);
		}

		if (KEYMANAGER->isOnceKeyDown('U'))
		{
			Buy();
		}
	}
}

void Smithy::ShowImage()
{
	_blackSmith->Render(Vector2(250, WINSIZEY / 2), 1, PIVOT::CENTER, false);
	_anvil->Render(Vector2(WINSIZEX / 2, WINSIZEY - 150), 1, PIVOT::CENTER, false);
	_title->Render(Vector2(WINSIZEX / 2, 50), 1, PIVOT::CENTER, false);
	_itemName->Render(Vector2(WINSIZEX - 200, 40), 1, PIVOT::CENTER, false);
	_upgradeRecipe->Render(Vector2(WINSIZEX - 200, WINSIZEY / 2 + 30), 1, PIVOT::CENTER, false);
	_itemList->Render(Vector2(WINSIZEX / 2, WINSIZEY / 2 - 80), 1, PIVOT::CENTER, false);
	_pSword->Render(Vector2(WINSIZEX - 115, 110), 1, PIVOT::CENTER, false);
	_pocketCircle->Render(Vector2(60, 60), 1, PIVOT::CENTER, false);
	_pocket->Render(Vector2(60, 60), 1, PIVOT::CENTER, false);

	_coin->Render(Vector2(110, 140), 1, PIVOT::CENTER, false);


	for (int i = 2; i >= 0; i--)
	{
		GRAPHICMANAGER->FindImage(get<0>(_vMaterialCount[i]))->Render(Vector2(WINSIZEX - 300, WINSIZEY - (-10 + (i + 1) * 90)), 1, PIVOT::CENTER, false);
	}

	/*_material1->Render(Vector2(WINSIZEX - 300, WINSIZEY - 260), 1, PIVOT::CENTER, false);
	_material2->Render(Vector2(WINSIZEX - 300, WINSIZEY - 170), 1, PIVOT::CENTER, false);
	_material3->Render(Vector2(WINSIZEX - 300, WINSIZEY - 80), 1, PIVOT::CENTER, false);*/

	/*if (_inven->FindItemSome("Crystal_Energy") >= _cristal)
	{
		_mOn1->Render(Vector2(WINSIZEX - 89.5, WINSIZEY - 262.5), 1, PIVOT::CENTER, false);
	}
	if (_inven->FindItemSome("Reinforced_Steel_G") >= _iron)
	{
		_mOn2->Render(Vector2(WINSIZEX - 89.5, WINSIZEY - 176.5), 1, PIVOT::CENTER, false);
	}
	if (_inven->FindItemSome("Golem_Core") >= _core)
	{
		_mOn3->Render(Vector2(WINSIZEX - 89.5, WINSIZEY - 90.5), 1, PIVOT::CENTER, false);
	}*/

}

void Smithy::ShowUI()
{
	string standardStr;
	wstring printStr;

	ColorF* color = new ColorF(0xecddc0, 1.0f);

	GRAPHICMANAGER->Text(Vector2(WINSIZEX / 2 - 80, 30), L"������ ���尣", 25, 200, 50, *color, TextPivot::LEFT_TOP, L"�������������");

	standardStr = to_string(_inven->GetATK());
	standardStr += " -> ";
	standardStr += to_string(_upgradeGap + _inven->GetATK());
	printStr.assign(standardStr.begin(), standardStr.end());

	GRAPHICMANAGER->Text(Vector2(WINSIZEX - 370, 180), printStr, 30, 300, 50, *color, TextPivot::RIGHT_BOTTOM);

	color = new ColorF(0x191919, 1.f);
	GRAPHICMANAGER->Text(Vector2(WINSIZEX / 2 - 50, WINSIZEY / 2 - 100), L"��ȭ�ϱ�", 50, 100, 50, *color, TextPivot::CENTER, L"�������������");

	GRAPHICMANAGER->Text(Vector2(WINSIZEX - 350, WINSIZEY / 2 + 10), L"������", 25, 100, 50, *color, TextPivot::CENTER, L"�������������");

	standardStr = to_string(_recipePrice);
	printStr.assign(standardStr.begin(), standardStr.end());
	GRAPHICMANAGER->Text(Vector2(WINSIZEX - 200, WINSIZEY / 2 + 10), printStr, 25, 100, 50, *color, TextPivot::CENTER, L"�������������");

	standardStr = to_string(_inven->GetMoney());
	printStr.assign(standardStr.begin(), standardStr.end());
	color = new ColorF(0xffffff, 1.f);
	GRAPHICMANAGER->Text(Vector2(10, 125), printStr, 15, 100, 25, *color, TextPivot::CENTER, L"�������������");

	PrintRecipe();
	
}

void Smithy::Buy()
{
	if (_inven->GetMoney() >= _recipePrice)
	{
		_inven->DeductionMoney(_recipePrice);
		_inven->SetATK(_inven->GetATK() + _upgradeGap);
		Upgrade();
	}

}

void Smithy::Upgrade()
{

	_recipePrice = _inven->GetATK() / 10 * 0.4 * 2316;

	//_recipePrice *= 1.6;
	
	_upgradeGap *= 1.15;
}

void Smithy::PrintRecipe()
{
	ColorF* color = new ColorF(0x191919, 1.f);

	for (int i = 0; i <= 2; i++)
	{
		//GRAPHICMANAGER->FindImage(get<0>(_vMaterialCount[i]))->Render(Vector2(WINSIZEX - 300, WINSIZEY - (-10 + (i + 1) * 90)), 1, PIVOT::CENTER, false);

		GRAPHICMANAGER->Text(Vector2(WINSIZEX - 280, WINSIZEY - 30 - ((i+1) * 90)), L"�ʿ�:", 20, 100, 50, *color, TextPivot::CENTER, L"�������������");
		GRAPHICMANAGER->Text(Vector2(WINSIZEX - 280, WINSIZEY - ((i+1) * 90)), L"����:", 20, 100, 50, *color, TextPivot::CENTER, L"�������������");

	//	_vMaterialCount[i]

	}
}