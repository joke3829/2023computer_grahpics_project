#include "Rifle.h"

Rifle::Rifle(std::string filename, int s_ammo, int r_ammo)
	: Mesh(filename), CharacterBase(0, 0, 0, 0, 20), total_ammo(s_ammo), reloaded_ammo(r_ammo)
{
	weapon_num = 라이플;
}

float Rifle::getATK()
{
	return ATK;
}

void Rifle::Shoot()
{
	if (reloaded_ammo > 0) {
		reloaded_ammo--;
		std::cout << "남은 총알 - " << reloaded_ammo << std::endl;
	}
	else {
		std::cout << "못쏴용가리치킨~" << std::endl;
	}
}