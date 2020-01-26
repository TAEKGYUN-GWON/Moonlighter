#include "stdafx.h"
#include "ShopStand.h"
#include "Transform.h"
#include "Sprite.h"


void ShopStand::Init(Vector2 pos, Vector2 scale)
{
	_tag = "ShopObject";
	_name = "ShopStand";

	//���Ǵ��� ��Ʈ �����
	_trans->SetPos(pos);
	_trans->SetScale(scale);
	

	//������� ���ڴ� ���߿� �ϰ���
	//_sprite->SetImgName("");
	

	_itemPos = _trans->GetPos(); //�̰� �������� ���� �𸣰ڴ�..
	//�ھ����� �̹��� ������(_itemImgName) ������� SetImgName���� ����
}

void ShopStand::Release()
{

	Object::Release();
}

void ShopStand::Update()
{

	ShowItem();

	Object::Update();
}

void ShopStand::Render()
{

	Object::Render();
}

void ShopStand::ShowItem()
{
	if (_item->GetIsActive()) //�������� �ö���ִ� ����ִ»��¸�
		//�ٵ� �̰� �׳� _item�̸� �Ǵ��� ��Ʈ���� �޾ƿ;ߵǴ��� �𸣰���
	{
		
	}
}
