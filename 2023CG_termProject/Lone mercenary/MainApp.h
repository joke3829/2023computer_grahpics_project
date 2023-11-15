//==========================================================
// MainApp.h
// 모든 과정을 정리 및 총괄한다
//==========================================================

#include "stdafx.h"

class CharacterBase;
class MainApp {
public:
	MainApp();
	~MainApp();
	bool Initialize();
	bool Update_MainApp();
	bool DestoryMainApp();
protected:
private:
	int game_state;
	CharacterBase* mPlayer;
};