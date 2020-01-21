#pragma once
#include "Object.h"

class CheckStand :public Object
{
private:
	bool _isInUse;

public:

	void SetStandState(bool isinuse) { _isInUse = isinuse; }
	bool GetStandState() { return _isInUse; }
};

