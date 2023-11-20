//==========================================================
// MainApp.h
// ��� ������ ���� �� �Ѱ��Ѵ�
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