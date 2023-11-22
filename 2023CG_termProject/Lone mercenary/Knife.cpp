#include "Knife.h"

Knife::Knife(std::string filename, int s_ammo, int r_ammo)
	: Mesh(filename), CharacterBase(0, 0, 0, 0, 5), total_ammo(s_ammo), reloaded_ammo(r_ammo)
{
	weapon_num = ������;
}

float Knife::getATK()
{
	return ATK;
}

void Knife::Shoot()
{
	if (reloaded_ammo > 0) {
		reloaded_ammo = 1;
		std::cout << "���� �Ѿ� - " << reloaded_ammo << std::endl;
	}
}