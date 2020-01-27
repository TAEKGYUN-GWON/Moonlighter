#include "stdafx.h"
#include "ShopDoor.h"

void ShopDoor::Init()
{
	Object::Init();

	_tag = "ShopObject";
	_name = "ShopDoor";

	_sprite = AddComponent<Sprite>();
	_sprite->Init(true, true);
	_sprite->SetImgName("Door");

	_trans->SetPos(Vector2(396, 745));
	_trans->SetScale(Vector2(
		GRAPHICMANAGER->FindImage("Door")->GetFrameWidth(),
		GRAPHICMANAGER->FindImage("Door")->GetFrameHeight()));
}

void ShopDoor::Update()
{
	Object::Update();


}



