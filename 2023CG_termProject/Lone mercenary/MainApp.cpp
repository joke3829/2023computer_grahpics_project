

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
	Mesh::box_check = false;
	camera = new CameraObj;
	proj = new ProjObj;
	game_state = 메인;

	current_scene = new Scene; // 메인 장면도 만들예정
	
	// 키보드 마우스 초기화
	pKeyboard = new KeyboardFunc;
	pKeyboard->setGame_stete(game_state);
	pKeyboard->setScene(current_scene);

	pMouse = new MouseFunc;
	pMouse->setGame_stete(game_state);
	pKeyboard->setScene(current_scene);

	// 게임 요소 초기화
	field = new FieldMap;
	cubemap = new CubeMap;

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
		}
		break;
	case 아이템선택:
		if (pMouse->next_state()) {
			game_state = 필드;
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
	case 필드:
		break;
	case 결과창:
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

	for (int i = 0; i < 4; ++i) {
		enemy_array.push_back(new NM_zombie(100, 200, 20, 10, 10, 힐러));
	}
	enemy_array.push_back(new NM_zombie(100, 200, 10, 20, 50, 폭발));
	enemy_array.push_back(new NM_zombie(100, 200, 10, 30, 50, 일반));
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