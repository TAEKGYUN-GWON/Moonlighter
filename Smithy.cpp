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

	_coin = GRAPHICMANAGER->AddImage("coin", L"resource/img/Smithy/Coin.png");

	_recipePrice = 100;
	_upgradeGap = 10;

	_player = (Player*)SCENEMANAGER->GetNowScene()->GetChildFromName("Will");

	_inven = new Inventory();
	_inven->Init();
	_inven->AddMoney(135948);
	_inven->SetATK(30);



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

	if (KEYMANAGER->isOnceKeyDown(VK_SPACE))
	{
		_inven->DeductionMoney(5000);
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

	_material1->Render(Vector2(WINSIZEX - 300, WINSIZEY - 260), 1, PIVOT::CENTER, false);
	_material2->Render(Vector2(WINSIZEX - 300, WINSIZEY - 170), 1, PIVOT::CENTER, false);
	_material3->Render(Vector2(WINSIZEX - 300, WINSIZEY - 80), 1, PIVOT::CENTER, false);
}

void Smithy::ShowUI()
{
	string standardStr;
	wstring printStr;

	ColorF* color = new ColorF(0xecddc0, 1.0f);

	GRAPHICMANAGER->Text(Vector2(WINSIZEX / 2 - 80, 30), L"벌컨의 대장간", 25, 200, 50, *color, TextPivot::LEFT_TOP, L"나눔스퀘어라운드");

	standardStr = to_string(_inven->GetATK());
	standardStr += " -> ";
	standardStr += to_string(_upgradeGap + _inven->GetATK());
	printStr.assign(standardStr.begin(), standardStr.end());

	GRAPHICMANAGER->DrawTextD2D(Vector2(WINSIZEX - 180, 190), standardStr.c_str(), 30, *color);

	color = new ColorF(0x191919, 1.f);
	GRAPHICMANAGER->Text(Vector2(WINSIZEX / 2 - 40, WINSIZEY / 2 - 100), L"강화하기", 50, 100, 50, *color, TextPivot::CENTER, L"나눔스퀘어라운드");

	GRAPHICMANAGER->Text(Vector2(WINSIZEX - 350, WINSIZEY / 2 + 10), L"레시피", 25, 100, 50, *color, TextPivot::CENTER, L"나눔스퀘어라운드");

	for (int i = 1; i <= 3; i++)
	{
		GRAPHICMANAGER->Text(Vector2(WINSIZEX - 280, WINSIZEY - 30 - (i * 90)), L"필요:", 20, 100, 50, *color, TextPivot::CENTER, L"나눔스퀘어라운드");
		GRAPHICMANAGER->Text(Vector2(WINSIZEX - 280, WINSIZEY - (i * 90)), L"소지:", 20, 100, 50, *color, TextPivot::CENTER, L"나눔스퀘어라운드");
	}


	standardStr = to_string(_inven->GetMoney());
	printStr.assign(standardStr.begin(), standardStr.end());
	color = new ColorF(0xffffff, 1.f);
	GRAPHICMANAGER->Text(Vector2(10, 125), printStr, 15, 100, 25, *color, TextPivot::CENTER, L"나눔스퀘어라운드");


	
}

string Smithy::PrintPrice(string price)
{
	string a = "a";

	return a;
}
