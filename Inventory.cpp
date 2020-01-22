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
	 GRAPHICMANAGER->AddImage("inventory", L"resource/img/UI/Inventory.png");
	_isActive = false;
	//_select = Object::CreateObject<Object>();
	//_select->SetParent(nullptr);

	//_select->
	//auto a = _select->AddComponent<Sprite>();
}

void Inventory::Update()
{
	if (KEYMANAGER->isOnceKeyDown('I'))_isActive = !_isActive;
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
			else
			{
				if (_inven.size() == 15) return;
				_inven.insert(make_pair(item->GetName(), tagItemInfo(item)));
			}
		}
	}
	if (_inven.size() == 15) return;

	_inven.insert(make_pair(item->GetName(), tagItemInfo(item)));
	return;
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

	//맵을 돌아서 카운트를 아이템 갯수만큼 증가시켜준다
	//그 이후에 삭제 
	//공무원 패턴 생각해 봐야함
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
