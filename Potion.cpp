#include "stdafx.h"
#include "Potion.h"

void Potion::Init()
{
	super::Init();

	_tag = "Potion";
}

void Potion::SetHealRate(int healRate)
{
	_healRate = healRate;
}