#include "stdafx.h"
#include "ETCS.h"

void Vine::Init(Vector2 pos)
{
	super::Init();

	_trans->SetPos(pos);
	_name = "Vine";

	_image = AddComponent<Sprite>();
	_image->SetImgName("\resource\img\Items\Items");
	_image->SetFrameX(3);
	_image->SetFrameY(2);
}

void Crystal_Energy::Init(Vector2 pos)
{
	super::Init();

	_trans->SetPos(pos);
	_name = "Crystal_Energy";

	_image = AddComponent<Sprite>();
	_image->SetImgName("\resource\img\Items\Items");
	_image->SetFrameX(2);
	_image->SetFrameY(2);
}

void Treated_Wood::Init(Vector2 pos)
{
	super::Init();

	_trans->SetPos(pos);
	_name = "Treated_Wood";

	_image = AddComponent<Sprite>();
	_image->SetImgName("\resource\img\Items\Items");
	_image->SetFrameX(1);
	_image->SetFrameY(2);
}

void amulet_ring::Init(Vector2 pos)
{
	super::Init();

	_trans->SetPos(pos);
	_name = "amulet_ring";

	_image = AddComponent<Sprite>();
	_image->SetImgName("\resource\img\Items\Items");
	_image->SetFrameX(0);
	_image->SetFrameY(2);
}

void Broken_Sword::Init(Vector2 pos)
{
	super::Init();

	_trans->SetPos(pos);
	_name = "Broken_Sword";

	_image = AddComponent<Sprite>();
	_image->SetImgName("\resource\img\Items\Items");
	_image->SetFrameX(3);
	_image->SetFrameY(1);
}

void Energy_Crystal::Init(Vector2 pos)
{
	super::Init();

	_trans->SetPos(pos);
	_name = "Energy_Crystal";

	_image = AddComponent<Sprite>();
	_image->SetImgName("\resource\img\Items\Items");
	_image->SetFrameX(2);
	_image->SetFrameY(1);
}

void Naja_Note::Init(Vector2 pos)
{
	super::Init();

	_trans->SetPos(pos);
	_name = "Naja_Note";

	_image = AddComponent<Sprite>();
	_image->SetImgName("\resource\img\Items\Items");
	_image->SetFrameX(1);
	_image->SetFrameY(1);
}

void Reinforced_Steel_G::Init(Vector2 pos)
{
	super::Init();

	_trans->SetPos(pos);
	_name = "Reinforced_Steel_G";

	_image = AddComponent<Sprite>();
	_image->SetImgName("\resource\img\Items\Items");
	_image->SetFrameX(0);
	_image->SetFrameY(1);
}

void Golem_Core::Init(Vector2 pos)
{
	super::Init();

	_trans->SetPos(pos);
	_name = "Golem_Core";

	_image = AddComponent<Sprite>();
	_image->SetImgName("\resource\img\Items\Items");
	_image->SetFrameX(3);
	_image->SetFrameY(0);
}

void Familiar_Egg::Init(Vector2 pos)

{
	super::Init();

	_trans->SetPos(pos);
	_name = "Familiar_Egg";

	_image = AddComponent<Sprite>();
	_image->SetImgName("\resource\img\Items\Items");
	_image->SetFrameX(2);
	_image->SetFrameY(0);
}

void Reinforced_Steel_Y::Init(Vector2 pos)
{
	super::Init();

	_trans->SetPos(pos);
	_name = "Reinforced_Steel_Y";

	_image = AddComponent<Sprite>();
	_image->SetImgName("\resource\img\Items\Items");
	_image->SetFrameX(1);
	_image->SetFrameY(0);
}

void Golem_King_Design::Init(Vector2 pos)
{
	super::Init();

	_trans->SetPos(pos); 
	_name = "Golem_King_Design ";

	_image = AddComponent<Sprite>();
	_image->SetImgName("\resource\img\Items\Items");
	_image->SetFrameX(0);
	_image->SetFrameY(0);
}
