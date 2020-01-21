#include "stdafx.h"
#include "NpcState.h"
#include "Npc.h"

NpcIdle* NpcIdle::instance;
NpcDecide* NpcDecide::instance;
NpcInline* NpcInline::instance;
NpcExit* NpcExit::instance;

NpcIdle* NpcIdle::GetInstance()
{
	if (instance == nullptr)
	{
		instance = new NpcIdle();
	}
	return instance;
}

//==================대기=====================
void NpcIdle::StateIn(Npc* npc)
{
	//일단 여기로 들어와야하므로 조건 없이 들여보내줘야함..
	//길을 찾는다
	//창가로 보낸다
	//창가에 사람이 있으면 옆칸으로 보낸다
}

void NpcIdle::StateStay(Npc* npc)
{
	//if ()//창가 자리에 도착하면
	{
		_counter++; //시작해서
		if (_counter > RND->getFromIntTo(300, 1000)) //대기시간 거쳐서
		{
			StateOut(npc); //IDLE상태에서 내보낸다
		}

	}
}

void NpcIdle::StateOut(Npc* npc)
{
	//이제 EXIT랑 DECIDE 중 어느 상태로 갈지 정해야함
	int a = RND->getInt(4);

	if (a < 3 && a >= 0) //0, 1, 2일 때
	{
		_npc->SetNpcState(NpcIdle::GetInstance());//IDLE 상태로 만듦
	}
	else if (a == 3) //3일 때
	{
		_npc->SetNpcState(NpcExit::GetInstance()); //EXIT 상태로 만듦
	}
}

NpcDecide* NpcDecide::GetInstance()
{
	if (instance == nullptr)
	{
		instance = new NpcDecide();
	}
	return instance;
}

//==================살말=====================
void NpcDecide::StateIn(Npc* npc)
{
	//들어와서 할거 없음.. 바로 stay 불러
	StateStay(npc);
}

void NpcDecide::StateStay(Npc* npc)
{
	//머무르면서도 할거 없음.. 그냥 나가
	StateOut(npc);
}

void NpcDecide::StateOut(Npc* npc)
{
	//가격 판단을 여기서 한다
	//if (가격이 생각한거 * 1.1 보다 크다)
	{
		//화난 얼굴 이미지  띄우기
		if (_counter > 500)
		{
			_npc->SetNpcState(NpcIdle::GetInstance());
		}
	}
	//else if (가격이 생각한거 * 1.1 다 작고 생각보다 크다(10퍼센트 비싸다)
	{
		//불만이지만 사는 표정 띄우기
		if (_counter > 500)
		{
			_npc->SetNpcState(NpcInline::GetInstance());
		}
	}
	//else if (가격이 생각한거보다 싸고 0.9보다는 비싸다)
	{
		//웃는 얼굴 표정 띄우기
		if (_counter > 500)
		{
			_npc->SetNpcState(NpcInline::GetInstance());
		}
	}
	//else if (가격이 생각한거 * 0.9 (10퍼 싸다)
	{
		//눈에 동전뜬 얼굴 표정 띄우기
		if (_counter > 500)
		{
			_npc->SetNpcState(NpcInline::GetInstance());
		}
	}
}

NpcInline* NpcInline::GetInstance()
{
	if (instance == nullptr)
	{
		instance = new NpcInline();
	}
	return instance;
}

//==================줄서기=====================
void NpcInline::StateIn(Npc* npc)
{
}

void NpcInline::StateStay(Npc* npc)
{
}

void NpcInline::StateOut(Npc* npc)
{
}

NpcExit* NpcExit::GetInstance()
{
	if (instance == nullptr)
	{
		instance = new NpcExit();
	}
	return instance;
}

//==================나가기=====================
void NpcExit::StateIn(Npc* npc)
{
}

void NpcExit::StateStay(Npc* npc)
{
}

void NpcExit::StateOut(Npc* npc)
{
}
