#include "Weapon.h"

//===================================================================
Weapon::Weapon(std::string filename, int s_ammo, int r_ammo)
	: Mesh(filename), CharacterBase(0, 0, 0, 0, 0), total_ammo(s_ammo), reloaded_ammo(r_ammo)
{
}

int Weapon::getATK()
{
	return ATK;
}

void Weapon::Shoot()
{
	if (������ != weapon_num) {
		if (reloaded_ammo > 0) {
			reloaded_ammo--;
			std::cout << "���� �Ѿ� - " << reloaded_ammo << std::endl;
		}
		else {
			std::cout << "�����밡��ġŲ~" << std::endl;
		}
	}
}

int Weapon::getWep()
{
	return 0;
}
//====================================================================

Knife::Knife(std::string filename, int s_ammo, int r_ammo) : Weapon(filename,1,1){
	weapon_num = ������;
	total_ammo = s_ammo;
	reloaded_ammo = r_ammo;
}


//========================================================================
Pistol::Pistol(std::string filename, int s_ammo, int r_ammo) : Weapon(filename, 1, 1) {
	weapon_num = ����;
	total_ammo = s_ammo;
	reloaded_ammo = r_ammo;
}

//=================================================================================
Rifle::Rifle(std::string filename, int s_ammo, int r_ammo) : Weapon(filename, 1, 1) {
	weapon_num = ������;
	total_ammo = s_ammo;
	reloaded_ammo = r_ammo;
}

//==================================================================================