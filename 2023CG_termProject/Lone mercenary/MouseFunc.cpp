#include "MouseFunc.h"
#include "CharacterBase.h"
#include "Player.h"

MouseFunc::MouseFunc(CharacterBase* t_player)
	: mPlayer(t_player)
{
	game_state = �ʵ�;
}

void MouseFunc::Mouse(int button,int state, int x, int y)
{
	if (�ʵ� == game_state) {
		
	}
	glutPostRedisplay();		// ???
}

void MouseFunc::MotionPassive(int x, int y)
{
	if (�ʵ� == game_state) {

		glutWarpPointer(1280 / 2, 720 / 2);
	}
	glutPostRedisplay();		// ???
}

void MouseFunc::setGame_stete(int n)
{
	game_state = n;
}