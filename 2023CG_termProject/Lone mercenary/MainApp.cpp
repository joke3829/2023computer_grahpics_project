
#include "MainApp.h"
#include "main_define.h"

// 최종본엔 이걸 사용할것
bool MainApp::Initialize()
{
	mPlayer = new Player(100, 200, 5, 10, 0);
	camera = new CameraObj;
	proj = new ProjObj;
	game_state = 타이틀;
	return true;
}


bool MainApp::test_Initialize()
{
	game_state = 필드;
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

// 상태가 바뀌면 그 때에 따라 새로운 자원을 받아와라
bool MainApp::Update_MainApp()
{
	switch (game_state) {
	case 타이틀:
		break;
	case 메인:
		break;
	case 아이템선택:
		break;
	case 필드:
		//  업데이트 헤더에서 애니메이션 적용하기
		dynamic_cast<Player*>(mPlayer)->animation();
		camera->setCameraEYE(dynamic_cast<Player*>(mPlayer)->getLoc());		// 카메라 업데이트 해주기
		camera->setCameraAngle(dynamic_cast<Player*>(mPlayer)->getRot());
		break;
	case 결과창:
		break;
	}
	return true;
}

bool MainApp::Render()
{
	switch (game_state) {
	case 타이틀:
		break;
	case 메인:
		
		break;
	case 필드:
		pistol->Render();
		field->Render();
		break;
	}
	return true;
}
// 자원을 사용했으면 반납해라
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