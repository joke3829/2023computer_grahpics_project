//==========================================================
// MainApp.h
// ��� ������ ���� �� �Ѱ��Ѵ�
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