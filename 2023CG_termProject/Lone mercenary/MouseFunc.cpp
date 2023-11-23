#include "MouseFunc.h"
#include "CharacterBase.h"
#include "Player.h"
#include "Knife.h"
#include "Rifle.h"
#include "Pistol.h"

MouseFunc::MouseFunc(CharacterBase* t_player)
	: mPlayer(t_player)
{
	game_state = 필드;
}

void MouseFunc::Mouse(int button, int state, int x, int y)
{
	if (필드 == game_state) {
		if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
			dynamic_cast<Player*>(mPlayer)->attack();
		}
	}
	glutPostRedisplay();		// ???
}

void MouseFunc::MotionPassive(int x, int y)
{
	if (필드 == game_state) {
		auto pos = glm::vec2(x, y);
		dynamic_cast<Player*>(mPlayer)->animi_rot(pos.x - 640, pos.y - 360);
		glutWarpPointer(1280 / 2, 720 / 2);
	}
	glutPostRedisplay();		// ???
}

void MouseFunc::setGame_stete(int n)
{
	game_state = n;
}