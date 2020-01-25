#pragma once

class Hp
{
private:
	float _curHP, _maxHP;
	bool _isDead;

public:
	Hp() : _curHP(0), _maxHP(0) , _isDead(false) {};
	Hp(float curHP, float maxHP) 
		: _curHP(curHP), _maxHP(maxHP), _isDead(false) {};

	float GetCurrentHP() { return _curHP; }
	float GetMaxHP() { return _maxHP; }

	void setHP(float value);
	void DamageHP(float value);
	void HealHP(float value);
	bool IsDead();

};

