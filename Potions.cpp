#include "stdafx.h"
#include "Potions.h"

void Potion_L::Init(Vector2 pos)
{

	super::Init();

	_trans->SetPos(pos);
	_type = EItemType::useable;
	_name = "Potion_L";

	_image = AddComponent<Sprite>();
	//_image->SetImgName("")
}

void Potion_S::Init(Vector2 pos)
{

	super::Init();

	_trans->SetPos(pos);
	_type = EItemType::useable;
	_name = "Potion_S";

	_image = AddComponent<Sprite>();
	//_image->SetImgName("")
}
