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
}

void Inventory::Update()
{
}

void Inventory::Release()
{
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
	//for (iter = _inven.begin(); iter != _inven.end(); iter++)
	//{
	//	if (iter->second->item->GetName() == name)
	//	{
	//	}
	//}
	//맵을 돌아서 카운트를 아이템 갯수만큼 증가시켜준다
	//그 이후에 삭제 
	//공무원 패턴 생각해 봐야함
}
