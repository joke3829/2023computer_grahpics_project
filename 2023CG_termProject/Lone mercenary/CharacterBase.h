//============================================================
// CharacterBase.h
// 캐릭터가 중복으로 가지는 정보를 저장하는 기반 클래스
// 상속시켜 사용한다
//============================================================
#pragma once
#include "stdafx.h"

class CharacterBase {
public:
	CharacterBase() = default;
	CharacterBase(float, float, float, float, float);				// 초기화
	virtual ~CharacterBase();
	void Update_HP(float);				// 체력 수정 상대 ATK를 받아와서 사용
	virtual bool Death_check();					// 체력이 0이하면 true 반환

	float getHP();
protected:
	float HP{};				// 체력
	float MAXHP{};			// 최대 체력
	float speed{};			// 이동 속도
	float DEF{};			// 방어력
	float ATK{};			// 플레이어의 경우 현재 든 무기의 공격력을 받아온다.
private:
};