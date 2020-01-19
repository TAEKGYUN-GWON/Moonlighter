#pragma once
#include "Object.h"
#include "ShopStand.h"
#include "NpcState.h"

class Npc :	public Object
{
private:
	ShopStand* _shopStand;
	NpcState* _npcState;



public:

	virtual void Init() override;
	virtual void Release() override;
	virtual void Update() override;
	virtual void Render() override;

	void SetState(NpcState* npcstate);	//상태 정의 //왜 Npc*로 받는지 잘 모르겠음 베꼈음
	void BuyStuffs();	//물건 사기 행동
	void NotBuyStuffs();//물건 안사기 행동
	void Move();		//이동 행동 (상태에 따라 바껴야함)
	void GoHome();		//집에 가기 행동


};

