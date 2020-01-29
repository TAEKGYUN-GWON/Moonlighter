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
	
	_trans->SetPos(392, 800); //문 밖에 생성
	_trans->SetScale(Vector2(
		GRAPHICMANAGER->FindImage(imgkey)->GetFrameWidth(),
		GRAPHICMANAGER->FindImage(imgkey)->GetFrameHeight()));

	_speed = 3.0f;
	//_destination = Vector2(0, 0);


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
	Stay();

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
	GRAPHICMANAGER->DrawEllipse(_trans->GetPos().x, _trans->GetPos().y, _trans->GetScale().x/2, _trans->GetScale().y/2);

}

void Npc::SetPath(list<Vector2> lpath)
{
	this->_lPath.clear();
	this->_lPath = lpath;
}


void Npc::Move()
{

	if (_lPath.size()) //이 속으로 들어가지 못함
	{
		Vector2 a = *_lPath.begin() - _trans->pos; // 가야할위치에서 내위치를 빼면, 가야되는 다음 노드가 나옴
		_trans->pos += a.Nomalized() * 70 * TIMEMANAGER->getElapsedTime(); //조건 느슨하게 예외처리 해주는 부분

		if ((int)Vector2::Distance(*_lPath.begin(), _trans->pos) < (int)20)//바로 직후 노드에 도착하면 
			_lPath.erase(_lPath.begin()); //가장 첫번째 목적지 지우기, 다음 노드를 넣기 위해

	}
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
