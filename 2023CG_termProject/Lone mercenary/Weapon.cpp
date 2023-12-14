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

void Weapon::plusammo(int n)
{
	total_ammo += n;
}

void Weapon::Shoot()
{
	if (³ªÀÌÇÁ != weapon_num) {
		if (reloaded_ammo > 0) {
			reloaded_ammo--;
			//std::cout << "³²Àº ÃÑ¾Ë - " << reloaded_ammo << std::endl;
		}
		else {
			//std::cout << "¸ø½÷¿ë°¡¸®Ä¡Å²~" << std::endl;
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
	if (reloaded_ammo != max_ammo) {
		if (total_ammo > 0) {
			last = max_ammo - reloaded_ammo;
			if (total_ammo >= last) {
				reloaded_ammo = max_ammo;
				total_ammo -= last;
				//std::cout << "³²Àº ÃÑ ÃÑ¾Ë - " << total_ammo << "ÀåÀüµÈ ÃÑ¾Ë - " << reloaded_ammo << std::endl;
			}
			else {
				reloaded_ammo += total_ammo;
				total_ammo = 0;
				//std::cout << "³²Àº ÃÑ ÃÑ¾Ë - " << total_ammo << "ÀåÀüµÈ ÃÑ¾Ë - " << reloaded_ammo << std::endl;
			}
		}
		else {
			//std::cout << "³²Àº ÃÑ¾ËÀÌ ¾ø¾îÀ¯~" << std::endl;
		}
	}
}
void Weapon::D_ammo()
{
	total_ammo *= 2;
}

bool Weapon::is_max()
{
	if ((reloaded_ammo < max_ammo)) {
		return true;
	}
	else {
		return false;
	}
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
	weapon_num = ³ªÀÌÇÁ;
}


//========================================================================
Pistol::Pistol(std::string filename, std::string f_path, int w_size, int h_size, int s_ammo, int r_ammo, int AT) : Weapon(filename, f_path, w_size, h_size, s_ammo, r_ammo, AT) {
	weapon_num = ±ÇÃÑ;
}

//=================================================================================
Rifle::Rifle(std::string filename, std::string f_path, int w_size, int h_size, int s_ammo, int r_ammo, int AT) : Weapon(filename, f_path, w_size, h_size, s_ammo, r_ammo, AT) {
	weapon_num = ¶óÀÌÇÃ;
}

//==================================================================================