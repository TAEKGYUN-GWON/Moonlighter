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

	if (_isDungeon) ;
		//플레이어가 만들어지면 플레이어의 좌표를 얻어올꺼임
		//FollowPlayer();

}

void Item::FollowPlayer(Vector2 playerPos)
{
	_followingMovement += .1f;

	_trans->SetPos(Vector2::Lerp(_trans->GetPos(), playerPos, _followingMovement));
}
