#include "Pistol.h"

Pistol::Pistol(std::string filename, int s_ammo, int r_ammo)
	: Mesh(filename), CharacterBase(0, 0, 0, 0, 10), total_ammo(s_ammo), reloaded_ammo(r_ammo)
{
	weapon_num = ±ÇÃÑ;
}

float Pistol::getATK()
{
	return ATK;
}