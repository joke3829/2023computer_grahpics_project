#include "Weapon.h"

//===================================================================
Weapon::Weapon(std::string filename, int s_ammo, int r_ammo, int AT)
	: Mesh(filename), CharacterBase(0, 0, 0, 0, AT), total_ammo(s_ammo), reloaded_ammo(r_ammo)
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
	return weapon_num;
}
//====================================================================

Knife::Knife(std::string filename, int s_ammo, int r_ammo, int AT) : Weapon(filename, s_ammo, r_ammo,AT) {
	weapon_num = 나이프;
}


//========================================================================
Pistol::Pistol(std::string filename, int s_ammo, int r_ammo, int AT) : Weapon(filename, s_ammo, r_ammo, AT) {
	weapon_num = 권총;
}

//=================================================================================
Rifle::Rifle(std::string filename, int s_ammo, int r_ammo, int AT) : Weapon(filename, s_ammo, r_ammo, AT) {
	weapon_num = 라이플;
}

//==================================================================================