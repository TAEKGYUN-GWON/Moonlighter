#include "stdafx.h"
#include "Potions.h"

void Potion_L::Init(Vector2 pos)
{

	super::Init();

	_trans->SetPos(pos);
	_name = "Potion_L";
	SetHealRate(30);

	_image = AddComponent<Sprite>();
	_image->SetImgName("Potion_L");
}

void Potion_S::Init(Vector2 pos)
{

	super::Init();

	_trans->SetPos(pos);
	_name = "Potion_S";
	SetHealRate(10);
	_image = AddComponent<Sprite>();
	_image->SetImgName("Potion_S");


	_trans->SetScale(_image->GetGraphic()->GetWidth(), _image->GetGraphic()->GetHeight());
}
