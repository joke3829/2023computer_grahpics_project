
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
	Weapon(std::string filename, std::string f_path, int w_size, int h_size, int s_ammo, int r_ammo, int AT);

	int getATK();					// ���ݷ� �޾ƿ���
	void Shoot();					// ����
	int getWep();					// ���� ���� �޾ƿ���
	bool exist_ammo();				// ���� �Ѿ��� �ִ��� -> �ݵ� ���� ������ ���� ����
	void reloading();				// ����
	void D_ammo();					//������ ������ ȿ�� - ź�� 2��

	int gettotal();
	int getreloaded();
protected:
	int weapon_num;			// ���� ��ȣ

	int max_ammo;
	int total_ammo;			// �� ź�� ��
	int reloaded_ammo;		// ������ ź���
private:


};


class Pistol : public Weapon {
public:
	Pistol(std::string filename, std::string f_path, int w_size, int h_size, int s_ammo, int r_ammo,int ATK);
protected:
private:
};


class Knife : public Weapon {
public:
	Knife(std::string filename, std::string f_path, int w_size, int h_size, int s_ammo, int r_ammo, int ATK);
protected:
private:
};


class Rifle : public Weapon {
public:
	Rifle(std::string filename, std::string f_path, int w_size, int h_size, int s_ammo, int r_ammo, int ATK);
protected:
private:
};