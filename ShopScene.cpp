#include "stdafx.h"
#include "ShopScene.h"

void ShopScene::Init()
{
	Scene::Init();


	GRAPHICMANAGER->AddImage("Shop", L"shop_background");
	//이미지 렌더
}

void ShopScene::Update()
{
	Scene::Update();
}
