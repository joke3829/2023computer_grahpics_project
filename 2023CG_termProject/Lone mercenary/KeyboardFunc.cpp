
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
		}
	}
	glutPostRedisplay();		// ???
}

void KeyboardFunc::setGame_stete(int n)
{
	game_state = n;
}