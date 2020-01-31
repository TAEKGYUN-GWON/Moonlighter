#include "stdafx.h"
#include "ETC.h"

void ETC::Init()
{
	super::Init();

	_tag = "ETC";
	_type = EItemType::etc;
	_maxCount = 10;
	_image->SetPosition(_trans->GetPos());
}

void ETC::Update()
{
	super::Update();
}
