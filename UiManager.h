#pragma once
class Inventory;
class UiManager
{
private:

	//Graphic* _coin;
	//Graphic* _bag;
	//Graphic* _bagButton;
	//Graphic* _potionButton;
	//Graphic* _heart;
	//Graphic* _weapon;

	UiObject* _coin;
	UiObject* _bag;
	UiObject* _bagButton;
	UiObject* _potionButton;
	UiObject* _heart;
	UiObject* _weapon;
	Inventory* inven;

public:
	void Init();
	void Update();
	void Render();
	void SetInvenLink(Inventory* inven) { this->inven = inven; }
};

