#include "stdafx.h"
#include "yest.h"
#include "PhysicsBodyComponent.h"
#include"script.h"
yest::yest()
{
}


yest::~yest()
{
}

void yest::Init()
{
	_trans->SetPos(WINSIZEX / 2, WINSIZEY / 2);
	_trans->SetScale(200, 200);

	auto a = AddComponent<PhysicsBodyComponent>();
	a->Init(DYNAMIC, 1, 1, 0);
	AddComponent<script>();
}

void yest::Update()
{
	auto a = GetComponent<PhysicsBodyComponent>();
	_trans->SetPos(a->GetBodyPosition());
	super::Update();
}

void yest::Release()
{
	super::Release();
}

void yest::test()
{
	
	cout << "이게 된다고?!" << endl;
}
