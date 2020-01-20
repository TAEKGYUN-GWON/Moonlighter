#pragma once

class Npc;
class NpcState;

class NpcManager
{
private:


public:
	void Init();
	void Update();
	void Release();
	void Render();

	void StateControl();
};

