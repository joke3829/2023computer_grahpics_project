//==================================================================
// MouseFunc.h
// ���콺�� ����
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
	
	bool next_state();

	int getGame_state();
	static int s_x;
	static int s_y;
protected:
private:
	Scene* mScene;
	int game_state;
};