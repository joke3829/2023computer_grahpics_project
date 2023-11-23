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
	if (나이프 != weapon_num) {
		if (reloaded_ammo > 0) {
			reloaded_ammo--;
			std::cout << "남은 총알 - " << reloaded_ammo << std::endl;
		}
		else {
			std::cout << "못쏴용가리치킨~" << std::endl;
		}
	}
}

int Weapon::getWep()
{
	return 0;
}
//====================================================================

Knife::Knife(std::string filename, int s_ammo, int r_ammo) : Weapon(filename,1,1){
	weapon_num = 나이프;
	total_ammo = s_ammo;
	reloaded_ammo = r_ammo;
}


//========================================================================
Pistol::Pistol(std::string filename, int s_ammo, int r_ammo) : Weapon(filename, 1, 1) {
	weapon_num = 권총;
	total_ammo = s_ammo;
	reloaded_ammo = r_ammo;
}

//=================================================================================
Rifle::Rifle(std::string filename, int s_ammo, int r_ammo) : Weapon(filename, 1, 1) {
	weapon_num = 라이플;
	total_ammo = s_ammo;
	reloaded_ammo = r_ammo;
}

//==================================================================================