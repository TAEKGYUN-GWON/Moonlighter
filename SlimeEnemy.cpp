#include "stdafx.h"
#include "SlimeEnemy.h"
#include "Hp.h"


SlimeEnemy::SlimeEnemy()
{

}

SlimeEnemy::~SlimeEnemy()
{

}

void SlimeEnemy::Init(Vector2 pos)
{
	Enemy::Init();

	GRAPHICMANAGER->AddFrameImage("slime", L"resource/img/Enemy/slime.png", 5, 1); 
	
	_tag = "enemy";
	_name = "Slime";
	
	_hp = new Hp(1, 1); 
	_sprite = AddComponent<Sprite>();
	_sprite->Init(true, true);
	_sprite->SetImgName("slime");
	////�̹��� ũ��, pos�� ��� ���� �����ɶ� ��ȿ� �������� �ؾ� �Ұ� ����
	_trans->SetScale(Vector2(_sprite->GetGraphic()->GetFrameWidth(), 
		_sprite->GetGraphic()->GetFrameHeight()));
	_trans->SetPos(pos);
	//_sprite->SetMaxFrameX(5);
	//_sprite->SetFrameY(1);
	//_sprite->SetRectColor(ColorF::Cornsilk);

	_physics = AddComponent<PhysicsBody>();
	_physics->Init(BodyType::DYNAMIC, 1.0f);	//�÷��̾����� �ո� �� �׷���?
	//���󼼰��� ��Ʈ ��Ʋ���°� ����
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
	_sprite->SetPosition(_trans->GetPos());
	//_sprite->set
}

