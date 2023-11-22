
#include "MainApp.h"
#include "main_define.h"

// �������� �̰� ����Ұ�
bool MainApp::Initialize()
{
	mPlayer = new Player(100, 200, 5, 10, 0);
	camera = new CameraObj;
	proj = new ProjObj;
	game_state = Ÿ��Ʋ;
	return true;
}


bool MainApp::test_Initialize()
{
	game_state = �ʵ�;
	mPlayer = new Player(100, 200, 5, 10, 0);
	camera = new CameraObj;
	proj = new ProjObj;
	pistol = new Pistol("test_obj\\obj_rifle.obj", 10, 10);
	pKeyboard = new KeyboardFunc(mPlayer, camera);
	pKeyboard->setGame_stete(game_state);

	field = new Field;
	pMouse = new MouseFunc(mPlayer);
	pMouse->setGame_stete(game_state);

	glutWarpPointer(1280 / 2, 720 / 2);
	return true;
}

// ���°� �ٲ�� �� ���� ���� ���ο� �ڿ��� �޾ƿͶ�
bool MainApp::Update_MainApp()
{
	switch (game_state) {
	case Ÿ��Ʋ:
		break;
	case ����:
		break;
	case �����ۼ���:
		break;
	case �ʵ�:
		//  ������Ʈ ������� �ִϸ��̼� �����ϱ�
		dynamic_cast<Player*>(mPlayer)->animation();
		camera->setCameraEYE(dynamic_cast<Player*>(mPlayer)->getLoc());		// ī�޶� ������Ʈ ���ֱ�
		camera->setCameraAngle(dynamic_cast<Player*>(mPlayer)->getRot());
		break;
	case ���â:
		break;
	}
	return true;
}

bool MainApp::Render()
{
	switch (game_state) {
	case Ÿ��Ʋ:
		break;
	case ����:
		
		break;
	case �ʵ�:
		pistol->Render();
		field->Render();
		break;
	}
	return true;
}
// �ڿ��� ��������� �ݳ��ض�
void MainApp::DestoryMainApp()
{
	if (nullptr != mPlayer) {
		delete mPlayer;
		mPlayer = nullptr;
	}
	if (nullptr != camera) {
		delete camera;
		camera = nullptr;
	}
	if (nullptr != proj) {
		delete proj;
		proj = nullptr;
	}
	if (nullptr != pistol) {
		delete pistol;
		pistol = nullptr;
	}
	if (nullptr != pKeyboard) {
		delete pKeyboard;
		pKeyboard = nullptr;
	}
	if (nullptr != field) {
		delete field;
		field = nullptr;
	}
	if (nullptr != pMouse) {
		delete pMouse;
		pMouse = nullptr;
	}
}