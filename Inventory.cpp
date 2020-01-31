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
	GRAPHICMANAGER->AddImage("Potion_S", L"resource/img/Items/Potion_S.png");
	_isActive = false;
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

	//_ui->RenderUI(Vector2(WINSIZEX / 2, WINSIZEY / 2));
	_ui->Render(Vector2(WINSIZEX / 2, WINSIZEY / 2),1,PIVOT::CENTER,false);
	for (iter = _inven.begin(); iter != _inven.end(); iter++)
	{
		//iter->second.item->GetComponent<Sprite>()->GetGraphic()->RenderUI(iter->second.item->GetTrans()->GetPos());
		GRAPHICMANAGER->FindImage(iter->second.item)->Render(iter->second.pos,1,PIVOT::CENTER,false);
		//char buffer[128];
		//sprintf_s(buffer, "%d",iter->second.some);
		Vector2 pos = Vector2(iter->second.pos.x + 20, iter->second.pos.y + 20);
		//GRAPHICMANAGER->DrawTextD2D(pos, buffer, 15);

		wchar_t buffer[128];
		swprintf(buffer, 128, L"%d", iter->second.some);
		GRAPHICMANAGER->Text(pos, buffer, 15, 300, 50, ColorF::White);

	}
	_select->RenderUI(pos);

}

void Inventory::Insert(Item* item)
{

	for (iter = _inven.begin(); iter != _inven.end(); iter++)
	{
		if (iter->first == item->GetName())
		{
			if (iter->second.some < item->GetMaxCount())
			{
				iter->second.some++;
				return;
			}
		}
	}
	if (_inven.size() >= 20) return;


#pragma region ������ ��ġ ����
	switch (_inven.size())
	{
	case 0:
		item->GetTrans()->SetPos(154,125);
		break;
	case 1:
		item->GetTrans()->SetPos(242, 125);
		break; 
	case 2:
		item->GetTrans()->SetPos(328, 125);
		break;
	case 3:
		item->GetTrans()->SetPos(416, 125);
		break;
	case 4:
		item->GetTrans()->SetPos(504, 125);
		break;
	case 5:
		item->GetTrans()->SetPos(154, 242);
		break;
	case 6:
		item->GetTrans()->SetPos(242, 242);
		break;
	case 7:
		item->GetTrans()->SetPos(328, 242);
		break;
	case 8:
		item->GetTrans()->SetPos(416, 242);
		break;
	case 9:
		item->GetTrans()->SetPos(504, 242);
		break;
	case 10:
		item->GetTrans()->SetPos(154, 338);
		break;
	case 11:
		item->GetTrans()->SetPos(242, 338);
		break;
	case 12:
		item->GetTrans()->SetPos(328, 338);
		break;
	case 13:
		item->GetTrans()->SetPos(416, 338);
		break;
	case 14:
		item->GetTrans()->SetPos(504, 338);
		break;
	case 15:
		item->GetTrans()->SetPos(154, 437);
		break;
	case 16:
		item->GetTrans()->SetPos(242, 437);
		break;
	case 17:
		item->GetTrans()->SetPos(328, 437);
		break;
	case 18:
		item->GetTrans()->SetPos(416, 437);
		break;
	case 19:
		item->GetTrans()->SetPos(504, 437);
		break;
	}

#pragma endregion
	_inven.insert(make_pair(item->GetName(), tagItemInfo(item,item->GetTrans()->GetPos())));
	item->Release();
}

void Inventory::Remove(string name, int num)
{

	int count = num;
	for (iter = _inven.begin(); iter != _inven.end(); ++iter)
	{
		if (count <= 0) break;
		if (iter->first == name)
		{
			if (iter->second.some > 0)
			{
				count--;
				iter->second.some--;
			}
		}
	}
}

int Inventory::FindItemSome(string name)
{
	int count = 0;

	for (iter = _inven.begin(); iter != _inven.end(); ++iter)
	{
		if (iter->first == name)
		{
			count += iter->second.some;
		}
	}
	return count;
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
	if (KEYMANAGER->isOnceKeyDown('P'))
	{
		AddMoney(100);
	}
	if (KEYMANAGER->isOnceKeyDown('I'))
	{
		_isActive = !_isActive;
		pos = Vector2(154, 125);
	}

	if (KEYMANAGER->isOnceKeyDown('W'))
	{
		if (pos.y == 242.f) pos = Vector2(pos.x, 125);
		else if(pos.y >= 125.f && pos.y >= 242.f)pos = Vector2(pos.x, pos.y - 98);
	}
	if (KEYMANAGER->isOnceKeyDown('A'))
	{
		if(pos.x >= 241.5) pos = Vector2(pos.x - 87.5, pos.y);
	}
	if (KEYMANAGER->isOnceKeyDown('S'))
	{
		if (pos.y == 125.f) pos = Vector2(pos.x, 242);
		else if(pos.y <= 340.f)pos = Vector2(pos.x, pos.y + 98);
	}
	if (KEYMANAGER->isOnceKeyDown('D'))
	{
		if (pos.x <= 416.5) pos = Vector2(pos.x + 87.5, pos.y);
	}
}

void Inventory::PosCorrection()
{
	
}

bool Inventory::DeductionMoney(int money)
{
	if (_money < money) return false;

	_money -= money;

	return true;
}

