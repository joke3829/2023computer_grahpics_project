
#include "MainApp.h"
#include "main_define.h"

MainApp::~MainApp()
{
	DestroyMainApp();
}

// 최종본엔 이걸 사용할것
bool MainApp::Initialize()
{
	Mesh::box_check = false;
	mPlayer = new Player(100, 200, 5, 10, 0);
	camera = new CameraObj;
	proj = new ProjObj;
	game_state = 타이틀;

	max_alive = 12;			// 한 필드에 12마리
	aliving = 0;

	return true;
}


bool MainApp::test_Initialize()
{
	Mesh::box_check = false;
	game_state = 필드;
	mPlayer = new Player(100, 200, 40, 10, 0);
	camera = new CameraObj;
	proj = new ProjObj;
	/*pistol = new Pistol("test_obj\\obj_rifle.obj", 10, 10);
	rifle = new Rifle("test_obj\\obj_rifle.obj", 30, 30);
	knife = new Knife("test_obj\\obj_rifle.obj", 1, 1);*/
	pKeyboard = new KeyboardFunc(mPlayer, camera);
	pKeyboard->setGame_stete(game_state);

	field = new Field;
	pMouse = new MouseFunc(mPlayer);
	pMouse->setGame_stete(game_state);

	//glutWarpPointer(1280 / 2, 720 / 2);


	e_arrayReady();			// 좀비 준비
	max_alive = 6;			// 한 필드에 12마리
	aliving = 0;



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
		game_state = dynamic_cast<MouseFunc*>(pMouse)->getGame_state();
		pKeyboard->setGame_stete(game_state);
		pMouse->setGame_stete(game_state);
		break;
	case 필드:
		// 플레이어 아이템 적용
		dynamic_cast<Player*>(mPlayer)->apply_item();
		//  업데이트 헤더에서 애니메이션 적용하기
		dynamic_cast<Player*>(mPlayer)->animation();
		dynamic_cast<Player*>(mPlayer)->attack();
		camera->setCameraEYE(dynamic_cast<Player*>(mPlayer)->getLoc());		// 카메라 업데이트 해주기
		camera->setCameraAngle(dynamic_cast<Player*>(mPlayer)->getRot());
		// 총기 위치 변경
		dynamic_cast<Player*>(mPlayer)->take_out_Wep();
		dynamic_cast<Player*>(mPlayer)->getWeapon()->setLoc(dynamic_cast<Player*>(mPlayer)->getLoc());
		dynamic_cast<Player*>(mPlayer)->getWeapon()->setRot(dynamic_cast<Player*>(mPlayer)->getWepRot());

		aliving = 0;
		for (int i = 0; enemy_array.size(); ++i) {
			if (aliving < max_alive) {
				if (not enemy_array[i]->Death_check()) {
					enemy_array[i]->setPlayerLoc(dynamic_cast<Player*>(mPlayer)->getLoc());
					enemy_array[i]->walk_ani();
					++aliving;
				}
			}
			else
				break;
		}

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
		field->Render();
		dynamic_cast<Player*>(mPlayer)->getWeapon()->Render();		// 현재 들고 있는 무기를 렌더링 합니다.


		aliving = 0;
		for (int i = 0; enemy_array.size(); ++i) {
			if (aliving < max_alive) {
				if (not enemy_array[i]->Death_check()) {
					enemy_array[i]->Render();
					++aliving;
				}
			}
			else
				break;
		}

		break;
	}
	return true;
}

bool MainApp::e_arrayReady()
{
	if (0 != enemy_array.size()) {
		for (EnemyBase* e : enemy_array)
			delete e;
		enemy_array.clear();
	}

	for (int i = 0; i < 10; ++i) {
		enemy_array.push_back(new NM_zombie(100, 200, i, 10, 10));
	}

	return true;
}

// 자원을 사용했으면 반납해라
void MainApp::DestroyMainApp()
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
	// 좀비 반환
	if (0 != enemy_array.size()) {
		for (EnemyBase* e : enemy_array)
			delete e;
		enemy_array.clear();
	}
}