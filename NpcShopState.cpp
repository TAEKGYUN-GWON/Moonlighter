#include "stdafx.h"
#include "NpcShopState.h"
#include "Npc.h"

//IDLE==========================
void NpcIdle::Enter()
{
	_state = "Idle";


}

void NpcIdle::Update()
{
	//��ǥ�� �޾Ƽ�. ����, ���Ǵ� �� �� �ٸ��� ó����
	

}

void NpcIdle::Exit()
{
}

//MOVE==========================
void NpcMove::Enter()
{
	_state = "Move";
	_timer = 0.0f;
}

void NpcMove::Update()
{
	if (_npc->GetPath()->size())
	{
		if (!_npc->GetIsAstarOn()) //������ ������ false ����
		{
			Vector2 a = *_npc->GetPath()->begin() - _npc->GetTrans()->GetPos(); // ��������ġ���� ����ġ�� ����, ���ߵǴ� ���� ��尡 ����
			float b = Vector2::GetAngle( _npc->GetTrans()->GetPos(), *_npc->GetPath()->begin());
		
			_npc->GetTrans()->SetPos(_npc->GetTrans()->GetPos() + Vector2(cosf(b),-sinf(b)) * 50 * TIMEMANAGER->getElapsedTime());

			if ((int)Vector2::Distance(*_npc->GetPath()->begin(), _npc->GetTrans()->GetPos()) < (int)2)//���� �����ϰ� ����ó�� ���ִ� �κ�
				_npc->GetPath()->pop_front(); //���� ù��° ������ �����, ���� ��带 �ֱ� ����
		}
	
	}
	else //������ ������ �ణ�� ���� �� ���� true �����
	{
		_timer += TIMEMANAGER->getElapsedTime();
		if (_timer > 2)
		{
			_npc->SetIsAstarOn(true);
			_timer = 0;
			_npc->ChangeState(new NpcIdle(_npc));
		}
	}
}

void NpcMove::Exit()
{
}

//HOME==========================
void NpcHome::Enter()
{
	_state = "Home";
}

void NpcHome::Update()
{
}

void NpcHome::Exit()
{
}
