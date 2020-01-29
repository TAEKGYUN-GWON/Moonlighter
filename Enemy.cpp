#include "stdafx.h"
#include "Enemy.h"
#include "Hp.h"
#include "Bullet.h"
#include "Item.h"
//#include "Player.h"
//���漱�� ���� ��...?



EnemyIdle* EnemyIdle::instance;
EnemyMove* EnemyMove::instance;
EnemyAttack* EnemyAttack::instance;
EnemyHit* EnemyHit::instance;
EnemyDead* EnemyDead::instance;


Enemy::Enemy()
{

	SetState(EnemyIdle::GetInstance());

	//cout << "�����ںκ� ���̵�" << endl;
	
}

Enemy::~Enemy()
{
}
//ó�� ���ʹ� ���� ���úκ� ���� Enemy::Init()���� ���� ������
void Enemy::SetState(EnemyBasic* state)
{

	state->Init(this);
	if (dynamic_cast<EnemyMove*>(this->state)) delete this->state;
	this->state = state;
}

void Enemy::Init()
{
	Object::Init();

	_tag = "enemy";
	_speed = 30.0f;
	_hp = new Hp;
	maxFrameX = 0;
	frameY = 0;
	_sprite = AddComponent<Sprite>();
	_sprite->SetMaxFrameX(maxFrameX);
	_sprite->SetFrameY(frameY);
	_player = (Player*)SCENEMANAGER->GetNowScene()->GetChildFromName("Will");
}

void Enemy::Update()
{
	Object::Update();
	
	float angle = Vector2::GetAngle(_trans->GetPos(), _player->GetTrans()->GetPos());
	 //�̹����� �ٲ��ִµ� ��...currentimg(y) �̷���?
	 //if (angle > (3 * PI) / 4 && angle < (5 * PI) / 4) _dir = DIRECTION::LEFT;
	 //if (angle > (4 * PI) / 4 && angle < (7 * PI) / 4) _dir = DIRECTION::RIGHT;
	 //if (angle > PI / 4 && angle < (3 * PI) / 4) _dir = DIRECTION::TOP;
	 //if (angle > PI / 4 && angle < (7 * PI) / 4) _dir = DIRECTION::BOTTOM;
	if (angle >= 45 * DegToRad && angle < 135 * DegToRad)_dir = DIRECTION::TOP;
	else if (angle >= 135 * DegToRad && angle < 180 * DegToRad)_dir = DIRECTION::LEFT;
	else if (angle <= -135 * DegToRad && angle > -180 * DegToRad)_dir = DIRECTION::LEFT;

	else if (angle <= -45 * DegToRad && angle > -135 * DegToRad)_dir = DIRECTION::BOTTOM;

	else if (angle <= 0 * DegToRad && angle >= -45 * DegToRad)_dir = DIRECTION::RIGHT;
	else if (angle >= 0 * DegToRad && angle < 45 * DegToRad)_dir = DIRECTION::RIGHT;

	
	//���� Update �ɾ���
	state->Update(this);


}

void Enemy::Render()
{
	Object::Render();
	wchar_t buffer[128];
	swprintf(buffer, 128, L"Angle : %f", Vector2::GetAngle(_trans->GetPos(), _player->GetTrans()->GetPos()) * Rad2Deg);
	GRAPHICMANAGER->Text(_trans->GetPos() - Vector2::down * 20, buffer, 20, 300, 50, ColorF::Azure, 1, TextPivot::CENTER, L"�������", true);

}

void Enemy::SetPath(list<Vector2> _path)
{
	this->_path.clear();
	this->_path = _path;
}




#include "SlimeEnemy.h"
#include "GolemEnemy.h"
#include "MintPotEnemy.h"

void EnemyBasic::Update(Enemy* _sEnemy)
{
	if (_sEnemy->GetHP()->IsDead())
	{
		SetEnemyState(_sEnemy, EnemyDead::GetInstance());
	}
	if (_sEnemy->GetAtk()) SetEnemyState(_sEnemy, EnemyAttack::GetInstance());
}

//������������� Idle ���������������
EnemyIdle* EnemyIdle::GetInstance()
{

	//instance�� null�̸� 
	if (instance == nullptr)
	{
		//enemy���´� idle
		instance = new EnemyIdle();
	}
	//instance = new EnemyIdle(); ��� �������ϱ� EnemyIdle�� ��
	//���� state->Update(this); �ɾ������ϱ� Idle instance�� ������
	return instance;
}

void EnemyIdle::Init(Enemy* _sEnemy)
{
	//sprite ����?
	cout << "�� �ȵ���?" << endl;
}

void EnemyIdle::Update(Enemy* _sEnemy)
{
	//if (KEYMANAGER->isOnceKeyDown('0'))
		//hp �� 0�̸�
	EnemyBasic::Update(_sEnemy);
	Release(_sEnemy);
	cout << "������?" << endl;

}
void EnemyIdle::Release(Enemy* _sEnemy)
{
	cout << "move�� ��!!!" << endl;

	//if �÷��̾ ������
	// else if ü���� 0 �̸� �׾��!
	if (_sEnemy->GetHP()->IsDead())
	{
		SetEnemyState(_sEnemy, EnemyDead::GetInstance());
	}
	else
		SetEnemyState(_sEnemy, EnemyMove::GetInstance());
}
//������������� Move ��������������
EnemyMove* EnemyMove::GetInstance()
{
	if (instance == nullptr)
	{
		instance = new EnemyMove();
	}

	return new EnemyMove();
}

void EnemyMove::Init(Enemy* _sEnemy)
{
	cout << "move ����?" << endl;
	//a*? bool������.?
	_sEnemy->SetMove(true);
	timer = 0;
}

void EnemyMove::Update(Enemy* _sEnemy)
{
	EnemyBasic::Update(_sEnemy);

	if (_sEnemy->GetMove())
		_sEnemy->SetMove(false);
	if (_sEnemy->GetPath().size())
	{
		Vector2 dir = *_sEnemy->GetPath().begin() - _sEnemy->GetTrans()->GetPos();
		Vector2 pos = _sEnemy->GetTrans()->GetPos();
		_sEnemy->SetAngle(Vector2::GetAngle(pos, *_sEnemy->GetPath().begin()));
		_sEnemy->GetTrans()->SetPos(pos + dir.Nomalized() * _sEnemy->GetSpeed() * TIMEMANAGER->getElapsedTime());
	}
	_sEnemy->GetPhysics()->SetBodyPosition();
	//cout << "����� ���� ���� �ε�ĩ" << endl;
	//loat a = RND->getFloat(10000000);
	//if(a<30)
	timer += TIMEMANAGER->getElapsedTime();
	if (timer > 3)
		Release(_sEnemy);

}

void EnemyMove::Release(Enemy* _sEnemy)
{

	//if ������ �÷��̾ ������ �����ϰ�
	//SetEnemyState(_sEnemy, EnemyAttack::GetInstance());
	// else if ������ �÷��̾ ������ �ٽ� ����
	//SetEnemyState(_sEnemy, EnemyMove::GetInstance());
	cout << "�ٽ� ����?" << endl;
	SetEnemyState(_sEnemy, EnemyIdle::GetInstance());
	// else if ü���� 0 �̸� �׾��!

	//if (_sEnemy->GetHP()->IsDead())
	//{
	//	SetEnemyState(_sEnemy, EnemyDead::GetInstance());
	//}
	//else SetEnemyState(_sEnemy, EnemyAttack::GetInstance());
}
//������������ Attack �������������
EnemyAttack* EnemyAttack::GetInstance()
{
	if (instance == nullptr)
	{
		instance = new EnemyAttack();
	}

	return instance;
}

void EnemyAttack::Init(Enemy* _sEnemy)
{
	if (_sEnemy->GetName() == "Golem") _sEnemy->GetSprite()->SetImgName("Golem_Atk");
	//cout << "���� ���Դ�?" << endl;
}

void EnemyAttack::Update(Enemy* _sEnemy)
{
	if (_sEnemy->GetHP()->IsDead())
	{
		SetEnemyState(_sEnemy, EnemyDead::GetInstance());
	}
	_sEnemy->Attack();
	//cout << "����� ����!" << endl;
	if (_sEnemy->GetName() == "Golem")
	{
		//if(_sEnemy->GetSprite()->get)
	}
	else
		Release(_sEnemy);
}

void EnemyAttack::Release(Enemy* _sEnemy)
{
	_sEnemy->SetAtk(false);
	//if �÷��̾����� ������ �´� ���·� ����
	SetEnemyState(_sEnemy, EnemyIdle::GetInstance());

	// else if �ƴϸ� idle�� ����
	//SetEnemyState(_sEnemy, EnemyIdle::GetInstance());
	// else if ü���� 0 �̸� �׾��!
}
//������������� Hit ��������������

EnemyHit* EnemyHit::GetInstance()
{
	if (instance == nullptr)
	{
		instance = new EnemyHit();
	}

	return instance;
}

void EnemyHit::Init(Enemy* _sEnemy)
{
	//cout << "����� �¾Ҵٰ� �ϴ� �κ�" << endl;
}

void EnemyHit::Update(Enemy* _sEnemy)
{
	EnemyBasic::Update(_sEnemy);
	//cout << "�÷��̾����� �¾ҳ�?" << endl;
	Release(_sEnemy);
}

void EnemyHit::Release(Enemy* _sEnemy)
{
	// if �¾����� idle�� ����
	// else if �ȸ¾����� �ٽ� ������
	// else if ü���� 0 �̸� �׾��!
	if (_sEnemy->GetHP()->IsDead())
	{
		SetEnemyState(_sEnemy, EnemyDead::GetInstance());
	}

}
//������������� Dead �������������

EnemyDead* EnemyDead::GetInstance()
{
	if (instance == nullptr)
	{
		instance = new EnemyDead();
	}

	return instance;
}

void EnemyDead::Init(Enemy* _sEnemy)
{
	//Item::CreateItem(_sEnemy->GetTrans()->GetPos());
	//cout << "����� ���� ����" << endl;
}

void EnemyDead::Update(Enemy* _sEnemy)
{
	//	cout << "�׾���?" << endl;
	Release(_sEnemy);
}

void EnemyDead::Release(Enemy* _sEnemy)
{
	//if (_sEnemy->GetHP()->IsDead())
	//cout << "�׾��� �Ф�" << endl;
//	_sEnemy->Release();
}
