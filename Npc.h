#pragma once
#include "Object.h"
#include "ShopStand.h"
#include "CheckStand.h"
#include "Sprite.h"
#define NPDSPEED 70

class ShopStand;
class CheckStand;
class NpcShopState;

class Npc :	public Object
{
private:
	Sprite* _sprite;

	//float _speed;
	bool _isShopSOn;	//���Ǵ�� �浹������
	bool _isCheckSOn;	//����� �浹������
	bool _isAstarOn=true;	//astar �޾ƾ��ϴ� ��������

	
	NpcShopState* _npcShopState;

	ShopStand* _shopStand;
	CheckStand* _checkStand;

	list<Vector2> _lPath;

	Vector2 _destination; //astar ��������



public:
	Npc() {};
	~Npc() {};

	virtual void Init(string imgkey);
	virtual void Release() override;
	virtual void Update() override;
	virtual void Render() override;

	void SetPath(list<Vector2> lpath);
	void Move();
	void SetNpcState(NpcShopState* npcshopstate);
	

	//�������� ���ǿ� �Լ�
	void In();
	void Stay();
	void Out();

	//���� ��ũ��
	void SetCheckStandLink(CheckStand* checkstand) { _checkStand = checkstand; }
	CheckStand* GetCheckStand() { return _checkStand; }

	//����� ���Ǵ�� �浹��ING���� üũ�� bool
	void SetIsShopSOn(bool shop) { _isShopSOn = shop; }
	bool GetIsShopSOn() { return _isShopSOn; }
	void SetIsCheckSOn(bool check) { _isCheckSOn = check; }
	bool GetIsCheckSOn() { return _isCheckSOn; }
	void SetIsAstarOn(bool ast) { _isAstarOn = ast; }
	bool GetIsAstarOn() { return _isAstarOn; }
	void SetDestination(Vector2 destination) { _destination = destination; }
	Vector2 GetDestination() { return _destination; }

	NpcShopState* GetState() {	return _npcShopState; }
};

