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
	//{
		cout << "NPCIDLE:stateIn 가게 입장상태" << endl;
	//	StateStay(npc);
	//}
	//else if (창가자리에 도착 안했으면)
	//{
		//길을 찾는다(창가를 찾음)
		//창가가 비었으면 거기로 가고 
		//창가에 사람이 있으면 옆칸으로 보낸다
	
	//}
}

void NpcIdle::StateStay(Npc* npc)
{

	_counter++; //시작해서
	if (_counter > RND->getFromIntTo(60, 100)) //대기시간 거쳐서 //이게 StateIn 유지시간에 영향줌
	{
		cout << "NPCIDLE:statestay중" << endl;
		_counter = 0;

		StateOut(npc); //IDLE상태에서 내보낸다
	}

}

void NpcIdle::StateOut(Npc* npc)
{
	//이제 EXIT랑 DECIDE 중 어느 상태로 갈지 정해야함
	int a = RND->getInt(4);
	cout << "NpcIdle: StateOut 들어옴" << endl;
	if (a < 3 && a >= 0) //0, 1, 2일 때
	{
	cout << "NpcIdle:StateOut:계산대로 이동, decide로 가" << endl;
	npc->SetNpcState(NpcDecide::GetInstance());//NpcDecide 상태로 만듦
	}
	else if (a == 3) //3일 때
	{
		cout << "NpdIdle,StateOut:나가기로 결심" << endl;
		npc->SetNpcState(NpcExit::GetInstance()); //EXIT 상태로 만듦
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
	_counter++;
	
	//테스트용
	int a = RND->getInt(2);
	switch (a)
	{
	case 0:
		//화난 얼굴 이미지  띄우기
		if (_counter > 500)
		{
			cout << "안사기로 결심, Idle로 돌아감" << endl;
			_counter = 0;
			npc->SetNpcState(NpcIdle::GetInstance());
		}
		break;
	case 1:
		//눈에 동전뜬 얼굴 표정 띄우기
		if (_counter > 500)
		{
			cout << "사기로 결심, Inline으로 감" << endl;
			_counter = 0;
			npc->SetNpcState(NpcInline::GetInstance());
		}
		break;
	}
	//{
	//	//화난 얼굴 이미지  띄우기
	//	if (_counter > 500)
	//	{
	//		cout << "안사기로 결심, Idle로 돌아감" << endl;
	//		npc->SetNpcState(NpcIdle::GetInstance());
	//	}
	//}
	////else if (가격이 생각한거 * 1.1 다 작고 생각보다 크다(10퍼센트 비싸다)
	//{
	//	//불만이지만 사는 표정 띄우기
	//	if (_counter > 500)
	//	{
	//		npc->SetNpcState(NpcInline::GetInstance());
	//	}
	//}
	////else if (가격이 생각한거보다 싸고 0.9보다는 비싸다)
	//{
	//	//웃는 얼굴 표정 띄우기
	//	if (_counter > 500)
	//	{
	//		npc->SetNpcState(NpcInline::GetInstance());
	//	}
	//}
	//else if (가격이 생각한거 * 0.9 (10퍼 싸다)
	//{
	//	//눈에 동전뜬 얼굴 표정 띄우기
	//	if (_counter > 500)
	//	{
	//		cout << "사기로 결심, Inline으로 감" << endl;
	//		npc->SetNpcState(NpcInline::GetInstance());
	//	}
	//}
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
	SetCheckStandLink (npc->GetCheckStand());
	//★여긴 고심해서 내용을 추가해라..
	//책상이 _isActivated 상태면 (앞사람이 접촉중) 앞에 사람이 있는 것
	//if (앞에 사람이 있으면) return;
	//if (앞에 사람이 없으면)
	//{
	cout << "Inline 들어왔음." << endl;
	//if (_checkStand)
	//{
	//	cout << "기다리는 중" << endl;
	//	return;
	//} //사용중이면 대기해
	cout << "계산대를 내가 사용" << endl;
	_checkStand->SetStandisInUse(true); //계산대를 사용중으로 만듦
		StateStay(npc);
	//}
}

void NpcInline::StateStay(Npc* npc)
{
	cout << "줄서서 기다리는 중" << endl;
	//플레이어가 J를 누르기를 기다려야 한다..
	//아마 이렇게 직접 처리하지는 않을거고
	//플레이어가 J를 누르면 계산대의 Activated가 false가 되어야하고
	//if(!_checkStand->GetStandState()) //계산대 비활성화 상태면 (플레이어가 J눌렀다면)
	//{
		cout << "물건 샀다" << endl;
		StateOut(npc);
	//}
}

void NpcInline::StateOut(Npc* npc)
{

	cout << "IDLE로 돌아간다" << endl;
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
	StateOut(npc);
}

void NpcExit::StateOut(Npc* npc)
{
	if (npc->GetIsActive())	cout << "★★집에 간다★★" << endl;
	//좌표를 여기서 문밖으로 이동시켜줌
	//문밖으로 이동끝나서 화면에서 사라지면 isactive 를 false시킨다.
	npc->SetIsActive(false);
	//여기서 npc를 isactive=false; 시키고, 벡터는 매니저에서 지움
}
