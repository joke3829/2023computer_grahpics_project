//==================================================================
// MouseFunc.h
// ���콺�� ����
//=================================================================
#pragma once
#include "stdafx.h"

class CharacterBase;
class CameraObj;
class MouseFunc {
public:
	MouseFunc(CharacterBase*);

	void Mouse(int,int, int, int);
	void Motion( int, int);

	void setGame_stete(int);
protected:
private:
	CharacterBase* mPlayer{ nullptr };
	int game_state;
};