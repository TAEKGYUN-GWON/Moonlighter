#include "stdafx.h"
#include "ShopStand.h"
#include "Transform.h"


void ShopStand::Init(Vector2 pos, Vector2 scale)
{
	_tag = "ShopObject";
	_name = "ShopStand";

	//가판대의 렉트 만들기
	_trans->SetPos(pos);
	_trans->SetScale(scale);
	

	AddComponent<Sprite>();
	//여기부터 몰겠다 나중에 하겠음
	//_sprite->SetImgName("");
	

	_itemPos = _trans->GetPos(); //이게 센터인지 뭔지 모르겠다..
	//★아이템 이미지 네임은(_itemImgName) 헤더에서 SetImgName으로 받음
}

void ShopStand::Release()
{

	Object::Release();
}

void ShopStand::Update()
{

	ShowItem();
	Object::Update();
}

void ShopStand::Render()
{

	Object::Render();
}

void ShopStand::ShowItem()
{
	if (_isActive) //살아있는상태면
	{
		//그려.
	}
}
