
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
	Weapon(std::string filename, std::string f_path, int w_size, int h_size, int s_ammo, int r_ammo, int AT);

	int getATK();					// 공격력 받아오기
	void Shoot();					// 공격
	int getWep();					// 무기 정보 받아오기
	bool exist_ammo();				// 남은 총알이 있는지 -> 반동 적용 미적용 결정 요인
	void reloading();				// 장전
	void D_ammo();					//시작전 아이템 효과 - 탄약 2배
	bool is_max();
	int gettotal();
	int getreloaded();

	void plusammo(int);
protected:
	int weapon_num;			// 무기 번호

	int max_ammo;
	int total_ammo;			// 총 탄약 수
	int reloaded_ammo;		// 장전된 탄약수
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