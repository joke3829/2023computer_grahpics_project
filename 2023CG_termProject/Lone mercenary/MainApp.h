//==========================================================
// MainApp.h
// 모든 과정을 정리 및 총괄한다
//==========================================================

#include "stdafx.h"

class CharacterBase;
class CameraObj;
class ProjObj;

class MainApp {
public:
	bool Initialize();
	bool Update_MainApp();
	void DestoryMainApp();
	bool Render();
protected:
private:
	int game_state;
	CharacterBase* mPlayer;
	CameraObj* camera;
	ProjObj* proj;
};