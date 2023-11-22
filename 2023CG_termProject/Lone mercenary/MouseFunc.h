//==================================================================
// MouseFunc.h
// 마우스에 관여
//=================================================================
#pragma once
#include "stdafx.h"

class CharacterBase;
class CameraObj;
class MouseFunc {
public:
	MouseFunc(CharacterBase*);

	void Mouse(int,int, int, int);
	void MotionPassive( int, int);

	void setGame_stete(int);
protected:
private:
	CharacterBase* mPlayer{ nullptr };
	int game_state;
};