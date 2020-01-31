#include "stdafx.h"
#include "ETCS.h"

void Vine::Init(Vector2 pos)
{
	super::Init();

	_trans->SetPos(pos);
	_name = "vine";

	_image->SetImgName("Vine");
}

void Crystal_Energy::Init(Vector2 pos)
{
	super::Init();

	_trans->SetPos(pos);
	_name = "crystal_Energy";


	_image->SetImgName("Crystal_Energy");
}

void Treated_Wood::Init(Vector2 pos)
{
	super::Init();

	_trans->SetPos(pos);
	_name = "treated_Wood";
	_image->SetImgName("Treated_Wood");

}

void amulet_ring::Init(Vector2 pos)
{
	super::Init();

	_trans->SetPos(pos);
	_name = "amulet_ring";
	_image->SetImgName("amulet_ring");
	
}

void Broken_Sword::Init(Vector2 pos)
{
	super::Init();

	_trans->SetPos(pos);
	_name = "broken_Sword";

	_image->SetImgName("Broken_Sword");
}

void Energy_Crystal::Init(Vector2 pos)
{
	super::Init();

	_trans->SetPos(pos);
	_name = "energy_Crystal";

	_image->SetImgName("Energy_Crystal");
}

void Naja_Note::Init(Vector2 pos)
{
	super::Init();

	_trans->SetPos(pos);
	_name = "naja_Note";

	_image->SetImgName("Naja_Note");
}

void Reinforced_Steel_G::Init(Vector2 pos)
{
	super::Init();

	_trans->SetPos(pos);
	_name = "reinforced_Steel_G";

	_image->SetImgName("Reinforced_Steel_G");
}

void Golem_Core::Init(Vector2 pos)
{
	super::Init();

	_trans->SetPos(pos);
	_name = "golem_Core";

	_image->SetImgName("Golem_Core");

}

void Familiar_Egg::Init(Vector2 pos)

{
	super::Init();

	_trans->SetPos(pos);
	_name = "familiar_Egg";

	_image->SetImgName("Familiar_Egg");
}

void Reinforced_Steel_Y::Init(Vector2 pos)
{
	super::Init();

	_trans->SetPos(pos);
	_name = "reinforced_Steel_Y";

	_image->SetImgName("Reinforced_Steel_Y");
}

void Golem_King_Design::Init(Vector2 pos)
{
	super::Init();

	_trans->SetPos(pos); 
	_name = "golem_King_Design";

	_image->SetImgName("Golem_King_Design");
}
