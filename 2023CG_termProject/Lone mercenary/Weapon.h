#pragma once
//=========================================================
// Weapon.h
// ���� Ŭ����
//=========================================================
#pragma once

#include "stdafx.h"
#include "Mesh.h"
#include "CharacterBase.h"

class Weapon : public Mesh, public CharacterBase {
public:
	Weapon(std::string filename, int s_ammo, int r_ammo);

	int getATK();					// ���ݷ� �޾ƿ���
	void Shoot();
	int getWep();
protected:
	int weapon_num;			// ���� ��ȣ


	int total_ammo;			// �� ź�� ��
	int reloaded_ammo;		// ������ ź���
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