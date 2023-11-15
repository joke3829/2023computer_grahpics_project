#include "CharacterBase.h"

// 생성자
CharacterBase::CharacterBase(float hp, float max, float spd, float def, float atk)
	: HP(hp), MAXHP(max), speed(spd), DEF(def), ATK(atk) {};

// 파괴자
CharacterBase::~CharacterBase() {};

// 체력 업데이트
void CharacterBase::Update_HP(float received)
{
	if (received > 0) {
		HP += received;
		if (HP >= MAXHP) HP = MAXHP;
	}
	else {
		HP -= received - DEF;		// 계산식은 나중에 생각하자
	}
}

// 죽었는지 체크
bool CharacterBase::Death_check()
{
	if (HP < 0)
		return true;

	return false;
}