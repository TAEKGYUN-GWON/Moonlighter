#include "stdafx.h"
#include "BossDead.h"

void BossDead::Enter()
{
	_Bstate = "Dead";

	//_boss->GetSprite()->SetMaxFrameX(41);
	//�״� �̹����� �ΰ��� ������ ����....��� ����?
	//�ι�° �״� �̵̹� 41������
	//_boss->GetSprite()->SetMaxFrameX(41);
	//_boss->GetSprite()->SetFrameX(0);
	//_boss->GetSprite()->SetFrameY(0);
	//_boss->GetSprite()->SetFPS(1.0f);
	//_boss->GetSprite()->SetIsLoop(false);
}

void BossDead::Update()
{
}

void BossDead::Exit()
{
}
