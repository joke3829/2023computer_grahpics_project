//==========================================================
// MainApp.h
// 모든 과정을 정리 및 총괄한다
//==========================================================

#include "stdafx.h"
#include "KeyboardFunc.h"
#include "MouseFunc.h"
#include "Sound.h"

class CharacterBase;
class CameraObj;
class ProjObj;
class Weapon;
class FieldMap;
class KeyboardFunc;
class MouseFunc;
class EnemyBase;
class Scene;

class MainApp {
public:
	// 미완성, 수정 예정
	~MainApp();

	bool Initialize();				
	bool Update_MainApp();
	void DestroyMainApp();

	bool e_arrayReady();			// 좀비 배열 준비
	bool Allkill_check();

	bool Render();
	void next_state();
	KeyboardFunc* pKeyboard;
	MouseFunc* pMouse;


	//bool test_init();
protected:
private:
	int game_state;
	CameraObj* camera;
	ProjObj* proj;
	CharacterBase* mPlayer;



	std::vector<EnemyBase*> enemy_array;
	GameTimer* game_timer;


	CubeMap* cubemap;
	FieldMap* field;
	Scene* current_scene;
	Scene* score_scene;

	MySound* mSound;

	// 아이템 선택 신에 들어갈 요소

};