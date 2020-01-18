#pragma once
#include "Object.h"
#include "ShopStand.h"

enum NPCSTATE
{
	NPCIDLE,		 //대기
	NPCSEARCHING,	 //가판대 탐색
	NPCINLINE,		 //물건 골라서 줄서기
	NPCOUT			 //나가기
};
class Npc :	public Object
{
private:
	NPCSTATE _npcState;
	ShopStand* _shopStand;



public:



};

