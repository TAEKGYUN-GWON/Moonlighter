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
	_select = GRAPHICMANAGER->AddImage("invenSlot", L"resource/img/UI/invenSlot.png");
	_isActive = false;
	//_select = Object::CreateObject<Object>();
	//_select->SetParent(nullptr);

	pos = Vector2(154, 125);

}
void Inventory::Update()
{
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
	_select->RenderUI(pos);
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
		pos = Vector2(154, 125);
	}

	if (KEYMANAGER->isOnceKeyDown('W'))
	{

	}
	if (KEYMANAGER->isOnceKeyDown('A'))
	{
		pos = Vector2(pos.x - 87.5, pos.y);
	}
	if (KEYMANAGER->isOnceKeyDown('S'))
	{

	}
	if (KEYMANAGER->isOnceKeyDown('D'))
	{
		pos = Vector2(pos.x + 87.5, pos.y);
	}
}

