#include "stdafx.h"
#include "Enemy.h"
#include "Ability.h"
#include "Bullet.h"
//#include "Player.h"
//전방선언 같은 거...?
EnemyIdle* EnemyIdle::instance;	
EnemyMove* EnemyMove::instance;
EnemyAttack* EnemyAttack::instance;
EnemyHit* EnemyHit::instance;
EnemyDead* EnemyDead::instance;

Enemy::Enemy()
{

	SetState(EnemyIdle::GetInstance());

	//cout << "생성자부분 아이들" << endl;
	
}

Enemy::~Enemy()
{
}
//처음 에너미 상태 세팅부분 따로 Enemy::Init()에서 세팅 안해줌
void Enemy::SetState(EnemyBasic* state)
{
	this->state = state;
	this->state->Init(this);
}

void Enemy::Init()
{
	Object::Init();

	_tag = "enemy";
	_speed = 30.0f;
	_hp = new Ability;
	

}

void Enemy::Update()
{
	Object::Update();
	
	//getAngle(float x1, float y1, float x2, float y2);
	//로 방향 구해야함..
	//Vector2::
	/*if (getAngle(_trans->GetPos().x, _trans->GetPos().y
		, _player->GetTrans()->GetPos().x, _player->GetTrans()->GetPos().y))
	{
		//left 일떄 _dir = LEFT 이런식...?
		// rigt 일떄
		// up 일때
		// down 일때?
		//해서 이미지 바꿔 주고? 
	}*/
	
	
	//상태 Update 걸어줌
	state->Update(this);


}

void Enemy::SetPath(list<Vector2> _path)
{
	this->_path.clear();
	this->_path = _path;
}

//hp가 0이면 죽어라
void EnemyBasic::Update(Enemy* _sEnemy)
{
	if (_sEnemy->GetHP()->IsDead())
	{
		SetEnemyState(_sEnemy, EnemyDead::GetInstance());
	}
}

//■■■■■■■■■■■■ Idle ■■■■■■■■■■■■■■
EnemyIdle* EnemyIdle::GetInstance()
{

	//instance가 null이면 
	if (instance == nullptr)
	{
		//enemy상태는 idle
		instance = new EnemyIdle();
	}
	//instance = new EnemyIdle(); 라고 해줬으니까 EnemyIdle로 들어감
	//위에 state->Update(this); 걸어줬으니까 Idle instance를 실행함
	return instance;
}

void EnemyIdle::Init(Enemy* _sEnemy)
{
	//cout << "왜 안들어와?" << endl;
}

void EnemyIdle::Update(Enemy* _sEnemy)
{
	
	if (KEYMANAGER->isOnceKeyDown('0'))
		
		EnemyBasic::Update(_sEnemy);
		Release(_sEnemy);
	
	//cout << "들어오냐?" << endl;
}

void EnemyIdle::Release(Enemy* _sEnemy)
{
	//cout << "move로 가!!!" << endl;

	//if 플레이어가 있으면
	SetEnemyState(_sEnemy, EnemyMove::GetInstance());
	// else if 체력이 0 이면 죽어라!
	if (_sEnemy->GetHP()->IsDead())
	{
		SetEnemyState(_sEnemy, EnemyDead::GetInstance());
	}
}
//■■■■■■■■■■■■ Move ■■■■■■■■■■■■■
EnemyMove* EnemyMove::GetInstance()
{
	if (instance == nullptr)
	{
		instance = new EnemyMove();
	}

	return instance;
}

void EnemyMove::Init(Enemy* _sEnemy)
{
	//cout << "move 들어옴?" << endl;

}

void EnemyMove::Update(Enemy* _sEnemy)
{

	EnemyBasic::Update(_sEnemy);
	_sEnemy->GetPhysics()->SetBodyPosition();
	//cout << "여기는 무브 오예 두둠칫" << endl;
	Release(_sEnemy);
}

void EnemyMove::Release(Enemy* _sEnemy)
{
	//if 범위에 플레이어가 있으면 공격하고
	SetEnemyState(_sEnemy, EnemyAttack::GetInstance());
	// else if 범위에 플레이어가 없으면 다시 무브
	//SetEnemyState(_sEnemy, EnemyMove::GetInstance());
	// else if 체력이 0 이면 죽어라!
	if (_sEnemy->GetHP()->IsDead())
	{
		SetEnemyState(_sEnemy, EnemyDead::GetInstance());
	}
}
//■■■■■■■■■■■ Attack ■■■■■■■■■■■■
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
	//cout << "공격 들어왔니?" << endl;
}

void EnemyAttack::Update(Enemy* _sEnemy)
{
	EnemyBasic::Update(_sEnemy);
	_sEnemy->Attack();
	//cout << "여기는 공격!" << endl;
	Release(_sEnemy);
}

void EnemyAttack::Release(Enemy* _sEnemy)
{
	//if 플레이어한테 맞으면 맞는 상태로 가라
	SetEnemyState(_sEnemy, EnemyHit::GetInstance());
	// else if 아니면 idle로 가라
	//SetEnemyState(_sEnemy, EnemyIdle::GetInstance());
	// else if 체력이 0 이면 죽어라!
	if (_sEnemy->GetHP()->IsDead())
	{
		SetEnemyState(_sEnemy, EnemyDead::GetInstance());
	}
}
//■■■■■■■■■■■■ Hit ■■■■■■■■■■■■■

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
	//cout << "여기는 맞았다고 하는 부분" << endl;
}

void EnemyHit::Update(Enemy* _sEnemy)
{
	EnemyBasic::Update(_sEnemy);
	//cout << "플레이어한테 맞았나?" << endl;
	Release(_sEnemy);
}

void EnemyHit::Release(Enemy* _sEnemy)
{
	// if 맞았으면 idle로 가라
	// else if 안맞았으면 다시 때려라
	// else if 체력이 0 이면 죽어라!
	if (_sEnemy->GetHP()->IsDead())
	{
		SetEnemyState(_sEnemy, EnemyDead::GetInstance());
	}

}
//■■■■■■■■■■■■ Dead ■■■■■■■■■■■■

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
	//cout << "여기는 죽은 상태" << endl;
}

void EnemyDead::Update(Enemy* _sEnemy)
{
//	cout << "죽었니?" << endl;
	Release(_sEnemy);
}

void EnemyDead::Release(Enemy* _sEnemy)
{
	//if (_sEnemy->GetHP()->IsDead())
	//cout << "죽었다 ㅠㅠ" << endl;
//	_sEnemy->Release();
}
