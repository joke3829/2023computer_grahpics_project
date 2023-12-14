#include "MouseFunc.h"
#include "CharacterBase.h"
#include "Player.h"
#include "Field.h"
#include "Select_Item.h"

int MouseFunc::s_x = -10;
int MouseFunc::s_y = -10;

void MouseFunc::Mouse(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		s_x = x;
		s_y = y;
		if (아이템선택 == game_state) {
			//std::cout << x << ", " << y << "\n'";
			dynamic_cast<Player*>(dynamic_cast<Select_Item*>(mScene)->getPlayer())->set_item(x, y);
		}
		if (필드 == game_state) {
			if (!dynamic_cast<Player*>(dynamic_cast<Field*>(mScene)->getPlayer())->do_reload_ani()) {
				dynamic_cast<Player*>(dynamic_cast<Field*>(mScene)->getPlayer())->conti_attack(true);
				//if (dynamic_cast<Player*>(dynamic_cast<Field*>(mScene)->getPlayer())->check_reload_ammo()) {
				//	// ↓↓↓ 이부분이 사격, 연사는 너가 어떻게 처리했는지 몰라서 클릭할때만 들어감
				//	dynamic_cast<Player*>(dynamic_cast<Field*>(mScene)->getPlayer())->attack_check(
				//		dynamic_cast<Field*>(mScene)->getList(), dynamic_cast<Field*>(mScene)->getCamera());
				//	mSound->play_s_shot(dynamic_cast<Player*>(dynamic_cast<Field*>(mScene)->getPlayer())->getWeapon()->getWep());
				//}
			}
		}
		if (결과창 == game_state) {
			std::cout << x << ", " << y << "\n'";
		}
	}
	else if (button == GLUT_LEFT_BUTTON && state == GLUT_UP) {
		if(필드 == game_state)
			dynamic_cast<Player*>(dynamic_cast<Field*>(mScene)->getPlayer())->conti_attack(false);
	}
	glutPostRedisplay();		// ???
}

void MouseFunc::MotionPassive(int x, int y)
{
	if (game_state == 필드) {
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
	case 타이틀:
		break;
	case 메인:
		if (s_x >= 0 && s_x <= 1280 && s_y >= 0 && s_y <= 720) {
			game_state = 아이템선택;
			mSound->play_click();
			return true;
		}
		break;
	case 아이템선택:
		if (1053 <= s_x && s_x <= 1238) {
			if (590 <= s_y && s_y <= 647) {
				game_state = 필드;
				mSound->bgm_off();
				mSound->play_c_reload();
				return true;
			}
		}
		break;
	case 필드:
		break;
	case 결과창:
		if (1053 <= s_x && s_x <= 1238) {
			if (590 <= s_y && s_y <= 647) {
				mSound->play_click();
				game_state = 메인;
				return true;
			}
		}
		else if (42 <= s_x && s_x <= 227) {
			if (590 <= s_y && s_y <= 647) {
				glutLeaveMainLoop();
			}
		}
		break;
	}
	return false;
}