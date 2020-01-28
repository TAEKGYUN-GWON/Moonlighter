#include "stdafx.h"
#include "Smithy.h"

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
		_blackSmith->Render(Vector2(250, WINSIZEY / 2), 1, PIVOT::CENTER, false);
		_anvil->Render(Vector2(WINSIZEX / 2, WINSIZEY - 150), 1, PIVOT::CENTER, false);
		_title->Render(Vector2(WINSIZEX / 2, 50), 1, PIVOT::CENTER, false);
		_itemName->Render(Vector2(WINSIZEX - 200, 40), 1, PIVOT::CENTER, false);
		_upgradeRecipe->Render(Vector2(WINSIZEX - 200, WINSIZEY / 2 + 30), 1, PIVOT::CENTER, false);
		_itemList->Render(Vector2(WINSIZEX / 2, WINSIZEY / 2 - 80), 1, PIVOT::CENTER, false);
		

		ColorF* color = new ColorF(0x9135dd, 1.0f);
		GRAPHICMANAGER->Text(Vector2(WINSIZEX / 2 - 80, 30), L"¹úÄÁÀÇ ´ëÀå°£", 25, 200, 50, *color, TextPivot::LEFT_TOP, L"³ª´®½ºÄù¾î¶ó¿îµå", false);


		

		//GRAPHICMANAGER->Text(Vector2(WINSIZEX / 2 - 80, 30), L"¹úÄÁÀÇ ´ëÀå°£", 25, 200, 50, ColorF::HotPink, 1.0f, TextPivot::LEFT_TOP, L"±Ã¼­Ã¼", false);
	}

}

void Smithy::KeyInput()
{
	if (KEYMANAGER->isOnceKeyDown(VK_NUMPAD0))
	{
		_isShow = !_isShow;
	}
}
