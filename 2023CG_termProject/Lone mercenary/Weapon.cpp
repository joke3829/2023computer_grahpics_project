#include "Weapon.h"

//===================================================================
Weapon::Weapon(std::string filename, std::string f_path, int w_size, int h_size, int s_ammo, int r_ammo, int AT)
	: Mesh(filename, f_path, w_size, h_size), CharacterBase(0, 0, 0, 0, AT), total_ammo(s_ammo), reloaded_ammo(r_ammo)
{
	max_ammo = r_ammo;
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
	return weapon_num;
}

bool Weapon::exist_ammo()
{
	if (reloaded_ammo > 0) {
		return true;
	}
	else {
		return false;
	}
}

void Weapon::reloading()
{
	int last = 0;
	if (total_ammo > 0) {
		last = max_ammo - reloaded_ammo;
		if (total_ammo >= last) {
			reloaded_ammo = max_ammo;
			total_ammo -= last;
			std::cout << "���� �� �Ѿ� - " << total_ammo << "������ �Ѿ� - " << reloaded_ammo << std::endl;
		}
		else {
			reloaded_ammo += total_ammo;
			total_ammo = 0;
			std::cout << "���� �� �Ѿ� - " << total_ammo << "������ �Ѿ� - " << reloaded_ammo << std::endl;
		}
	}
	else {
		std::cout << "���� �Ѿ��� ������~"<< std::endl;
	}
}
void Weapon::D_ammo()
{
	total_ammo *= 2;
}

int Weapon::gettotal()
{
	return total_ammo;
}

int Weapon::getreloaded()
{
	return reloaded_ammo;
}
//====================================================================

Knife::Knife(std::string filename, std::string f_path, int w_size, int h_size, int s_ammo, int r_ammo, int AT) : Weapon(filename, f_path, w_size, h_size, s_ammo, r_ammo,AT) {
	weapon_num = ������;
}


//========================================================================
Pistol::Pistol(std::string filename, std::string f_path, int w_size, int h_size, int s_ammo, int r_ammo, int AT) : Weapon(filename, f_path, w_size, h_size, s_ammo, r_ammo, AT) {
	weapon_num = ����;
}

//=================================================================================
Rifle::Rifle(std::string filename, std::string f_path, int w_size, int h_size, int s_ammo, int r_ammo, int AT) : Weapon(filename, f_path, w_size, h_size, s_ammo, r_ammo, AT) {
	weapon_num = ������;
}

//==================================================================================