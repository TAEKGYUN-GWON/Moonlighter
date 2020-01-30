#include "stdafx.h"
#include "Npc.h"
#include "NpcShopState.h"

void Npc::Init(string imgkey)
{
	
	Object::Init();

	_tag = "Npc";

	_sprite = AddComponent<Sprite>();
	_sprite->Init(true, true);
	_sprite->SetImgName(imgkey);

	SetNpcState(NpcIdle::GetInstance()); //기본 상태
	
	_trans->SetPos(400, 800); //문 밖에 생성
	_trans->SetScale(Vector2(
		GRAPHICMANAGER->FindImage(imgkey)->GetFrameWidth(),
		GRAPHICMANAGER->FindImage(imgkey)->GetFrameHeight()));

	
	
	
	
	
	

	//_destination = Vector2(340, 200);

	int a;

	
}

void Npc::Release()
{
	Object::Release();
}

void Npc::Update()
{

	//위로 움직이라고 명령 중
	//if (_trans->GetPos() >= Vector2(392, 500))
	//_trans->SetPos(Vector2(_trans->GetPos()+Vector2::up));

	//상태패턴용 함수
	//In(); //in, stay 둘다 해두면 애들이 다 다르게 지멋대로 움직임
	Stay(); //이렇게 두면 랜덤으로 한두명 돌아옴

	//Astar 용 함수
	//SetPath(list<Vector2> lpath);
	Move();

	//npc 그림 띄우기
	_sprite->SetPosition(_trans->GetPos()); 

	Object::Update();
}

void Npc::Render()
{
	Object::Render();

	//이거 안하면 자꾸 정체불명의 동그라미가 엔피씨처럼 움직임.. erase할때 false 해줌
	if (_isActive)
	{
		GRAPHICMANAGER->DrawEllipse(
			_trans->GetPos().x, 
			_trans->GetPos().y, 
			_trans->GetScale().x / 2, 
			_trans->GetScale().y / 2);
	}


}

void Npc::SetPath(list<Vector2> lpath)
{
	this->_lPath.clear();
	this->_lPath = lpath;
}


void Npc::Move()
{

	if (_lPath.size()) 
	{
		Vector2 a = *_lPath.begin() - _trans->GetPos(); // 가야할위치에서 내위치를 빼면, 가야되는 다음 노드가 나옴
		_trans->pos += a.Nomalized() * NPDSPEED * TIMEMANAGER->getElapsedTime(); //조건 느슨하게 예외처리 해주는 부분

		if ((int)Vector2::Distance(*_lPath.begin(), _trans->GetPos()) < (int)30)//바로 직후 노드에 도착하면 
			_lPath.erase(_lPath.begin()); //가장 첫번째 목적지 지우기, 다음 노드를 넣기 위해

	}
	else
		_isAstarOn = true;
}

void Npc::SetNpcState(NpcShopState* npcshopstate)
{
	_npcShopState = npcshopstate;
	_npcShopState->StateIn(this);
	
}


//상태 정의
void Npc::In()
{
	_npcShopState->StateIn(this);
}

void Npc::Stay()
{
	_npcShopState->StateStay(this);
}

void Npc::Out()
{
	_npcShopState->StateOut(this);
}
