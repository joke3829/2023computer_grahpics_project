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
<<<<<<< Updated upstream
=======
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
<<<<<<< Updated upstream
=======
	KeyboardFunc* pKeyboard;
	MouseFunc* pMouse;
>>>>>>> Stashed changes
protected:
private:
	int game_state;
	CharacterBase* mPlayer;
	CameraObj* camera;
	ProjObj* proj;
	Pistol* pistol;
};