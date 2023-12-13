

#include "MainApp.h"
#include "main_define.h"


MainApp::~MainApp()
{
	DestroyMainApp();
}

// 최종본엔 이걸 사용할것
bool MainApp::Initialize()
{
	// 기초 요소들 초기화
	mSound = MySound::GetInstance();
	Mesh::box_check = false;
	camera = new CameraObj;
	proj = new ProjObj;
	game_state = 메인;

	field = new FieldMap;
	cubemap = new CubeMap;

	current_scene = new Title(cubemap); // 메인 장면도 만들예정
	
	// 키보드 마우스 초기화
	pKeyboard = new KeyboardFunc;
	pKeyboard->setGame_stete(game_state);
	pKeyboard->setScene(current_scene);

	pMouse = new MouseFunc;
	pMouse->setGame_stete(game_state);
	pKeyboard->setScene(current_scene);

	// 게임 요소 초기화

	return true;
}

bool MainApp::test_init()
{
	// 기초 요소들 초기화
	Mesh::box_check = false;
	camera = new CameraObj;
	proj = new ProjObj;
	game_state = 메인;

	mPlayer = new Player(100, 200, 40, 20, 0);
	field = new FieldMap;
	cubemap = new CubeMap;



	// 키보드 마우스 초기화
	pKeyboard = new KeyboardFunc;

	pMouse = new MouseFunc;


	// 게임 요소 초기화

	game_state = 필드;
	//delete current_scene;
	e_arrayReady();
	game_timer = new GameTimer(mPlayer);
	current_scene = new Field(mPlayer, field, camera, enemy_array, game_timer, cubemap);
	pKeyboard->setGame_stete(game_state);
	pKeyboard->setScene(current_scene);

	pMouse->setGame_stete(game_state);
	pMouse->setScene(current_scene);
	return true;
}

void MainApp::next_state()
{
	switch (game_state) {
	case 타이틀:
		break;
	case 메인:
		if (pMouse->next_state()) {
			game_state = 아이템선택;
			delete current_scene;
			mPlayer = new Player(100, 200, 40, 10, 0);
			current_scene = new Select_Item(mPlayer, cubemap);
			pKeyboard->setGame_stete(game_state);
			pKeyboard->setScene(current_scene);

			pMouse->setGame_stete(game_state);
			pMouse->setScene(current_scene);
			MouseFunc::s_x = -1;
			MouseFunc::s_y = -1;
		}
		break;
	case 아이템선택:
		if (pMouse->next_state()) {
			game_state = 필드;
			delete current_scene;
			e_arrayReady();
			game_timer = new GameTimer(mPlayer);
			current_scene = new Field(mPlayer, field, camera, enemy_array, game_timer, cubemap);
			score_scene = new ScoreBoard(cubemap, enemy_array, game_timer, camera);
			pKeyboard->setGame_stete(game_state);
			pKeyboard->setScene(current_scene);

			pMouse->setGame_stete(game_state);
			pMouse->setScene(current_scene);
			MouseFunc::s_x = -1;
			MouseFunc::s_y = -1;
		}
		break;
	case 필드:
		if (mPlayer->Death_check() || Allkill_check() || game_timer->getremaining() == 0) {
			glutSetCursor(GLUT_CURSOR_RIGHT_ARROW);
			game_state = 결과창;
			dynamic_cast<ScoreBoard*>(score_scene)->Update_1();
			delete current_scene;
			current_scene = score_scene;

			pKeyboard->setGame_stete(game_state);
			pKeyboard->setScene(current_scene);

			pMouse->setGame_stete(game_state);
			pMouse->setScene(current_scene);
			MouseFunc::s_x = -1;
			MouseFunc::s_y = -1;
		}
		break;
	case 결과창:
		if (pMouse->next_state()) {
			game_state = 메인;
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
		}
		break;
	}
}


// 현재 장면 업데이트
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

	/*for (int i = 0; i < 3; ++i) {
		enemy_array.push_back(new NM_zombie(2300, 2300, 14, 100, 25, 힐러));
	}
	for (int i = 0; i < 4; ++i) {
		enemy_array.push_back(new NM_zombie(2100, 1900, 10, 150, 30, 폭발));
	}*/
	for (int i = 0; i < 19; ++i)
		enemy_array.push_back(new NM_zombie(1500, 1500, 20, 200, 35, 일반));
	enemy_array.push_back(new NM_zombie(2300, 2300, 14, 150, 25, 힐러));
	for (int i = 0; i < 5; ++i)
		enemy_array.push_back(new NM_zombie(1500, 1500, 20, 200, 35, 일반));
	enemy_array.push_back(new NM_zombie(2100, 2100, 10, 100, 30, 폭발));
	// 여기까지 26
	//================================
	for (int i = 0; i < 7; ++i)
		enemy_array.push_back(new NM_zombie(1500, 1500, 20, 200, 35, 일반));
	for(int i = 0 ; i < 2;++i)
		enemy_array.push_back(new NM_zombie(2100, 2100, 10, 100, 30, 폭발));
	enemy_array.push_back(new NM_zombie(2300, 2300, 14, 150, 25, 힐러));
	//여기까지 36
	//==================================
	for (int i = 0; i < 5; ++i)
		enemy_array.push_back(new NM_zombie(1500, 1500, 20, 200, 35, 일반));
	for (int i = 0; i < 2; ++i)
		enemy_array.push_back(new NM_zombie(2100, 2100, 10, 100, 30, 폭발));
	for (int i = 0; i < 3; ++i)
		enemy_array.push_back(new NM_zombie(1500, 1500, 20, 200, 35, 일반));
	enemy_array.push_back(new NM_zombie(2300, 2300, 14, 150, 25, 힐러));
	for(int i = 0 ; i < 2;++i)
		enemy_array.push_back(new NM_zombie(2100, 2100, 10, 100, 30, 폭발));
	for (int i = 0; i < 5; ++i)
		enemy_array.push_back(new NM_zombie(1500, 1500, 20, 200, 35, 일반));
	// 여기까지 54
	//====================================
	for (int i = 0; i < 5; ++i)
		enemy_array.push_back(new NM_zombie(1500, 1500, 20, 200, 35, 일반));
	enemy_array.push_back(new NM_zombie(2300, 2300, 14, 150, 25, 힐러));
	for (int i = 0; i < 10; ++i)
		enemy_array.push_back(new NM_zombie(1500, 1500, 20, 200, 35, 일반));
	for (int i = 0; i < 3; ++i)
		enemy_array.push_back(new NM_zombie(2100, 2100, 10, 100, 30, 폭발));
	enemy_array.push_back(new NM_zombie(2300, 2300, 14, 150, 25, 힐러));
	for (int i = 0; i < 7; ++i)
		enemy_array.push_back(new NM_zombie(1500, 1500, 20, 200, 35, 일반));
	// 여기까지 81
	//=======================================
	for (int i = 0; i < 4; ++i)
		enemy_array.push_back(new NM_zombie(1500, 1500, 20, 200, 35, 일반));
	for(int i = 0; i < 2; ++i)
		enemy_array.push_back(new NM_zombie(2300, 2300, 14, 150, 25, 힐러));
	for (int i = 0; i < 8; ++i)
		enemy_array.push_back(new NM_zombie(1500, 1500, 20, 200, 35, 일반));
	for (int i = 0; i < 2; ++i)
		enemy_array.push_back(new NM_zombie(2100, 2100, 10, 100, 30, 폭발));
	enemy_array.push_back(new NM_zombie(2300, 2300, 14, 150, 25, 힐러));
	for (int i = 0; i < 10; ++i)
		enemy_array.push_back(new NM_zombie(1500, 1500, 20, 200, 35, 일반));
	// 여기까지 108
	//=========================================
	for (int i = 0; i < 19; ++i)
		enemy_array.push_back(new NM_zombie(1500, 1500, 20, 200, 35, 일반));
	for (int i = 0; i < 2; ++i)
		enemy_array.push_back(new NM_zombie(2300, 2300, 14, 150, 25, 힐러));
	for (int i = 0; i < 7; ++i)
		enemy_array.push_back(new NM_zombie(2100, 2100, 10, 100, 30, 폭발));
	for (int i = 0; i < 4; ++i)
		enemy_array.push_back(new NM_zombie(2300, 2300, 14, 150, 25, 힐러));

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

bool MainApp::Allkill_check()
{
	for (int i = 0; i < enemy_array.size(); ++i) {
		if (not enemy_array[i]->Death_check())
			return false;
	}
	return true;
}