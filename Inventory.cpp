#include "stdafx.h"
#include "Inventory.h"


Inventory::Inventory()
{
}


Inventory::~Inventory()
{
}

void Inventory::Init()
{
	_ui = GRAPHICMANAGER->AddImage("inventory", L"resource/img/UI/Inventory.png");
	 GRAPHICMANAGER->AddImage("invenSlot", L"resource/img/UI/invenSlot.png");
	_isActive = false;
	//_select = Object::CreateObject<Object>();
	//_select->SetParent(nullptr);

	_select = Object::CreateObject<Object>();
	_select->Init();
	_select->GetTrans()->SetPos(154, 125);
	_select->GetTrans()->SetScale(68,68);
	auto a = _select->AddComponent<Sprite>();
	a->Init();
	a->SetImgName("invenSlot");
	_select->SetIsActive(false);


}

void Inventory::Update()
{
	_select->GetTrans()->SetPos(_select->GetTrans()->pos - CAMERA->GetPosition());
	KeyCon();

	if (!_isActive) return;

	Quantity();
}

void Inventory::Release()
{
}

void Inventory::Render()
{
	if (!_isActive) return;

	_ui->RenderUI(Vector2(WINSIZEX / 2, WINSIZEY / 2));
	_select->Render();
}

void Inventory::Insert(Item* item)
{

	for (iter = _inven.begin(); iter != _inven.end(); iter++)
	{
		if (iter->second.item->GetName() == item->GetName())
		{
			if (iter->second.some < item->GetMaxCount())
			{
				iter->second.some++;
				return;
			}
		}
	}
	if (_inven.size() >= 15) return;

	_inven.insert(make_pair(item->GetName(), tagItemInfo(item)));
}

void Inventory::Remove(string name, int num)
{

	int count = num;
	for (iter = _inven.begin(); iter != _inven.end(); ++iter)
	{
		if (count <= 0) break;
		if (iter->second.item->GetName() == name)
		{
			if (iter->second.some > 0)
			{
				count--;
				iter->second.some--;
			}
		}
	}

}

void Inventory::Quantity()
{
	for (iter = _inven.begin(); iter != _inven.end(); ++iter)
	{
		if (iter->second.some <= 0)
		{
			_inven.erase(iter);
			break;
		}
	}
}
void Inventory::KeyCon()
{

	if (KEYMANAGER->isOnceKeyDown('I'))
	{
		_isActive = !_isActive;
		_select->SetIsActive(!_select->GetIsActive());
		_select->GetTrans()->SetPos(Vector2(154, 125));
	}

	if (KEYMANAGER->isOnceKeyDown('W'))
	{

	}
	if (KEYMANAGER->isOnceKeyDown('A'))
	{

	}
	if (KEYMANAGER->isOnceKeyDown('S'))
	{

	}
	if (KEYMANAGER->isOnceKeyDown('D'))
	{
		_select->GetTrans()->SetPos(154, 125);
	}
}

