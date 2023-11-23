#include "Weapon.h"

Weapon::Weapon(std::string filename, int s_ammo, int r_ammo)
	: Mesh(filename), CharacterBase(0, 0, 0, 0, 0), total_ammo(s_ammo), reloaded_ammo(r_ammo)
{
	weapon_num = 0;
}

int Weapon::getATK()
{
	return ATK;
}

void Weapon::Shoot()
{
	return;
}

int Weapon::getWep()
{
	return 0;
}

Knife::Knife(std::string filename, int s_ammo, int r_ammo) : Weapon(filename,1,1){
	weapon_num = 나이프;
	total_ammo = s_ammo;
	reloaded_ammo = r_ammo;
}

int Knife::getWep() {
	return 나이프;
}

int Knife::getATK()
{
	return 5;
}

void Knife::Shoot()
{
	if (reloaded_ammo > 0) {
		reloaded_ammo = 1;
		std::cout << "남은 총알 - " << reloaded_ammo << std::endl;
	}
}

Pistol::Pistol(std::string filename, int s_ammo, int r_ammo) : Weapon(filename, 1, 1) {
	weapon_num = 권총;
	total_ammo = s_ammo;
	reloaded_ammo = r_ammo;
}

int Pistol::getWep() {
	return 권총;
}

int Pistol::getATK()
{
	return 10;
}

void Pistol::Shoot()
{
	if (reloaded_ammo > 0) {
		reloaded_ammo--;
		std::cout << "남은 총알 - " << reloaded_ammo << std::endl;
	}
	else {
		std::cout << "못쏴용가리치킨~" << std::endl;
	}
}

Rifle::Rifle(std::string filename, int s_ammo, int r_ammo) : Weapon(filename, 1, 1) {
	weapon_num = 라이플;
	total_ammo = s_ammo;
	reloaded_ammo = r_ammo;
}

int Rifle::getWep() {
	return 라이플;
}

int Rifle::getATK()
{
	return 20;
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