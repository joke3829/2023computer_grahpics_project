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
class Weapon;
class Field;
class KeyboardFunc;
class MouseFunc;
class EnemyBase;

class MainApp {
public:
	// �̿ϼ�, ���� ����
	~MainApp();

	bool Initialize();				
	bool test_Initialize();			// �׽�Ʈ�� �ʱ�ȭ
	bool Update_MainApp();
	void DestroyMainApp();

	bool e_arrayReady();			// ���� �迭 �غ�

	bool Render();
	KeyboardFunc* pKeyboard;
	MouseFunc* pMouse;
protected:
private:
	int game_state;
	CameraObj* camera;
	ProjObj* proj;


	CharacterBase* mPlayer;
	//Weapon* pistol;
	//Weapon* rifle;
	//Weapon* knife;



	std::vector<EnemyBase*> enemy_array;
	int max_alive;		// �� �ʵ忡 �ִ� ���� ���� ��
	int aliving;		// �� �ʵ忡 �����ϴ� ���� ��

	Field* field;
};