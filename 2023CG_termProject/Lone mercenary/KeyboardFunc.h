//==================================================================
// KeyboardFunc.h
// Ű���� �Է¿� ����
//=================================================================
#pragma once
#include "stdafx.h"

class CharacterBase;
class CameraObj;
class KeyboardFunc {
public:
	KeyboardFunc(CharacterBase*, CameraObj*);

	void Keyboard(unsigned char, int, int);
	void KeyboardUp(unsigned char, int, int);

	void setGame_stete(int);
protected:
private:
	CharacterBase* mPlayer{ nullptr };
	CameraObj* mCamera{ nullptr };
	int game_state;
};