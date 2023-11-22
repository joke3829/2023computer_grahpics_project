//==========================================================
// MainApp.h
// ��� ������ ���� �� �Ѱ��Ѵ�
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
	CharacterBase* mPlayer;
	CameraObj* camera;
	ProjObj* proj;
	Pistol* pistol;
	Rifle* rifle;
	Knife* knife;

	Field* field;
};