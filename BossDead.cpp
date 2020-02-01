#include "stdafx.h"
#include "BossDead.h"

void BossDead::Enter()
{
	_Bstate = "Dead";

	//_boss->GetSprite()->SetMaxFrameX(41);
	//죽는 이미지가 두개로 나눠져 있음....어떻게 하지?
	//두번째 죽는 이미도 41프레임
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
