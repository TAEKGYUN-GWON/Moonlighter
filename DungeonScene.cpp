#include "stdafx.h"
#include "DungeonScene.h"


void DungeonScene::Init()
{
	Scene::Init();

	Object* obj = Object::CreateObject<Object>();
	auto a = obj->AddComponent<Sprite>();

	 

}

void DungeonScene::Update()
{
	Scene::Update();
}
