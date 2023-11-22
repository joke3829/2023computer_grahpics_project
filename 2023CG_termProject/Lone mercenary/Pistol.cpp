#include "Pistol.h"

Pistol::Pistol(std::string filename, int s_ammo, int r_ammo)
	: Mesh(filename), CharacterBase(0, 0, 0, 0, 10), total_ammo(s_ammo), reloaded_ammo(r_ammo)
{
	weapon_num = ����;
}

float Pistol::getATK()
{
	return ATK;
}

void Pistol::Shoot()
{
	if (reloaded_ammo > 0) {
		reloaded_ammo--;
		std::cout << "���� �Ѿ� - " << reloaded_ammo << std::endl;
	}
	else {
		std::cout << "�����밡��ġŲ~"<< std::endl;
	}
}