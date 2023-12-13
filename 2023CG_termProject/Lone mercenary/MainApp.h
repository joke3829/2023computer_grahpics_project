//==========================================================
// MainApp.h
// ��� ������ ���� �� �Ѱ��Ѵ�
//==========================================================

#include "stdafx.h"
#include "KeyboardFunc.h"
#include "MouseFunc.h"
#include "Sound.h"

class CharacterBase;
class CameraObj;
class ProjObj;
class Weapon;
class FieldMap;
class KeyboardFunc;
class MouseFunc;
class EnemyBase;
class Scene;
class Sound;

class MainApp {
public:
	// �̿ϼ�, ���� ����
	~MainApp();

	bool Initialize();				
	bool Update_MainApp();
	void DestroyMainApp();

	bool e_arrayReady();			// ���� �迭 �غ�
	bool Allkill_check();

	bool Render();
	void next_state();
	KeyboardFunc* pKeyboard;
	MouseFunc* pMouse;


	bool test_init();
protected:
private:
	int game_state;
	CameraObj* camera;
	ProjObj* proj;
	CharacterBase* mPlayer;

	Sound* sd;

	std::vector<EnemyBase*> enemy_array;
	GameTimer* game_timer;


	CubeMap* cubemap;
	FieldMap* field;
	Scene* current_scene;
	Scene* score_scene;

	// ������ ���� �ſ� �� ���

};