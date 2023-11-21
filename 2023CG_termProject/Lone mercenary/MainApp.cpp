
#include "MainApp.h"
#include "CameraObj.h"
#include "ProjObj.h"
#include "Player.h"
#include "Pistol.h"

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
	pistol = new Pistol("test_obj\\cube.obj", 10, 10);
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
}