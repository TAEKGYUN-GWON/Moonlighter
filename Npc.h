#pragma once
#include "Object.h"
#include "ShopStand.h"
#include <list>
#include "CheckStand.h"
#include "Sprite.h"

class CheckStand;
class NpcShopState;

class Npc :	public Object
{
private:
	//Sprite* _sprite;

	float _speed;

	ShopStand* _shopStand;
	NpcShopState* _npcShopState;
	CheckStand* _checkStand;

	Sprite* _sprite;

	//����Ʈ ����2 �� ����������, a��Ÿ�� 

public:
	Npc() {};
	~Npc() {};

	virtual void Init(string imgkey) ;
	virtual void Release() override;
	virtual void Update() override;
	virtual void Render() override;
	
	void SetCheckStandLink(CheckStand* checkstand) { _checkStand = checkstand; }
	CheckStand* GetCheckStand() { return _checkStand; }
	void SetNpcState(NpcShopState* npcshopstate);

	//void SetImgKey(string imgkey) { _sprite->SetImgName(imgkey); }

	void In();
	void Stay();
	void Out();


};

