//==========================================================
// MainApp.h
// ��� ������ ���� �� �Ѱ��Ѵ�
//==========================================================

#include "stdafx.h"
#include "KeyboardFunc.h"
#include "MouseFunc.h"

class CharacterBase;
class CameraObj;
class ProjObj;
class Pistol;
class Field;
class KeyboardFunc;
class MouseFunc;

class MainApp {
public:
	// �̿ϼ�, ���� ����
	bool Initialize();				
	bool test_Initialize();			// �׽�Ʈ�� �ʱ�ȭ
	bool Update_MainApp();
	void DestoryMainApp();
	bool Render();
	KeyboardFunc* pKeyboard;
	MouseFunc* pMouse;
protected:
private:
	int game_state;
	CameraObj* camera;
	ProjObj* proj;


	CharacterBase* mPlayer;
	Pistol* pistol;

	Field* field;
};