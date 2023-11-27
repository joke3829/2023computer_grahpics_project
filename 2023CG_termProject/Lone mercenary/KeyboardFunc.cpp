
#include "KeyboardFunc.h"
#include "CharacterBase.h"
#include "CameraObj.h"
#include "Player.h"

KeyboardFunc::KeyboardFunc(CharacterBase* t_player, CameraObj* t_camera)
	: mPlayer(t_player), mCamera(t_camera)
{
	game_state = 필드;
}

void KeyboardFunc::Keyboard(unsigned char key, int x, int y)
{
	if (필드 == game_state) {
		switch (key) {
		case 'w':
			dynamic_cast<Player*>(mPlayer)->setMove('w', true);
			break;
		case 'a':
			dynamic_cast<Player*>(mPlayer)->setMove('a', true);
			break;
		case 's':
			dynamic_cast<Player*>(mPlayer)->setMove('s', true);
			break;
		case 'd':
			dynamic_cast<Player*>(mPlayer)->setMove('d', true);
			break;
		case 27:	// ESC 그 잘난 김도영이 해냈습니다.
			glutLeaveMainLoop();
			break;
		case '1':
			dynamic_cast<Player*>(mPlayer)->setWeapon('1');
			break;
		case '2':
			dynamic_cast<Player*>(mPlayer)->setWeapon('2');
			break;
		case '3':
			dynamic_cast<Player*>(mPlayer)->setWeapon('3');
			break;
		case 'r':
			dynamic_cast<Player*>(mPlayer)->setWeapon('r');
			break;
		case '+':
			dynamic_cast<Player*>(mPlayer)->setsensative('+');
			break;
		case '-':
			dynamic_cast<Player*>(mPlayer)->setsensative('-');
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
			dynamic_cast<Player*>(mPlayer)->setMove('w', false);
			break;
		case 'a':
			dynamic_cast<Player*>(mPlayer)->setMove('a', false);
			break;
		case 's':
			dynamic_cast<Player*>(mPlayer)->setMove('s', false);
			break;
		case 'd':
			dynamic_cast<Player*>(mPlayer)->setMove('d', false);
			break;
		}
	}
	glutPostRedisplay();		// ???
}

void KeyboardFunc::setGame_stete(int n)
{
	game_state = n;
}