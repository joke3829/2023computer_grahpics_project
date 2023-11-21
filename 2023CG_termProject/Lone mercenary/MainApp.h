//==========================================================
// MainApp.h
// ��� ������ ���� �� �Ѱ��Ѵ�
//==========================================================

#include "stdafx.h"

class CharacterBase;
class CameraObj;
class ProjObj;
class Pistol;

class MainApp {
public:
	// �̿ϼ�, ���� ����
	bool Initialize();				
	bool test_Initialize();			// �׽�Ʈ�� �ʱ�ȭ
	bool Update_MainApp();
	void DestoryMainApp();
	bool Render();
protected:
private:
	int game_state;
	CharacterBase* mPlayer;
	CameraObj* camera;
	ProjObj* proj;
	Pistol* pistol;
};