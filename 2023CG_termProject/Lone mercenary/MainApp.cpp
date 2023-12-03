
#include "MainApp.h"
#include "main_define.h"

MainApp::~MainApp()
{
	DestroyMainApp();
}

// �������� �̰� ����Ұ�
bool MainApp::Initialize()
{
	Mesh::box_check = false;
	mPlayer = new Player(100, 200, 5, 10, 0);
	camera = new CameraObj;
	proj = new ProjObj;
	game_state = Ÿ��Ʋ;

	max_alive = 12;			// �� �ʵ忡 12����
	aliving = 0;

	return true;
}


bool MainApp::test_Initialize()
{
	Mesh::box_check = false;
	game_state = �ʵ�;
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


	e_arrayReady();			// ���� �غ�
	max_alive = 6;			// �� �ʵ忡 12����
	aliving = 0;



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
		game_state = dynamic_cast<MouseFunc*>(pMouse)->getGame_state();
		pKeyboard->setGame_stete(game_state);
		pMouse->setGame_stete(game_state);
		break;
	case �ʵ�:
		// �÷��̾� ������ ����
		dynamic_cast<Player*>(mPlayer)->apply_item();
		//  ������Ʈ ������� �ִϸ��̼� �����ϱ�
		dynamic_cast<Player*>(mPlayer)->animation();
		dynamic_cast<Player*>(mPlayer)->attack();
		camera->setCameraEYE(dynamic_cast<Player*>(mPlayer)->getLoc());		// ī�޶� ������Ʈ ���ֱ�
		camera->setCameraAngle(dynamic_cast<Player*>(mPlayer)->getRot());
		// �ѱ� ��ġ ����
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
		field->Render();
		dynamic_cast<Player*>(mPlayer)->getWeapon()->Render();		// ���� ��� �ִ� ���⸦ ������ �մϴ�.


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

// �ڿ��� ��������� �ݳ��ض�
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
	// ���� ��ȯ
	if (0 != enemy_array.size()) {
		for (EnemyBase* e : enemy_array)
			delete e;
		enemy_array.clear();
	}
}