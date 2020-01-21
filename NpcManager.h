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

//npc 중에 isactive(ㅇ기ㅓ말고 다른거 써야함) 인 애가 있으면
//erase.

