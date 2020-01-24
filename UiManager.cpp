#include "stdafx.h"
#include "UiManager.h"

void UiManager::Init()
{
	_coin = GRAPHICMANAGER->AddImage("coin", L"resource/img/UI/coin.png");
	_bag = GRAPHICMANAGER->AddImage("moneyBag", L"resource/img/UI/moneyBag.png");
	_bagButton = GRAPHICMANAGER->AddImage("UI_Bag", L"resource/img/UI/UI_Bag.png");
	_potionButton = GRAPHICMANAGER->AddImage("UI_Potion", L"resource/img/UI/UI_Potion.png");
	_heart = GRAPHICMANAGER->AddImage("heart", L"resource/img/UI/heart.png");
	_heart = GRAPHICMANAGER->AddImage("heart", L"resource/img/UI/heart.png");
	_weapon = GRAPHICMANAGER->AddFrameImage("UI_WeaponSwap", L"resource/img/UI/UI_WeaponSwap.png",4,2);
}

void UiManager::Update()
{
}

void UiManager::Render()
{
	_bag->Render(Vector2(54, 58.5f), 1, PIVOT::CENTER, false);
	_heart->Render(Vector2(132, 46), 1, PIVOT::CENTER, false);
	_coin->Render(Vector2(25.5f, 114), 1, PIVOT::CENTER, false);
	_potionButton->Render(Vector2(1243.5, 30), 1, PIVOT::CENTER, false);
	_bagButton->Render(Vector2(1210, 207), 1, PIVOT::CENTER, false);
	_weapon->FrameRender(Vector2(1150.f, 103), 0, 0, 1, PIVOT::CENTER, false);
}
