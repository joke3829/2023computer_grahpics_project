

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
	mSound = MySound::GetInstance();
	mSound->play_mainbgm();
	Mesh::box_check = false;
	camera = new CameraObj;
	proj = new ProjObj;
	game_state = ����;

	field = new FieldMap;
	cubemap = new CubeMap;

	current_scene = new Title(cubemap); // ���� ��鵵 ���鿹��
	
	// Ű���� ���콺 �ʱ�ȭ
	pKeyboard = new KeyboardFunc;
	pKeyboard->setGame_stete(game_state);
	pKeyboard->setScene(current_scene);

	pMouse = new MouseFunc;
	pMouse->setGame_stete(game_state);
	pKeyboard->setScene(current_scene);

	// ���� ��� �ʱ�ȭ

	return true;
}

//bool MainApp::test_init()
//{
//	// ���� ��ҵ� �ʱ�ȭ
//	Mesh::box_check = false;
//	camera = new CameraObj;
//	proj = new ProjObj;
//	game_state = ����;
//
//	mPlayer = new Player(100, 200, 40, 20, 0);
//	field = new FieldMap;
//	cubemap = new CubeMap;
//
//
//
//	// Ű���� ���콺 �ʱ�ȭ
//	pKeyboard = new KeyboardFunc;
//
//	pMouse = new MouseFunc;
//
//
//	// ���� ��� �ʱ�ȭ
//
//	game_state = �ʵ�;
//	//delete current_scene;
//	e_arrayReady();
//	game_timer = new GameTimer(mPlayer);
//	current_scene = new Field(mPlayer, field, camera, enemy_array, game_timer, cubemap);
//	pKeyboard->setGame_stete(game_state);
//	pKeyboard->setScene(current_scene);
//
//	pMouse->setGame_stete(game_state);
//	pMouse->setScene(current_scene);
//	return true;
//}

void MainApp::next_state()
{
	switch (game_state) {
	case Ÿ��Ʋ:
		break;
	case ����:
		if (pMouse->next_state()) {
			game_state = �����ۼ���;
			delete current_scene;
			mPlayer = new Player(100, 200, 40, 20, 0);
			current_scene = new Select_Item(mPlayer, cubemap);
			pKeyboard->setGame_stete(game_state);
			pKeyboard->setScene(current_scene);

			pMouse->setGame_stete(game_state);
			pMouse->setScene(current_scene);
			MouseFunc::s_x = -1;
			MouseFunc::s_y = -1;
		}
		break;
	case �����ۼ���:
		if (pMouse->next_state()) {
			game_state = �ʵ�;
			delete current_scene;
			e_arrayReady();
			game_timer = new GameTimer(mPlayer);
			current_scene = new Field(mPlayer, field, camera, enemy_array, game_timer, cubemap);
			score_scene = new ScoreBoard(cubemap, enemy_array, game_timer, camera);
			pKeyboard->setGame_stete(game_state);
			pKeyboard->setScene(current_scene);

			pMouse->setGame_stete(game_state);
			pMouse->setScene(current_scene);
			mSound->play_fieldbgm();
			MouseFunc::s_x = -1;
			MouseFunc::s_y = -1;
		}
		break;
	case �ʵ�:
		if (mPlayer->Death_check() || Allkill_check() || game_timer->getremaining() == 0) {
			glutSetCursor(GLUT_CURSOR_RIGHT_ARROW);
			game_state = ���â;
			dynamic_cast<ScoreBoard*>(score_scene)->Update_1();
			delete current_scene;
			current_scene = score_scene;

			pKeyboard->setGame_stete(game_state);
			pKeyboard->setScene(current_scene);

			pMouse->setGame_stete(game_state);
			pMouse->setScene(current_scene);
			MouseFunc::s_x = -1;
			MouseFunc::s_y = -1;
			mSound->play_resultbgm();
		}
		break;
	case ���â:
		if (pMouse->next_state()) {
			game_state = ����;
			delete mPlayer;
			delete game_timer;
			delete current_scene;
			current_scene = new Title(cubemap);

			pKeyboard->setGame_stete(game_state);
			pKeyboard->setScene(current_scene);

			pMouse->setGame_stete(game_state);
			pMouse->setScene(current_scene);
			MouseFunc::s_x = -1;
			MouseFunc::s_y = -1;
			mSound->play_mainbgm();
		}
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

	for (int i = 0; i < 19; ++i)
		enemy_array.push_back(new NM_zombie(1200, 1350, 20, 30, 27, �Ϲ�));
	enemy_array.push_back(new NM_zombie(1500, 1650, 14, 20, 25, ����));
	for (int i = 0; i < 5; ++i)
		enemy_array.push_back(new NM_zombie(1200, 1350, 20, 30, 27, �Ϲ�));
	enemy_array.push_back(new NM_zombie(2200, 2350, 10, 50, 33, ����));
	// ������� 26
	//================================
	for (int i = 0; i < 7; ++i)
		enemy_array.push_back(new NM_zombie(1200, 1350, 20, 30, 27, �Ϲ�));
	for(int i = 0 ; i < 2;++i)
		enemy_array.push_back(new NM_zombie(2200, 2350, 10, 50, 33, ����));
	enemy_array.push_back(new NM_zombie(1500, 1650, 14, 20, 25, ����));
	//������� 36
	//==================================
	for (int i = 0; i < 5; ++i)
		enemy_array.push_back(new NM_zombie(1200, 1350, 20, 30, 27, �Ϲ�));
	for (int i = 0; i < 2; ++i)
		enemy_array.push_back(new NM_zombie(2200, 2350, 10, 50, 33, ����));
	for (int i = 0; i < 3; ++i)
		enemy_array.push_back(new NM_zombie(1200, 1350, 20, 30, 27, �Ϲ�));
	enemy_array.push_back(new NM_zombie(1500, 1650, 14, 20, 25, ����));
	for(int i = 0 ; i < 2;++i)
		enemy_array.push_back(new NM_zombie(2200, 2350, 10, 50, 33, ����));
	for (int i = 0; i < 5; ++i)
		enemy_array.push_back(new NM_zombie(1200, 1350, 20, 30, 27, �Ϲ�));
	// ������� 54
	//====================================
	for (int i = 0; i < 5; ++i)
		enemy_array.push_back(new NM_zombie(1200, 1350, 20, 30, 27, �Ϲ�));
	enemy_array.push_back(new NM_zombie(1500, 1650, 14, 20, 25, ����));
	for (int i = 0; i < 10; ++i)
		enemy_array.push_back(new NM_zombie(1200, 1350, 20, 30, 27, �Ϲ�));
	for (int i = 0; i < 3; ++i)
		enemy_array.push_back(new NM_zombie(2200, 2350, 10, 50, 33, ����));
	enemy_array.push_back(new NM_zombie(1500, 1650, 14, 20, 25, ����));
	for (int i = 0; i < 7; ++i)
		enemy_array.push_back(new NM_zombie(1200, 1350, 20, 30, 27, �Ϲ�));
	// ������� 81
	//=======================================
	for (int i = 0; i < 4; ++i)
		enemy_array.push_back(new NM_zombie(1200, 1350, 20, 30, 27, �Ϲ�));
	for(int i = 0; i < 2; ++i)
		enemy_array.push_back(new NM_zombie(1500, 1650, 14, 20, 25, ����));
	for (int i = 0; i < 8; ++i)
		enemy_array.push_back(new NM_zombie(1200, 1350, 20, 30, 27, �Ϲ�));
	for (int i = 0; i < 2; ++i)
		enemy_array.push_back(new NM_zombie(2200, 2350, 10, 50, 33, ����));
	enemy_array.push_back(new NM_zombie(1500, 1650, 14, 20, 25, ����));
	for (int i = 0; i < 10; ++i)
		enemy_array.push_back(new NM_zombie(1200, 1350, 20, 30, 27, �Ϲ�));
	// ������� 108
	//=========================================
	for (int i = 0; i < 19; ++i)
		enemy_array.push_back(new NM_zombie(1200, 1350, 20, 30, 27, �Ϲ�));
	for (int i = 0; i < 2; ++i)
		enemy_array.push_back(new NM_zombie(1500, 1650, 14, 20, 25, ����));
	for (int i = 0; i < 7; ++i)
		enemy_array.push_back(new NM_zombie(2200, 2350, 10, 50, 33, ����));
	for (int i = 0; i < 4; ++i)
		enemy_array.push_back(new NM_zombie(1500, 1650, 14, 20, 25, ����));

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

bool MainApp::Allkill_check()
{
	for (int i = 0; i < enemy_array.size(); ++i) {
		if (not enemy_array[i]->Death_check())
			return false;
	}
	return true;
}