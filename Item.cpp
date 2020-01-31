#include "stdafx.h"
#include "Item.h"
#include "Potion.h"

void Item::Init()
{
	_tag = "Item";
	_maxCount = 1;
	_price = 0;
	_followingMovement = 0;

}

void Item::Update()
{
	super::Update();

	if (_isDungeon)
		//부모를 통해 플레이어를 찾아 좌표를 받아옴
		FollowPlayer(_parent->GetChildFromName("Will")->GetTrans()->GetPos());

	for (auto a : _draw)
	{
		Sprite* b = (Sprite*)a;
		b->SetPosition(_trans->GetPos());

	}
}

void Item::FollowPlayer(Vector2 playerPos)
{
	_followingMovement += .16f;

	_trans->SetPos(Vector2::Lerp(_trans->GetPos(), playerPos, _followingMovement));
	
}
