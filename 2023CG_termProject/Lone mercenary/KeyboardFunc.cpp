
#include "KeyboardFunc.h"
#include "CharacterBase.h"
#include "CameraObj.h"
#include "Player.h"

KeyboardFunc::KeyboardFunc(CharacterBase* t_player, CameraObj* t_camera)
	: mPlayer(t_player), mCamera(t_camera)
{
	game_state = �ʵ�;
}

void KeyboardFunc::Keyboard(unsigned char key, int x, int y)
{
	if (�ʵ� == game_state) {
		switch (key) {
		case 'w':
			dynamic_cast<Player*>(mPlayer)->setMove('w', true);
			break;
<<<<<<< Updated upstream
=======
		case 'a':
			dynamic_cast<Player*>(mPlayer)->setMove('a', true);
			break;
		case 's':
			dynamic_cast<Player*>(mPlayer)->setMove('s', true);
			break;
		case 'd':
			dynamic_cast<Player*>(mPlayer)->setMove('d', true);
			break;
		case 27:	// ESC �� �߳� �赵���� �س½��ϴ�.
			glutLeaveMainLoop();
			break;
>>>>>>> Stashed changes
		}
	}
	glutPostRedisplay();		// ???
}

void KeyboardFunc::KeyboardUp(unsigned char key, int x, int y)
{
	if (�ʵ� == game_state) {
		switch (key) {
		case 'w':
			dynamic_cast<Player*>(mPlayer)->setMove('w', false);
			break;
		}
	}
	glutPostRedisplay();		// ???
}

void KeyboardFunc::setGame_stete(int n)
{
	game_state = n;
}