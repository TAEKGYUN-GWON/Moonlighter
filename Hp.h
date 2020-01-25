#pragma once

class Hp
{
private:
	float _curHP, _maxHP;
	bool isDead;

public:
	void setHP(float value);
	void DamageHP(float value);
	void HealHP(float value);
	bool IsDead();

};

