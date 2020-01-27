#pragma once
#include "Object.h"
#include "ShopStand.h"
#include "CheckStand.h"
#include "Sprite.h"

class ShopStand;
class CheckStand;
class NpcShopState;

class Npc :	public Object
{
private:
	//Sprite* _sprite;

	float _speed;
	bool _isShopSOn;	//���Ǵ�� �浹������
	bool _isCheckSOn;	//����� �浹������



	NpcShopState* _npcShopState;

	ShopStand* _shopStand;
	CheckStand* _checkStand;

	//list<Vector2> _lPath;

	Sprite* _sprite;

	//����Ʈ ����2 �� ����������, a��Ÿ�� 

public:
	Npc() {};
	~Npc() {};

	virtual void Init(string imgkey) ;
	virtual void Release() override;
	virtual void Update() override;
	virtual void Render() override;

	//void Move();

	void SetNpcState(NpcShopState* npcshopstate);
	//void SetPath(list<Vector2> lpath);

	void In();
	void Stay();
	void Out();

	void SetCheckStandLink(CheckStand* checkstand) { _checkStand = checkstand; }
	CheckStand* GetCheckStand() { return _checkStand; }

	//����� ���Ǵ�� �浹��ING���� üũ�� bool
	void SetIsShopSOn(bool shop) { _isShopSOn = shop; }
	void SetIsCheckSOn(bool check) { _isCheckSOn = check; }
	bool GetIsShopSOn() { return _isShopSOn; }
	bool GetIsCheckSOn() { return _isCheckSOn; }

};

