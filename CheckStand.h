#pragma once
#include "Object.h"

class CheckStand :public Object
{
private:
	bool _isInUse;

public:

	virtual void Init(Vector2 pos, Vector2 scale);
	virtual void Release() override;
	virtual void Update() override;
	virtual void Render() override;

	void SetStandisInUse(bool isinuse) { _isInUse = isinuse; }
	bool GetStandState() { return _isInUse; }

	
};

