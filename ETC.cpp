#include "stdafx.h"
#include "ETC.h"

void ETC::Init()
{
	super::Init();

	_tag = "ETC";
	_type = EItemType::etc;
	_maxCount = 10;
	_image = AddComponent<Sprite>();
	_image->Init();
}

void ETC::Update()
{
	super::Update();
}
