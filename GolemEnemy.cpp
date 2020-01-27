#include "stdafx.h"
#include "GolemEnemy.h"
#include "Hp.h"

GolemEnemy::GolemEnemy()
{
}

GolemEnemy::~GolemEnemy()
{
}

void GolemEnemy::Init()
{
	Enemy::Init();

	//GRAPHICMANAGER->AddFrameImage("Golem", L"resource/img/Enemy", 8, 4);
	_tag = "enemy";
	_name = "Golem";

	_hp = new Hp(100, 100);

	_trans->SetScale(Vector2(_sprite->GetGraphic()->GetFrameWidth(),
		_sprite->GetGraphic()->GetFrameHeight()));

	_sprite = AddComponent<Sprite>();
	_sprite->Init(true, true);
	_sprite->SetRectColor(ColorF::Cornsilk);

	_physics = AddComponent<PhysicsBody>();
	_physics->Init(BodyType::DYNAMIC, 1.0f);	
	////가상세계의 렉트 뒤틀리는거 고정
	_physics->GetBody()->SetFixedRotation(true);



}

void GolemEnemy::Update()
{
	Enemy::Update();

	if (_path.size())
	{
		Vector2 _astar = *_path.begin() - _trans->GetPos();
		_trans->SetPos(_trans->GetPos() + _astar.Nomalized() * 70 * TIMEMANAGER->getElapsedTime());

		if ((int)Vector2::Distance(*_path.begin(), _trans->GetPos()) < (int)20)_path.erase(_path.begin());
	}
}

void GolemEnemy::Attack()
{

}
