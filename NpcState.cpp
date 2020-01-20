#include "stdafx.h"
#include "NpcState.h"


//★이부분 뭔지 모르겠음 일단 있어서 베낌
NpcStateIdle* NpcStateIdle::instance;
NpcStateDecide* NpcStateDecide::instance;
NpcStateInline* NpcStateInline::instance;
NpcStateGoHome* NpcStateGoHome::instance;

//======================IDLE 상태===========================

NpcStateIdle* NpcStateIdle::GetInstance()
{
	if (instance == nullptr)
	{
		instance = new NpcStateIdle(); //★ 
	}
	return instance;
}

void NpcStateIdle::NotBuyStuffs(Npc* npc)
{
	cout << "이런건 없음" << endl;
}

void NpcStateIdle::Act(Npc* npc)
{
	//테이블 vector 돌려서 _isActive = false 인 테이블을 찾는다
	//찾았으면 그 테이블 앞으로 이동한다
	//이동 완료하면 _npcState = Decide 가 되어야함

	//SetNpcState(npc, NpcStateDecide); //이렇게 해주면 될듯..

	//살지 말지 결정은 어디에서 해줘야함?
	//Npc.cpp의 update에서 해주겠음 일단
}

void NpcStateIdle::GoHome(Npc* npc)
{
	//SetNpcState(npc, NpcStateGoHome); //고홈 상태로 바꿈
}
//======================Search 상태===========================
NpcStateDecide* NpcStateDecide::GetInstance()
{
	if (instance == nullptr)
	{
		instance = new NpcStateDecide();
	}
	return instance;
}

void NpcStateDecide::NotBuyStuffs(Npc* npc)
{
	//안사기로 한것임
	//문앞으로 이동하고
	//SetNpcState(npc, NpcStateIdle);
	//이거하고 랜덤숫자로 카운터를 돌린다
	//카운터가 다되면 Idle->Act 상태로 가야함
	//집에는 안가, 집에가는건 따로..
}

void NpcStateDecide::Act(Npc* npc)
{
	//구매하기로 결심한것임
	//테이블에 있던 아이템 좌표가 캐릭터한테 붙어야함
	//_shopStand->SetActive(false); //테이블을 inactivate 해줌

}

void NpcStateDecide::GoHome(Npc* npc)
{
}
//======================Inline 상태===========================
NpcStateInline* NpcStateInline::GetInstance()
{
	if (instance == nullptr)
	{
		instance = new NpcStateInline();
	}
	return instance;
}

void NpcStateInline::NotBuyStuffs(Npc* npc)
{
	cout << "일어날 수 없는 일임" << endl;
}

void NpcStateInline::Act(Npc* npc)
{
	//Idle 상대로 바껴야함
	//계산이 끝났으니까 줄서기가 된거임
	//플레이어가 J눌러서 허락해줬을 때 Inline::Act 로 들어와야함
	//혹은 플레이어가 너무 안눌러줬을떄 자동으로 들어와야되는데, 구현 안해도 아무도 모름
	//SetNpcState(npc, NpcStateIdle);
}

void NpcStateInline::GoHome(Npc* npc)
{
	cout << "이런일은 일어날 수 없다.." << endl;
}
//======================GoHome 상태===========================
NpcStateGoHome* NpcStateGoHome::GetInstance()
{
	if (instance == nullptr)
	{
		instance = new NpcStateGoHome();
	}
	return instance;
}

void NpcStateGoHome::NotBuyStuffs(Npc* npc)
{
	cout << "이 상태에서는 행동이 없음" << endl;
}

void NpcStateGoHome::Act(Npc* npc)
{
	cout << "이 상태에서는 행동이 없음" << endl;
}

void NpcStateGoHome::GoHome(Npc* npc)
{
	cout << "이 상태에서는 행동이 없음" << endl;
}
