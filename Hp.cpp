#include "stdafx.h"
#include "Hp.h"

void Hp::setHP(float value)
{
	_curHP = value;
}

void Hp::DamageHP(float value)
{
	_curHP -= value;

	//if (_curHP <= 0) _curHP = 0;
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
	if (_curHP <= 0)
	{
		_curHP = 0;
		return true;
	}
	
	//float getHP();  //먼가...먼가 부족한 느낌....
					  //함께 채워가요★ㅋㅋㅋㅋㅋ

	return false;
}
