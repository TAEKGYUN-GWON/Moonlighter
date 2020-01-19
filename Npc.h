#pragma once
#include "Object.h"
#include "ShopStand.h"
#include "NpcState.h"

class Npc :	public Object
{
private:
	ShopStand* _shopStand;
	NpcState* _npcState;



public:

	virtual void Init() override;
	virtual void Release() override;
	virtual void Update() override;
	virtual void Render() override;

	void SetState(NpcState* npcstate);	//���� ���� //�� Npc*�� �޴��� �� �𸣰��� ������
	void BuyStuffs();	//���� ��� �ൿ
	void NotBuyStuffs();//���� �Ȼ�� �ൿ
	void Move();		//�̵� �ൿ (���¿� ���� �ٲ�����)
	void GoHome();		//���� ���� �ൿ


};

