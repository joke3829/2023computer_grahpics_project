//==================================================================
// MouseFunc.h
// 마우스에 관여
//=================================================================
#pragma once
#include "stdafx.h"
#include "Scene.h"
#include "Field.h"

class CharacterBase;
class CameraObj;
class MouseFunc {
public:
	void Mouse(int,int, int, int);
	void MotionPassive( int, int);

	void setScene(Scene*);
	void setGame_stete(int);
	int getGame_state();
protected:
private:
	Scene* mScene;
	int game_state;
};