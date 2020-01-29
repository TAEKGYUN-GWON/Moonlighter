#include "stdafx.h"
#include "TestScene.h"

void TestScene::Init()
{
	Scene::Init();
	bullet = Object::CreateObject<Object>();
	bullet->GetTrans()->SetPos(WINSIZEX * 4, WINSIZEY / 2);
	bullet->GetTrans()->SetScale(50,30);

	auto p = bullet->AddComponent<PhysicsBody>();
	p->Init(DYNAMIC, 1, 10.f, 0, true);
	p->GetBody()->SetFixedRotation(true);

}


void TestScene::Update()
{
	Scene::Update();

	if (KEYMANAGER->isOnceKeyDown('S'))
	{
		for (Object* obj : test)
			obj->GetComponent<PhysicsBody>()->SetSensor(false);
	}
	if (KEYMANAGER->isOnceKeyDown('F'))
	{
		bullet->GetComponent<PhysicsBody>()->ApplyForce(Vector2::b2Left * 90000000);
	}
		//bullet->GetComponent<PhysicsBody>()->GetBody()->SetAngularVelocity(999);

	if (KEYMANAGER->isOnceKeyDown('D'))
	{
		for (Object* obj : test)
			obj->GetComponent<PhysicsBody>()->SetBodyActive(true);
	}
	_timer += TIMEMANAGER->getElapsedTime();
	if (_count < 200)
	{
		//if (_timer > 0.1f)
		//{
			Object* obj = Object::CreateObject<Object>();

			float x = RND->getFromFloatTo(WINSIZEY / 2-100, WINSIZEX/2+200);
			float y = RND->getFromFloatTo(WINSIZEY / 2 - 100, WINSIZEY / 2 + 100);

			obj->GetTrans()->SetPos(Vector2(x, y));

			float w = RND->getFromFloatTo(100, 300);
			float h = RND->getFromFloatTo(100, 400);
			obj->GetTrans()->SetScale(Vector2(w, h));

			auto a = obj->AddComponent<PhysicsBody>();
			a->Init(BodyType::DYNAMIC, 0,0.1f);
			a->SetSensor(true);
			a->GetBody()->SetFixedRotation(true);
			_timer = 0;
			_count++;
			test.push_back(obj);
		//}
	}
}

void TestScene::Render()
{
	for (Object* child : _children)
	{
		child->Render();

	}
}
