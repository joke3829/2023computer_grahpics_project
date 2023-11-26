//==========================================================
// MainApp.h
// 모든 과정을 정리 및 총괄한다
//==========================================================

#include "stdafx.h"
#include "KeyboardFunc.h"
#include "MouseFunc.h"

class CharacterBase;
class CameraObj;
class ProjObj;
class Weapon;
class Field;
class KeyboardFunc;
class MouseFunc;
class EnemyBase;

class MainApp {
public:
	// 미완성, 수정 예정
	~MainApp();

	bool Initialize();				
	bool test_Initialize();			// 테스트용 초기화
	bool Update_MainApp();
	void DestroyMainApp();

	bool e_arrayReady();			// 좀비 배열 준비

	bool Render();
	KeyboardFunc* pKeyboard;
	MouseFunc* pMouse;
protected:
private:
	int game_state;
	CameraObj* camera;
	ProjObj* proj;


	CharacterBase* mPlayer;
	//Weapon* pistol;
	//Weapon* rifle;
	//Weapon* knife;



	std::vector<EnemyBase*> enemy_array;
	int max_alive;		// 한 필드에 최대 존재 좀비 수
	int aliving;		// 한 필드에 존재하는 좀비 수

	Field* field;
};