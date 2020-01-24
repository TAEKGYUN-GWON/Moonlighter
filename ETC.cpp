#include "stdafx.h"
#include "ETC.h"

void ETC::Init()
{
	super::Init();

	_tag = "ETC";
	_type = EItemType::etc;
	_maxCount = 10;
}

void ETC::Update()
{
	super::Update();
}
