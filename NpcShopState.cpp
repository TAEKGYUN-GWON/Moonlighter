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




	
	//if (창가자리에 도착함) //560, 607 창가자리 좌표
	//{
		cout << "NPCIDLE:stateIn 가게 입장상태" << endl;
		//★여기서 StateStay가 주석인데 Stay로 어떻게 넘어가는거지
		//ㄴ npc::update에 걸려있기떄문에 돌아가는것임
		//npc->SetIsAstarOn(false);
		//StateStay(npc);
	//}
	//else if (창가자리에 도착 안했으면)
	//{
		//길을 찾는다(창가를 찾음)
		//창가가 비었으면 거기로 가고 
		//창가에 사람이 있으면 옆칸으로 보낸다
		//굳이 옆으로 안가도 됨
	
	//}
}

void NpcIdle::StateStay(Npc* npc)
{
		//npc->SetIsAstarOn(false);
	//if (npc->GetIsAstarOn())
		//npc->SetDestination(Vector2(340, 200)); //난로앞으로 가기

			//StateOut(npc);//못움직임
			
		
		int a;


}

void NpcIdle::StateOut(Npc* npc)
{
	//이제 EXIT랑 DECIDE 중 어느 상태로 갈지 정해야함
	int a = RND->getInt(4); // 75%확률로 가판대로 감
	cout << "NpcIdle: StateOut 들어옴" << endl;
	if (a < 3 && a >= 0) //0, 1, 2일 때
	{
		cout << "NpcIdle:StateOut:판매대로 이동, decide로 가" << endl;
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
	SetCheckStandLink(npc->GetCheckStand()); //이거 안쓰면 큰일남 npcmanager의 collision에서 해주는데 다른듯
	cout << "Inline 상태 들어왔음." << endl;

	//지금 움직이게 하기가 어려워서.. 일단 체크 안하고 넘어가겠음
	if (npc->GetIsCheckSOn() == true)return;//계산대랑 충돌중이면 리턴, 앞에 사람있는것임
	else if (npc->GetIsCheckSOn() == false) //계산대가 비어있으면
	{
		cout << "계산대를 내가 사용" << endl;
		_checkStand->SetStandisInUse(true); //계산대를 사용중으로 만듦
		StateStay(npc);

	}
}

void NpcInline::StateStay(Npc* npc)
{
	//cout << "계산대 앞에서 기다리는 중" << endl;
	if (npc->GetIsCheckSOn() == true) //충돌중일떄
	{
		if (KEYMANAGER->isOnceKeyDown('J')) //제이를 누르면
		{
			_checkStand->SetStandisInUse(false); //비활시키고
			npc->SetIsCheckSOn(false); //충돌도 아닌걸로 처리
			//★여기서 아이템값 판매액을 받아야함
		}

	}
	//플레이어가 J를 누르기를 기다려야 한다..
	if (_checkStand->GetStandisInUse() == false) //계산대 비활성화 상태면 (플레이어가 J눌렀다면)
	{
		cout << "물건 샀다" << endl;
		StateOut(npc);
	}
	//아마 이렇게 직접 처리하지는 않을거고
	//플레이어가 J를 누르면 계산대의  되어야하고
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
	//조건 왜검?
	if (npc->GetIsActive())	cout << "★★집에 간다★★" << endl;
	//좌표를 여기서 문밖으로 이동시켜줌
	//문밖으로 이동끝나서 화면에서 사라지면 isactive 를 false시킨다.
	npc->SetIsActive(false);
	//여기서 npc를 isactive=false; 시키고, 벡터는 매니저에서 지움
}
