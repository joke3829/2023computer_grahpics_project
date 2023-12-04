//==================================================================
// KeyboardFunc.h
// 키보드 입력에 관여
//=================================================================
#pragma once
#include "stdafx.h"
#include "Scene.h"

class CharacterBase;
class CameraObj;
class KeyboardFunc {
public:
	//KeyboardFunc(CharacterBase*, CameraObj*);


	void Keyboard(unsigned char, int, int);
	void KeyboardUp(unsigned char, int, int);

	void setScene(Scene*);

	void setGame_stete(int);
protected:
private:
	/*CharacterBase* mPlayer{ nullptr };
	CameraObj* mCamera{ nullptr };*/
	Scene* mScene{ nullptr };
	int game_state;
};