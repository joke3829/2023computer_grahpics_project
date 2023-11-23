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

	virtual int getATK();					// ���ݷ� �޾ƿ���
	virtual void Shoot();
	virtual int getWep();
protected:
	int weapon_num;			// ���� ��ȣ


	int total_ammo;			// �� ź�� ��
	int reloaded_ammo;		// ������ ź���
private:


};
class Pistol : public Weapon {
public:
	Pistol(std::string filename, int s_ammo, int r_ammo);
	virtual int getATK();
	virtual void Shoot();
	virtual int getWep();
protected:
private:
};
class Knife : public Weapon {
public:
	Knife(std::string filename, int s_ammo, int r_ammo);
	virtual int getATK();
	virtual void Shoot();
	virtual int getWep();
protected:
private:
	int weapon_num;			// ���� ��ȣ


	int total_ammo;			// �� ź�� ��
	int reloaded_ammo;		// ������ ź���
};
class Rifle : public Weapon {
public:
	Rifle(std::string filename, int s_ammo, int r_ammo);
	virtual int getATK();
	virtual void Shoot();
	virtual int getWep();
protected:
private:
	int weapon_num;			// ���� ��ȣ


	int total_ammo;			// �� ź�� ��
	int reloaded_ammo;		// ������ ź���
};