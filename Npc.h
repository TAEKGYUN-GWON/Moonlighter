#pragma once
#include "Object.h"
#include "ShopStand.h"

enum NPCSTATE
{
	NPCIDLE,		 //���
	NPCSEARCHING,	 //���Ǵ� Ž��
	NPCINLINE,		 //���� ��� �ټ���
	NPCOUT			 //������
};
class Npc :	public Object
{
private:
	NPCSTATE _npcState;
	ShopStand* _shopStand;



public:



};

