//==========================================================
// MainApp.h
// 모든 과정을 정리 및 총괄한다
//==========================================================

#include "stdafx.h"
#include "CameraObj.h"
#include "ProjObj.h"

class CharacterBase;
class RenderManager;
class MainApp {
public:
	MainApp();
	bool Initialize();
	bool Update_MainApp();
	void DestoryMainApp();
	bool Render();
protected:
private:
	int game_state;
	CharacterBase* mPlayer;
	RenderManager* renderer;
};