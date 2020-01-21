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
	//for (iter = _inven.begin(); iter != _inven.end(); iter++)
	//{
	//	if (iter->second->item->GetName() == name)
	//	{
	//		
	//	}
	//}
}
