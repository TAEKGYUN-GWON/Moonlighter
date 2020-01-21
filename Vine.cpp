#include "stdafx.h"
#include "Vine.h"


Vine::Vine()
{
}


Vine::~Vine()
{
}


void Vine::Init()
{
	super::Init();

	_name = "Vine";

	_image = AddComponent<Sprite>();
	_image->SetImgName("Items");
	_image->SetFrameX(3);
	_image->SetFrameY(2);
}