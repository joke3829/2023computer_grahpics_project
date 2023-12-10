#include "MouseFunc.h"
#include "CharacterBase.h"
#include "Player.h"
#include "Knife.h"
#include "Rifle.h"
#include "Pistol.h"
#include "Field.h"
#include "Select_Item.h"

int MouseFunc::s_x = -10;
int MouseFunc::s_y = -10;

void MouseFunc::Mouse(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		s_x = x;
		s_y = y;
		if (�����ۼ��� == game_state) {
			std::cout << x << ", " << y << "\n'";
			dynamic_cast<Player*>(dynamic_cast<Select_Item*>(mScene)->getPlayer())->set_item(x, y);
		}
		if (�ʵ� == game_state) {
			dynamic_cast<Player*>(dynamic_cast<Field*>(mScene)->getPlayer())->conti_attack(true);
			// ���� �̺κ��� ���, ����� �ʰ� ��� ó���ߴ��� ���� Ŭ���Ҷ��� ��
			dynamic_cast<Player*>(dynamic_cast<Field*>(mScene)->getPlayer())->attack_check(
				dynamic_cast<Field*>(mScene)->getList(), dynamic_cast<Field*>(mScene)->getCamera());
		}
	}
	else if (button == GLUT_LEFT_BUTTON && state == GLUT_UP) {
		if(�ʵ� == game_state)
			dynamic_cast<Player*>(dynamic_cast<Field*>(mScene)->getPlayer())->conti_attack(false);
	}
	glutPostRedisplay();		// ???
}

void MouseFunc::MotionPassive(int x, int y)
{
	if (game_state == �ʵ�) {
		glutSetCursor(GLUT_CURSOR_NONE);
		glm::vec2 pos = glm::vec2(x, y);
		dynamic_cast<Player*>(dynamic_cast<Field*>(mScene)->getPlayer())->animi_rot(pos.x - 640, pos.y - 360);
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

void MouseFunc::setScene(Scene* t_scene)
{
	mScene = t_scene;
}

bool MouseFunc::next_state()
{
	switch (game_state) {
	case Ÿ��Ʋ:
		break;
	case ����:
		if (s_x >= 0 && s_x <= 1280 && s_y >= 0 && s_y <= 720) {
			game_state = �����ۼ���;
			return true;
		}
		break;
	case �����ۼ���:
		if (1053 <= s_x && s_x <= 1238) {
			if (590 <= s_y && s_y <= 647) {
				game_state = �ʵ�;
				return true;
			}
		}
		break;
	case �ʵ�:
		break;
	case ���â:
		break;
	}
	return false;
}