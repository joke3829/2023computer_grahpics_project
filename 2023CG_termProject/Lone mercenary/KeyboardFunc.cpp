
#include "KeyboardFunc.h"
#include "CharacterBase.h"
#include "CameraObj.h"
#include "Player.h"
#include "Field.h"


void KeyboardFunc::setScene(Scene* t_scene)
{
	mScene = t_scene;
}

void KeyboardFunc::Keyboard(unsigned char key, int x, int y)
{
	if (메인 == game_state) {
		switch (key) {
		case 27:
			glutLeaveMainLoop();
			break;
		}
	}
	if (필드 == game_state) {
		switch (key) {
		case 'w':
			dynamic_cast<Player*>(dynamic_cast<Field*>(mScene)->getPlayer())->setMove('w', true);
			break;
		case 'a':
			dynamic_cast<Player*>(dynamic_cast<Field*>(mScene)->getPlayer())->setMove('a', true);
			break;
		case 's':
			dynamic_cast<Player*>(dynamic_cast<Field*>(mScene)->getPlayer())->setMove('s', true);
			break;
		case 'd':
			dynamic_cast<Player*>(dynamic_cast<Field*>(mScene)->getPlayer())->setMove('d', true);
			break;
		case 27:	// ESC 그 잘난 김도영이 해냈습니다.
			glutLeaveMainLoop();
			break;
		case '1':
			dynamic_cast<Player*>(dynamic_cast<Field*>(mScene)->getPlayer())->setWeapon('1');
			break;
		case '2':
			dynamic_cast<Player*>(dynamic_cast<Field*>(mScene)->getPlayer())->setWeapon('2');
			break;
		case '3':
			dynamic_cast<Player*>(dynamic_cast<Field*>(mScene)->getPlayer())->setWeapon('3');
			break;
		case 'r':
			dynamic_cast<Player*>(dynamic_cast<Field*>(mScene)->getPlayer())->setWeapon('r');
			break;
		case '+':
			dynamic_cast<Player*>(dynamic_cast<Field*>(mScene)->getPlayer())->setsensative('+');
			break;
		case '-':
			dynamic_cast<Player*>(dynamic_cast<Field*>(mScene)->getPlayer())->setsensative('-');
			break;
		case ']':
			dynamic_cast<Field*>(mScene)->getPlayer()->Update_HP(10);
			break;
		case '[':
			dynamic_cast<Field*>(mScene)->getPlayer()->Update_HP(-1);
			break;
		case 't':
			if (Mesh::box_check)
				Mesh::box_check = false;
			else
				Mesh::box_check = true;
			break;
		}
	}
	glutPostRedisplay();		// ???
}

void KeyboardFunc::KeyboardUp(unsigned char key, int x, int y)
{
	if (필드 == game_state) {
		switch (key) {
		case 'w':
			dynamic_cast<Player*>(dynamic_cast<Field*>(mScene)->getPlayer())->setMove('w', false);
			break;
		case 'a':
			dynamic_cast<Player*>(dynamic_cast<Field*>(mScene)->getPlayer())->setMove('a', false);
			break;
		case 's':
			dynamic_cast<Player*>(dynamic_cast<Field*>(mScene)->getPlayer())->setMove('s', false);
			break;
		case 'd':
			dynamic_cast<Player*>(dynamic_cast<Field*>(mScene)->getPlayer())->setMove('d', false);
			break;
		}
	}
	glutPostRedisplay();		// ???
}

void KeyboardFunc::setGame_stete(int n)
{
	game_state = n;
}