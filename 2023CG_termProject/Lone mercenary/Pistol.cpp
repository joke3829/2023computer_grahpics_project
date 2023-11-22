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

void Pistol::Shoot()
{
	if (reloaded_ammo > 0) {
		reloaded_ammo--;
		std::cout << "³²Àº ÃÑ¾Ë - " << reloaded_ammo << std::endl;
	}
	else {
		std::cout << "¸ø½÷¿ë°¡¸®Ä¡Å²~"<< std::endl;
	}
}