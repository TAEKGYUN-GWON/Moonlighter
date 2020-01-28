#include "stdafx.h"
#include "GolemEnemy.h"
#include "Hp.h"


GolemEnemy::GolemEnemy()
{
}

GolemEnemy::~GolemEnemy()
{
}

void GolemEnemy::Init(Vector2 pos)
{
	Enemy::Init();

	GRAPHICMANAGER->AddFrameImage("Golem", L"resource/img/Enemy/GolemMove.png", 8, 4);
	_tag = "enemy";
	_name = "Golem";

	_hp = new Hp(50, 50);



	_sprite = AddComponent<Sprite>();
	_sprite->Init(true, true);
	_sprite->SetImgName("Golem");
	_trans->SetScale(Vector2(_sprite->GetGraphic()->GetFrameWidth(),
		_sprite->GetGraphic()->GetFrameHeight()));
	_trans->SetPos(pos);
	_sprite->SetRectColor(ColorF::Cornsilk);

	_trans->SetScale(Vector2(62, 25));
	_physics = AddComponent<PhysicsBody>();
	_physics->Init(BodyType::DYNAMIC, 1.0f);
	////가상세계의 렉트 뒤틀리는거 고정
	_physics->GetBody()->SetFixedRotation(true);
	_physics->SetBodyActive(false);

	_atkRange = 100;


#pragma region 공격 오브젝트
	_lAtk = Object::CreateObject<Object>(this);
	_rAtk = Object::CreateObject<Object>(this);
	_tAtk = Object::CreateObject<Object>(this);
	_bAtk = Object::CreateObject<Object>(this);


	_lAtk->GetTrans()->SetPos(_trans->GetPos()+Vector2::left*50);
	_rAtk->GetTrans()->SetPos(_trans->GetPos()+Vector2::right*50);
	_tAtk->GetTrans()->SetPos(_trans->GetPos()+Vector2::up*50);
	_bAtk->GetTrans()->SetPos(_trans->GetPos()+Vector2::down*50);

	_lAtk->GetTrans()->SetScale(100,40);
	_rAtk->GetTrans()->SetScale(100,40);
	_tAtk->GetTrans()->SetScale(40,100);
	_bAtk->GetTrans()->SetScale(40,100);

	_lAtk->AddComponent<PhysicsBody>()->Init(BodyType::STATIC,1.f,1.f);
	_rAtk->AddComponent<PhysicsBody>()->Init(BodyType::STATIC,1.f,1.f);
	_tAtk->AddComponent<PhysicsBody>()->Init(BodyType::STATIC,1.f,1.f);
	_bAtk->AddComponent<PhysicsBody>()->Init(BodyType::STATIC,1.f,1.f);

	_lAtk->GetComponent<PhysicsBody>()->GetBody()->SetFixedRotation(true);
	_rAtk->GetComponent<PhysicsBody>()->GetBody()->SetFixedRotation(true);
	_tAtk->GetComponent<PhysicsBody>()->GetBody()->SetFixedRotation(true);
	_bAtk->GetComponent<PhysicsBody>()->GetBody()->SetFixedRotation(true);

	_lAtk->GetComponent<PhysicsBody>()->SetBodyActive(false);
	_rAtk->GetComponent<PhysicsBody>()->SetBodyActive(false);
	_tAtk->GetComponent<PhysicsBody>()->SetBodyActive(false);
	_bAtk->GetComponent<PhysicsBody>()->SetBodyActive(false);

#pragma endregion


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
	_sprite->SetPosition(_trans->GetPos()+Vector2::up*30);
	AtkPosUpdate();
	if (KEYMANAGER->isOnceKeyDown('8'))GetLeftAtk()->SetBodyActive(true);
}



void GolemEnemy::AtkPosUpdate()
{
	_lAtk->GetTrans()->SetPos(_trans->GetPos() + Vector2::left * 50);
	_rAtk->GetTrans()->SetPos(_trans->GetPos() + Vector2::right * 50);
	_tAtk->GetTrans()->SetPos(_trans->GetPos() + Vector2::up * 50);
	_bAtk->GetTrans()->SetPos(_trans->GetPos() + Vector2::down * 50);

	_lAtk->GetComponent<PhysicsBody>()->SetBodyPosition();
	_rAtk->GetComponent<PhysicsBody>()->SetBodyPosition();
	_tAtk->GetComponent<PhysicsBody>()->SetBodyPosition();
	_bAtk->GetComponent<PhysicsBody>()->SetBodyPosition();

}

void GolemEnemy::Attack()
{
	//여기에 범위 원 렉트?
	//GRAPHICMANAGER->DrawEllipse
		//(float x, float y, float radiusX, float radiusY, ColorF::Enum color, float strokeWidth)
		//데미지 주는거?
	//원 랙트 안에 센서 on이면 떄리고 off면 안 때리고
	//이미지 바꿔줘야 하나 여기서?->슬라임은 필요x
	//길바떄 센서처럼 하면 될까??->bool player?


}

void GolemEnemy::Release()
{

	SCENEMANAGER->GetNowScene()->GetWorld()->DestroyBody(GetLeftAtk()->GetBody());
	SCENEMANAGER->GetNowScene()->GetWorld()->DestroyBody(GetRightAtk()->GetBody());
	SCENEMANAGER->GetNowScene()->GetWorld()->DestroyBody(GetTopAtk()->GetBody());
	SCENEMANAGER->GetNowScene()->GetWorld()->DestroyBody(GetBottomAtk()->GetBody());

	_lAtk->Release();
	_rAtk->Release();
	_tAtk->Release();
	_bAtk->Release();
	Object::Release();
}

void GolemEnemy::Render()
{
	if(KEYMANAGER->isToggleKey(VK_F5))
		GRAPHICMANAGER->DrawEllipse(_trans->GetPos().x, _trans->GetPos().y, _atkRange, _atkRange, ColorF::AntiqueWhite, 1.5f);
	Object::Render();

}
