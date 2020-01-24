#pragma once
#include"singletonBase.h"
class UiManager : public singletonBase<UiManager>
{
private:
	Graphic* _coin;
	Graphic* _bag;
	Graphic* _bagButton;
	Graphic* _potionButton;
	Graphic* _heart;
	Graphic* _weapon;

public:
	void Init();
	void Update();
	void Render();
};

