#include "stdafx.h"
#include "NpcShopState.h"
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
	//여긴 들어와짐
	//Npc상태를 IDLE로 두고 In()에서 StateIn()을 불러줘서 들어옴
	//if (창가자리에 도착함)
	{
		cout << "NPCIDLE:stateIn" << endl;
		StateStay(npc);
	}
	//else if (창가자리에 도착 안했으면)
	{
		//길을 찾는다(창가를 찾음)
		//창가가 비었으면 거기로 가고 
		//창가에 사람이 있으면 옆칸으로 보낸다
	
	}
}

void NpcIdle::StateStay(Npc* npc)
{

	if (!_isFunctionDone) //아직 일 안했을때
	{
		_counter++; //시작해서
		if (_counter > RND->getFromIntTo(1, 10)) //대기시간 거쳐서
		{
			cout << "NPCIDLE:statestay" << endl;
			_counter = 0;
			_isFunctionDone = true;
			StateOut(npc); //IDLE상태에서 내보낸다
		}

	}
}

void NpcIdle::StateOut(Npc* npc)
{
	//이제 EXIT랑 DECIDE 중 어느 상태로 갈지 정해야함
	int a = RND->getInt(4);
	cout << "NpcIdle: StateOut" << endl;
	if (a < 3 && a >= 0) //0, 1, 2일 때
	{
		cout << "NPC IDLE로 돌아감 다시 대기" << endl;
		npc->SetNpcState(NpcIdle::GetInstance());//IDLE 상태로 만듦
		_isFunctionDone = false; //여기서 되돌려줌..다른애들 들어갈 수 있게
	}
	else if (a == 3) //3일 때
	{
		cout << "NPCEXIT:Getinstance , 가게 나감" << endl;
		npc->SetNpcState(NpcExit::GetInstance()); //EXIT 상태로 만듦
		_isFunctionDone = false; //여기서 되돌려줌..다른애들 들어갈 수 있게
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
	StateStay(npc); //이러면 무한대로 부르고있나?
}

void NpcDecide::StateStay(Npc* npc)
{
	//머무르면서도 할거 없음.. 그냥 나가
	StateOut(npc);//이러면 무한대로 부르고있나?
}

void NpcDecide::StateOut(Npc* npc)
{
	//가격 판단을 여기서 한다
	//if (가격이 생각한거 * 1.1 보다 크다)
	{
		//화난 얼굴 이미지  띄우기
		if (_counter > 500)
		{
			npc->SetNpcState(NpcIdle::GetInstance());
		}
	}
	//else if (가격이 생각한거 * 1.1 다 작고 생각보다 크다(10퍼센트 비싸다)
	{
		//불만이지만 사는 표정 띄우기
		if (_counter > 500)
		{
			npc->SetNpcState(NpcInline::GetInstance());
		}
	}
	//else if (가격이 생각한거보다 싸고 0.9보다는 비싸다)
	{
		//웃는 얼굴 표정 띄우기
		if (_counter > 500)
		{
			npc->SetNpcState(NpcInline::GetInstance());
		}
	}
	//else if (가격이 생각한거 * 0.9 (10퍼 싸다)
	{
		//눈에 동전뜬 얼굴 표정 띄우기
		if (_counter > 500)
		{
			npc->SetNpcState(NpcInline::GetInstance());
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
	//★여긴 고심해서 내용을 추가해라..
	//책상이 _isActivated 상태면 (앞사람이 접촉중) 앞에 사람이 있는 것
	//if (앞에 사람이 있으면) return;
	//if (앞에 사람이 없으면)
	{
		_checkStand->SetStandState(true); //계산대를 사용중으로 만듦
		StateStay(npc);
	}
}

void NpcInline::StateStay(Npc* npc)
{

	//플레이어가 J를 누르기를 기다려야 한다..
	//아마 이렇게 직접 처리하지는 않을거고
	//플레이어가 J를 누르면 계산대의 Activated가 false가 되어야하고
	if(!_checkStand->GetStandState()) //계산대 비활성화 상태면 (플레이어가 J눌렀다면)
	{
		StateOut(npc);
	}
}

void NpcInline::StateOut(Npc* npc)
{

	npc->SetNpcState(NpcIdle::GetInstance());

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
	StateStay(npc);
}

void NpcExit::StateStay(Npc* npc)
{
	//해당 엔피씨 벡터를 지운다.. 들어온 npc를 지워..
}

void NpcExit::StateOut(Npc* npc)
{
	//여긴 암거도 없어도 될듯..
}
