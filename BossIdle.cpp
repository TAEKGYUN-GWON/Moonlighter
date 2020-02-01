#include "stdafx.h"
#include "BossIdle.h"
#include "BossAttack.h"
#include "BossRockAtk.h"
#include "BossSlimeAtk.h"
//���� ���� ������
//���� �״°�
//�����Ƽ?

void BossIdle::Enter()
{
	_Bstate = "Idle";

	_count = timer = 0;
	ExitTime = RND->getFromIntTo(5,10);
	

	//_boss->GetSprite()->SetImgName("");
	//_boss->GetSprite()->SetMaxFrameX();
	//_boss->GetSprite()->SetFrameX(0);
	//_boss->GetSprite()->SetPosition()


}

void BossIdle::Update()
{
	timer += TIMEMANAGER->getElapsedTime();
	if (timer >= ExitTime)
	{
		int rand = RND->getInt(2);
		if (rand)
		{
			_boss->SetState(new BossRockAtk(_boss));

		}
		else 
		{
			//_boss �ٸ�����
			_boss->SetState(new BossSlimeAtk(_boss));
		}
			
	}


}

void BossIdle::Exit()
{
}
