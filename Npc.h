#pragma once
#include "Object.h"
//#include "ShopStand.h"
//#include "ShopStandManager.h"
//#include "CheckStand.h"
//#include "Sprite.h"

#define NPDSPEED 70

class ShopStand;
class CheckStand;
class NpcShopState;

class Npc :	public Object
{
private:
	Sprite* _sprite;

	bool _isShopSOn;	//���Ǵ�� �浹������
	bool _isCheckSOn;	//����� �浹������

	bool _isAstarOn = true;	//astar �޾ƾ��ϴ� ��������

	
	NpcShopState* _npcShopState;

	//ShopStand* _shopStand; //���ĵ带 �����ߵ��� �Ŵ����� �����ߵ��� �𸣰���
	//ShopStandManager* _shopStandMgr;
	//CheckStand* _checkStand;

	list<Vector2> _lPath; //�����ϴ� ��

public:
	Npc() {};
	~Npc() {};

	virtual void Init(string imgkey);
	virtual void Release() override;
	virtual void Update() override;
	virtual void Render() override;

	void SetPath(list<Vector2> lpath);
	
	//���� ���ǿ�
	void ChangeState(NpcShopState* state);

	//����/�ǸŴ� ��ũ��
	//void SetCheckStandLink(CheckStand* checkstand) { _checkStand = checkstand; }
	//CheckStand* GetCheckStand() { return _checkStand; }
	//void SetShopStandLink(ShopStandManager* shopstand) { _shopStandMgr = shopstand; }
	//ShopStandManager* GetShopStandMgr() { return _shopStandMgr; }

	//����� ���Ǵ�� �浹��ING���� üũ�� bool
	void SetIsShopSOn(bool shop) { _isShopSOn = shop; }
	bool GetIsShopSOn() { return _isShopSOn; }
	void SetIsCheckSOn(bool check) { _isCheckSOn = check; }
	bool GetIsCheckSOn() { return _isCheckSOn; }
	void SetIsAstarOn(bool ast) { _isAstarOn = ast; }
	bool GetIsAstarOn() { return _isAstarOn; }

	//NpcShopState* GetStatePointer() { return _npcShopState; }

	Sprite* GetSprite() { return _sprite; }
	NpcShopState* GetState() {	return _npcShopState; }

	list<Vector2>* GetPath() { return &_lPath; }
};

