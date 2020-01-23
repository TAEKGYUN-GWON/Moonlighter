#include "stdafx.h"
#include "CheckStand.h"

void CheckStand::Init()
{

	_isInUse = false;

	_tag = "ShopObject";
	_name = "CheckStand";


	Object::Init();
}

void CheckStand::Release()
{

	Object::Release();
}

void CheckStand::Update()
{

	Object::Update();
}

void CheckStand::Render()
{

	Object::Render();
}
