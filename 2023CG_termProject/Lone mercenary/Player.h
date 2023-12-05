//============================================================
// Player.h
// 플레이어 헤더
// 플레이어 조종 및 관리
//============================================================


#pragma once
#include "CharacterBase.h"
#include "Weapon.h"

class Player : public CharacterBase {
private:
	glm::vec3 cur_loc;			// 플레이어 현재 위치, 총기랑 카메라에 넘겨주자
	glm::vec2 cur_rot;			// 플레이어가 바라보는 방향(0, 0)이면 x축이 증가하는 방향을 바라본다. 마찬가지로 넘겨주기
	glm::vec2 init_Weapon_rot;
	bool item[4];
	bool move[4];		// 0 w, 1 a
	bool atck;
	bool changing;
	int weapon;
	int cnt; //적당한 시간에 쏘자!
	float mousesense;
	Weapon* cur_Wea = nullptr;
	Weapon* pistol;
	Weapon* rifle;
	Weapon* knife;
protected:

public:
	Player(float hp, float max, float spd, float def, float atk);

	// 애니메이션 함수 만들기
	void animation();
	void animi_rot(int, int);
	void setMove(char, bool);
	void setsensative(char);
	void setWeapon(char);
	void attack();
	void conti_attack(bool);
	void take_out_Wep();
	void set_item(int, int);
	void apply_item();
	glm::vec3 getLoc();				// 현재 위치 받아오기
	glm::vec2 getRot();				// 현재 바라보는 방향 받아오기
	glm::vec2 getWepRot();			// 현재 바라보는 방향에 맞춰 총기위치 지정하기

	Weapon* getWeapon() const;		// 내가 들고 있는 무기 정보 받기
	int Weapon();
};