#include "stdafx.h"
#include "CheckStand.h"
#include "Transform.h"

void CheckStand::Init(Vector2 pos, Vector2 scale)
{

	_isInUse = false;

	_tag = "ShopObject";
	_name = "CheckStand";

	//���Ǵ��� ��Ʈ �����
	_trans->SetPos(pos);
	_trans->SetScale(scale);


	AddComponent<Sprite>();

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
