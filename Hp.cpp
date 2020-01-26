#include "stdafx.h"
#include "Hp.h"

void Hp::setHP(float value)
{
	_curHP = value;
}

void Hp::DamageHP(float value)
{
	_curHP -= value;

	if (_curHP <= 0)	_curHP = 0;
}

void Hp::HealHP(float value)
{
	_curHP += value;

	if (_curHP >= _maxHP)
	{
		_curHP = _maxHP;
	}
}

bool Hp::IsDead()
{
	if (_curHP <= 0)	isDead = true;
	
	float getHP();  //�հ�...�հ� ������ ����....

	return _curHP;
}
