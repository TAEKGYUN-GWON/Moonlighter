#include "stdafx.h"
#include "ShopScene.h"

void ShopScene::Init()
{
	Scene::Init();

	_trans->SetPos(Vector2(WINSIZEX / 2, WINSIZEY / 2));

	//��� �̹��� �߰�
	GRAPHICMANAGER->AddImage("Shop", L"resource/img/Shop/shop_background.png");
	////�� ������Ʈ �̹���
	//GRAPHICMANAGER->AddImage("bed", L"resource/img/Shop/room_bed.png");
	//GRAPHICMANAGER->AddImage("carpet", L"resource/img/Shop/room_bed_carpet.png");
	//GRAPHICMANAGER->AddImage("chest", L"resource/img/Shop/room_bed_chest.png");
	//GRAPHICMANAGER->AddImage("shoes", L"resource/img/Shop/room_shoes.png");
	//GRAPHICMANAGER->AddImage("stove", L"resource/img/Shop/room_stove.png");
	//GRAPHICMANAGER->AddImage("table", L"resource/img/Shop/room_table.png");
	//GRAPHICMANAGER->AddImage("chest", L"resource/img/Shop/room_chest.png");
	////���� ������Ʈ �̹���
	//GRAPHICMANAGER->AddImage("entrance_carpet", L"resource/img/Shop/shop_entrance_carpet.png");
	//GRAPHICMANAGER->AddImage("sell_table", L"resource/img/Shop/shop_sell_table.png");
	//GRAPHICMANAGER->AddImage("shop_stove", L"resource/img/Shop/shop_stove.png");
	//GRAPHICMANAGER->AddImage("main_table", L"resource/img/Shop/shop_main_table.png");
	////���� ������ �̹���
	//GRAPHICMANAGER->AddFrameImage("", L"resource/img/Shop/shop_cash_register_close.png", 2, 1);
	//GRAPHICMANAGER->AddFrameImage("", L"resource/img/Shop/shop_cash_register_open.png", 9, 1);
	//GRAPHICMANAGER->AddFrameImage("", L"resource/img/Shop/shop_cauldron.png", 6, 1);
	//GRAPHICMANAGER->AddFrameImage("", L"resource/img/Shop/shop_door.png", 5, 1);
	//GRAPHICMANAGER->AddFrameImage("", L"resource/img/Shop/will_getup.png", 58, 1);

	//Object* obj = Object::CreateObject<Object>(); //�Ű������� �ȳ־����Ƿ� ������ �ͼӵǴ� ������Ʈ��

	CAMERA->SetScale(Vector2(2.f, 1.f));
}

void ShopScene::Update()
{

	Scene::Update();
}

void ShopScene::Render()
{
	Scene::Render();
	//���� ���
	GRAPHICMANAGER->FindImage("Shop")->Render(_trans->GetPos(), CENTER);
}
