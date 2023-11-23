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
	weapon_num = ������;
	total_ammo = s_ammo;
	reloaded_ammo = r_ammo;
}

int Knife::getWep() {
	return ������;
}

int Knife::getATK()
{
	return 5;
}

void Knife::Shoot()
{
	if (reloaded_ammo > 0) {
		reloaded_ammo = 1;
		std::cout << "���� �Ѿ� - " << reloaded_ammo << std::endl;
	}
}

Pistol::Pistol(std::string filename, int s_ammo, int r_ammo) : Weapon(filename, 1, 1) {
	weapon_num = ����;
	total_ammo = s_ammo;
	reloaded_ammo = r_ammo;
}

int Pistol::getWep() {
	return ����;
}

int Pistol::getATK()
{
	return 10;
}

void Pistol::Shoot()
{
	if (reloaded_ammo > 0) {
		reloaded_ammo--;
		std::cout << "���� �Ѿ� - " << reloaded_ammo << std::endl;
	}
	else {
		std::cout << "�����밡��ġŲ~" << std::endl;
	}
}

Rifle::Rifle(std::string filename, int s_ammo, int r_ammo) : Weapon(filename, 1, 1) {
	weapon_num = ������;
	total_ammo = s_ammo;
	reloaded_ammo = r_ammo;
}

int Rifle::getWep() {
	return ������;
}

int Rifle::getATK()
{
	return 20;
}

void Rifle::Shoot()
{
	if (reloaded_ammo > 0) {
		reloaded_ammo--;
		std::cout << "���� �Ѿ� - " << reloaded_ammo << std::endl;
	}
	else {
		std::cout << "�����밡��ġŲ~" << std::endl;
	}
}