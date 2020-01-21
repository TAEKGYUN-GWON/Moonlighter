#include "stdafx.h"
#include "ETCS.h"


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
	_image->SetImgName("\resource\img\Items\Items");
	_image->SetFrameX(3);
	_image->SetFrameY(2);
}