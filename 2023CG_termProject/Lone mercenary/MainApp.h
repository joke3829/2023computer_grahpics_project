//==========================================================
// MainApp.h
// 모든 과정을 정리 및 총괄한다
//==========================================================

#include "stdafx.h"
<<<<<<< Updated upstream
=======
#include "KeyboardFunc.h"
#include "MouseFunc.h"
>>>>>>> Stashed changes

class CharacterBase;
class CameraObj;
class ProjObj;
class Pistol;
class Rifle;
class Knife;
class Field;
class KeyboardFunc;
class MouseFunc;
>>>>>>> Stashed changes

class MainApp {
public:
	// 미완성, 수정 예정
	bool Initialize();				
	bool test_Initialize();			// 테스트용 초기화
	bool Update_MainApp();
	void DestoryMainApp();
	bool Render();
	KeyboardFunc* pKeyboard;
	MouseFunc* pMouse;
protected:
private:
	int game_state;
	CharacterBase* mPlayer;
	CameraObj* camera;
	ProjObj* proj;
	Pistol* pistol;
	Rifle* rifle;
	Knife* knife;

	Field* field;
};