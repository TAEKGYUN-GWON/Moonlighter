#include "stdafx.h"
#include "SlimeEnemy.h"
#include "Ability.h"


SlimeEnemy::SlimeEnemy()
{

}

SlimeEnemy::~SlimeEnemy()
{

}

void SlimeEnemy::Init()
{
	Enemy::Init();
	//Object::Update();
	GRAPHICMANAGER->AddFrameImage("slime", L"resource/img/Enemy", 5, 1); //슬라임 추가할것
	
	_tag = "enemy";
	_name = "Slime";
	
	_hp = new Ability(1, 1, 1);
	
	////이미지 크기, pos는 어떻게 하지 생성될때 방안에 랜덤으로 해야 할거 같음
	_trans->SetPos(WINSIZEX / 2, WINSIZEY / 2 - 200); //->셋포스는 나중에 사라질 예정
	//_trans->SetScale(Vector2(100, 100));	
	_trans->SetScale(Vector2(_sprite->GetGraphic()->GetFrameWidth(), 
		_sprite->GetGraphic()->GetFrameHeight()));

	_sprite = AddComponent<Sprite>();
	_sprite->Init(true, true);
	_sprite->SetRectColor(ColorF::Cornsilk);

	_physics = AddComponent<PhysicsBody>();
	_physics->Init(BodyType::DYNAMIC, 1.0f);	//플레이어한테 뚫림 왜 그러지?
	//가상세계의 렉트 뒤틀리는거 고정
	_physics->GetBody()->SetFixedRotation(true);	
	
}

void SlimeEnemy::Update()
{
	Enemy::Update();
	
	if (_path.size())
	{
		Vector2 _astar = *_path.begin() - _trans->GetPos();
		_trans->SetPos(_trans->GetPos() + _astar.Nomalized() * 70 * TIMEMANAGER->getElapsedTime());
		
		if ((int)Vector2::Distance(*_path.begin(), _trans->GetPos()) < (int)20)_path.erase(_path.begin());
	}
	//_sprite->set
}

void SlimeEnemy::Attack()
{
	//여기에 범위 원 렉트?
	//그리고...........데미지 주는거?
	//GRAPHICMANAGER->DrawEllipse
		//(float x, float y, float radiusX, float radiusY, ColorF::Enum color, float strokeWidth)
	//원 랙트 안에 센서 on이면 떄리고 off면 안 때리고
	//이미지 바꿔줘야 하나 여기서?
	//길바떄 센서처럼 하면 될까??


}

