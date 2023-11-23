#pragma once
//=========================================================
// Weapon.h
// 무기 클래스
//=========================================================
#pragma once

#include "stdafx.h"
#include "Mesh.h"
#include "CharacterBase.h"

class Weapon : public Mesh, public CharacterBase {
public:
	Weapon(std::string filename, int s_ammo, int r_ammo);

	int getATK();					// 공격력 받아오기
	void Shoot();
	int getWep();
protected:
	int weapon_num;			// 무기 번호


	int total_ammo;			// 총 탄약 수
	int reloaded_ammo;		// 장전된 탄약수
private:


};


class Pistol : public Weapon {
public:
	Pistol(std::string filename, int s_ammo, int r_ammo);
protected:
private:
};


class Knife : public Weapon {
public:
	Knife(std::string filename, int s_ammo, int r_ammo);
protected:
private:
};


class Rifle : public Weapon {
public:
	Rifle(std::string filename, int s_ammo, int r_ammo);
protected:
private:
};