#include "MouseFunc.h"
#include "CharacterBase.h"
#include "Player.h"
#include "Knife.h"
#include "Rifle.h"
#include "Pistol.h"

MouseFunc::MouseFunc(CharacterBase* t_player)
	: mPlayer(t_player)
{
	game_state = �����ۼ���;
}

void MouseFunc::Mouse(int button, int state, int x, int y)
{
	if (game_state == �����ۼ���) {
		if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
			dynamic_cast<Player*>(mPlayer)->set_item(x,y);
			if (950 <= x && x <= 1250) {
				if (500 <= y && y <= 700) {
					setGame_stete(�ʵ�);
				}
			}
		}
	}
	if (game_state == �ʵ�) {
		if (button == GLUT_LEFT_BUTTON) {
			if (state == GLUT_DOWN) {
				dynamic_cast<Player*>(mPlayer)->conti_attack(true);
			}
			else {
				dynamic_cast<Player*>(mPlayer)->conti_attack(false);
			}
		}
	}
	glutPostRedisplay();		// ???
}

void MouseFunc::MotionPassive(int x, int y)
{
	if (game_state == �ʵ�) {
		glutSetCursor(GLUT_CURSOR_NONE);
		glm::vec2 pos = glm::vec2(x, y);
		dynamic_cast<Player*>(mPlayer)->animi_rot(pos.x - 640, pos.y - 360);
		glutWarpPointer(1280 / 2, 720 / 2);
	}
	glutPostRedisplay();		// ???
}

void MouseFunc::setGame_stete(int n)
{
	game_state = n;
}

int MouseFunc::getGame_state()
{
	return game_state;
}
