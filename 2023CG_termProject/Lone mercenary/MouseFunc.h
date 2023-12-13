//==================================================================
// MouseFunc.h
// 마우스에 관여
//=================================================================
#pragma once
#include "stdafx.h"
#include "Scene.h"
#include "Field.h"
#include "Sound.h"

class CharacterBase;
class CameraObj;
class MouseFunc {
public:
	MouseFunc() {
		mSound = MySound::GetInstance();
	}
	void Mouse(int,int, int, int);
	void MotionPassive( int, int);

	void setScene(Scene*);
	void setGame_stete(int);
	
	bool next_state();

	int getGame_state();
	static int s_x;
	static int s_y;
protected:
private:
	Scene* mScene;
	MySound* mSound;
	int game_state;
};