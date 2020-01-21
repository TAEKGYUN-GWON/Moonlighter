#include "stdafx.h"
#include "Potions.h"

void Potion_L::Init(Vector2 pos)
{

	super::Init();

	_trans->SetPos(pos);
	_name = "Potion_L";
	_maxCount = 5;

	_image = AddComponent<Sprite>();
	//_image->SetImgName("")
}

void Potion_S::Init(Vector2 pos)
{

	super::Init();

	_trans->SetPos(pos);
	_name = "Potion_S";
	_maxCount = 5;

	_image = AddComponent<Sprite>();
	_image->SetImgName("\resource\img\Items\Potion_S");
}
