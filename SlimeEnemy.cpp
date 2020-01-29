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
	GRAPHICMANAGER->AddFrameImage("slime", L"resource/img/Enemy", 5, 1); //������ �߰��Ұ�
	
	_tag = "enemy";
	_name = "Slime";
	
	_hp = new Ability(1, 1, 1);
	
	////�̹��� ũ��, pos�� ��� ���� �����ɶ� ��ȿ� �������� �ؾ� �Ұ� ����
	_trans->SetPos(WINSIZEX / 2, WINSIZEY / 2 - 200); //->�������� ���߿� ����� ����
	//_trans->SetScale(Vector2(100, 100));	
	_trans->SetScale(Vector2(_sprite->GetGraphic()->GetFrameWidth(), 
		_sprite->GetGraphic()->GetFrameHeight()));

	_sprite = AddComponent<Sprite>();
	_sprite->Init(true, true);
	_sprite->SetRectColor(ColorF::Cornsilk);

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
	//_sprite->set
}

void SlimeEnemy::Attack()
{
	//���⿡ ���� �� ��Ʈ?
	//�׸���...........������ �ִ°�?
	//GRAPHICMANAGER->DrawEllipse
		//(float x, float y, float radiusX, float radiusY, ColorF::Enum color, float strokeWidth)
	//�� ��Ʈ �ȿ� ���� on�̸� ������ off�� �� ������
	//�̹��� �ٲ���� �ϳ� ���⼭?
	//��ً� ����ó�� �ϸ� �ɱ�??


}

