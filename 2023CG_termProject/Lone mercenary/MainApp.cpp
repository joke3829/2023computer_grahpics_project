

#include "MainApp.h"
#include "main_define.h"


MainApp::~MainApp()
{
	DestroyMainApp();
}

// �������� �̰� ����Ұ�
bool MainApp::Initialize()
{
	// ���� ��ҵ� �ʱ�ȭ
	Mesh::box_check = false;
	camera = new CameraObj;
	proj = new ProjObj;
	game_state = ����;

	current_scene = new Scene; // ���� ��鵵 ���鿹��
	
	// Ű���� ���콺 �ʱ�ȭ
	pKeyboard = new KeyboardFunc;
	pKeyboard->setGame_stete(game_state);
	pKeyboard->setScene(current_scene);

	pMouse = new MouseFunc;
	pMouse->setGame_stete(game_state);
	pKeyboard->setScene(current_scene);

	// ���� ��� �ʱ�ȭ
	field = new FieldMap;
	cubemap = new CubeMap;

	return true;
}

void MainApp::next_state()
{
	switch (game_state) {
	case Ÿ��Ʋ:
		break;
	case ����:
		if (pMouse->next_state()) {
			game_state = �����ۼ���;
			delete current_scene;
			mPlayer = new Player(100, 200, 40, 10, 0);
			current_scene = new Select_Item(mPlayer, cubemap);
			pKeyboard->setGame_stete(game_state);
			pKeyboard->setScene(current_scene);

			pMouse->setGame_stete(game_state);
			pMouse->setScene(current_scene);
		}
		break;
	case �����ۼ���:
		if (pMouse->next_state()) {
			game_state = �ʵ�;
			delete current_scene;
			e_arrayReady();
			game_timer = new GameTimer;
			current_scene = new Field(mPlayer, field, camera, enemy_array, game_timer, cubemap);
			pKeyboard->setGame_stete(game_state);
			pKeyboard->setScene(current_scene);

			pMouse->setGame_stete(game_state);
			pMouse->setScene(current_scene);
		}
		break;
	case �ʵ�:
		break;
	case ���â:
		break;
	}
}


// ���� ��� ������Ʈ
bool MainApp::Update_MainApp()
{
	current_scene->Update();
	return true;
}

bool MainApp::Render()
{
	current_scene->Render();
	return true;
}

bool MainApp::e_arrayReady()
{
	if (0 != enemy_array.size()) {
		for (EnemyBase* e : enemy_array)
			delete e;
		enemy_array.clear();
	}

	for (int i = 0; i < 4; ++i) {
		enemy_array.push_back(new NM_zombie(100, 200, 20, 10, 10, ����));
	}
	enemy_array.push_back(new NM_zombie(100, 200, 10, 20, 50, ����));
	enemy_array.push_back(new NM_zombie(100, 200, 10, 30, 50, �Ϲ�));
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