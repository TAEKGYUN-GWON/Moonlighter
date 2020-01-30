#include "stdafx.h"
#include "Smithy.h"
#include "Component.h"
#include "ETCS.h"

void Smithy::Init(Inventory* inven)
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


	_material1 = GRAPHICMANAGER->AddImage("crystal_Energy", L"resource/img/Smithy/material1.png");
	_material2 = GRAPHICMANAGER->AddImage("reinforced_Steel_G", L"resource/img/Smithy/material2.png");
	_material3 = GRAPHICMANAGER->AddImage("golem_Core", L"resource/img/Smithy/material3.png");
	
	_mOn1 = GRAPHICMANAGER->AddImage("onCheck1", L"resource/img/Smithy/Upgradable.png");
	_mOn2 = GRAPHICMANAGER->AddImage("onCheck2", L"resource/img/Smithy/Upgradable.png");
	_mOn3 = GRAPHICMANAGER->AddImage("onCheck3", L"resource/img/Smithy/Upgradable.png");

	_coin = GRAPHICMANAGER->AddImage("coin", L"resource/img/Smithy/Coin.png");

	//_recipePrice = 100;
	_upgradeGap = 10;

	_player = (Player*)SCENEMANAGER->GetNowScene()->GetChildFromName("Will");

	//_inven = new Inventory();
	_inven = inven;
	//_inven->Init();
	//_inven->AddMoney(135948788);
	//_inven->SetATK(30);

	_recipePrice = _inven->GetATK() / 10 * 0.4 * 2316;



	/*for (int i = 0; i < 3; i++)
	{
		_mRecipe.insert(make_pair(new Graphic(), 2));
	}*/



	_isShow = false;
}

void Smithy::Update()
{
	KeyInput();

	_vMaterialCount.push_back(make_tuple(_material3->GetImageKey(), _mOn3->GetImageKey(), 2, _inven->FindItemSome(_material1->GetImageKey())));
	_vMaterialCount.push_back(make_tuple(_material2->GetImageKey(), _mOn2->GetImageKey(), 2, _inven->FindItemSome(_material2->GetImageKey())));
	_vMaterialCount.push_back(make_tuple(_material1->GetImageKey(), _mOn1->GetImageKey(), 2, _inven->FindItemSome(_material3->GetImageKey())));
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

	//Å©¸®½ºÅ»
	if (get<2>(_vMaterialCount[0]) <= get<3>(_vMaterialCount[0]))
	{
		GRAPHICMANAGER->FindImage(get<1>(_vMaterialCount[0]))->Render(Vector2(WINSIZEX - 89.5, WINSIZEY - 262.5), 1, PIVOT::CENTER, false);
	}

	//°­Ã¶
	if (get<2>(_vMaterialCount[1]) <= get<3>(_vMaterialCount[1]))
	{
		GRAPHICMANAGER->FindImage(get<1>(_vMaterialCount[1]))->Render(Vector2(WINSIZEX - 89.5, WINSIZEY - 262.5), 1, PIVOT::CENTER, false);
		_mOn2->Render(Vector2(WINSIZEX - 89.5, WINSIZEY - 176.5), 1, PIVOT::CENTER, false);
	}

	//ÄÚ¾î
	if (get<2>(_vMaterialCount[2]) <= get<3>(_vMaterialCount[2]))
	{
		GRAPHICMANAGER->FindImage(get<1>(_vMaterialCount[2]))->Render(Vector2(WINSIZEX - 89.5, WINSIZEY - 262.5), 1, PIVOT::CENTER, false);
		_mOn3->Render(Vector2(WINSIZEX - 89.5, WINSIZEY - 90.5), 1, PIVOT::CENTER, false);
	}

}

void Smithy::ShowUI()
{

	ColorF* color = new ColorF(0xecddc0, 1.0f);

	GRAPHICMANAGER->Text(Vector2(WINSIZEX / 2 - 80, 30), L"¹úÄÁÀÇ ´ëÀå°£", 25, 200, 50, *color, TextPivot::LEFT_TOP, L"³ª´®½ºÄù¾î¶ó¿îµå");

	standardStr = to_string(_inven->GetATK());
	standardStr += " -> ";
	standardStr += to_string(_upgradeGap + _inven->GetATK());
	printStr.assign(standardStr.begin(), standardStr.end());

	GRAPHICMANAGER->Text(Vector2(WINSIZEX - 370, 180), printStr, 30, 300, 50, *color, TextPivot::RIGHT_BOTTOM);

	color = new ColorF(0x191919, 1.f);
	GRAPHICMANAGER->Text(Vector2(WINSIZEX / 2 - 50, WINSIZEY / 2 - 100), L"°­È­ÇÏ±â", 50, 100, 50, *color, TextPivot::CENTER, L"³ª´®½ºÄù¾î¶ó¿îµå");

	GRAPHICMANAGER->Text(Vector2(WINSIZEX - 350, WINSIZEY / 2 + 10), L"·¹½ÃÇÇ", 25, 100, 50, *color, TextPivot::CENTER, L"³ª´®½ºÄù¾î¶ó¿îµå");

	standardStr = to_string(_recipePrice);
	printStr.assign(standardStr.begin(), standardStr.end());
	GRAPHICMANAGER->Text(Vector2(WINSIZEX - 200, WINSIZEY / 2 + 10), printStr, 25, 100, 50, *color, TextPivot::CENTER, L"³ª´®½ºÄù¾î¶ó¿îµå");

	standardStr = to_string(_inven->GetMoney());
	printStr.assign(standardStr.begin(), standardStr.end());
	color = new ColorF(0xffffff, 1.f);
	GRAPHICMANAGER->Text(Vector2(10, 125), printStr, 15, 100, 25, *color, TextPivot::CENTER, L"³ª´®½ºÄù¾î¶ó¿îµå");

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

		GRAPHICMANAGER->Text(Vector2(WINSIZEX - 280, WINSIZEY - 30 - ((i+1) * 90)), L"ÇÊ¿ä:", 20, 100, 50, *color, TextPivot::CENTER, L"³ª´®½ºÄù¾î¶ó¿îµå");
		GRAPHICMANAGER->Text(Vector2(WINSIZEX - 280, WINSIZEY - ((i+1) * 90)), L"¼ÒÁö:", 20, 100, 50, *color, TextPivot::CENTER, L"³ª´®½ºÄù¾î¶ó¿îµå");

		standardStr = to_string(get<3>(_vMaterialCount[i]));
		printStr.assign(standardStr.begin(), standardStr.end());
		GRAPHICMANAGER->Text(Vector2(WINSIZEX - 230, WINSIZEY - (-10 + (i + 1) * 90)), printStr, 20, 100, 25, *color, TextPivot::RIGHT_CENTER, L"³ª´®½ºÄù¾î¶ó¿îµå");
		
		standardStr = to_string(get<2>(_vMaterialCount[i]));
		printStr.assign(standardStr.begin(), standardStr.end());
		GRAPHICMANAGER->Text(Vector2(WINSIZEX - 230, WINSIZEY - (20 + (i + 1) *90)), printStr, 20, 100, 25, *color, TextPivot::RIGHT_CENTER, L"³ª´®½ºÄù¾î¶ó¿îµå");





	}
}