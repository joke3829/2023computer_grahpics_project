#pragma once
#include "Scene.h"
#include "CharacterBase.h"
#include "FieldMap.h"
#include "Enemy.h"
#include "CameraObj.h"
#include "GameTimer.h"
#include "CubeMap.h"
#include "UI.h"
#include "ItemBox.h"
#include "Timeplus.h"


class Field : public Scene {
public:
	Field(CharacterBase*, FieldMap*, CameraObj*, std::vector<EnemyBase*>&, GameTimer*, CubeMap*);
	~Field();

	CharacterBase* getPlayer();
	CameraObj* getCamera();
	std::vector<EnemyBase*>& getList();

	static int first_zom;

	bool check_zomcol(EnemyBase* [], int);

	void Update();
	void Render();
private:
	CharacterBase* mPlayer{ nullptr };
	FieldMap* mField;
	CubeMap* mCubemap;
	std::vector<EnemyBase*> enemy_list;
	CameraObj* mCamera{ nullptr };
	GameTimer* mTimer{ nullptr };
	UI* mUi;
	ItemBox* item;
	Timerplus* sandglass[3];

	int max_alive{};		// 한 필드에 최대 존재 좀비 수
	int aliving{};		// 한 필드에 존재하는 좀비 수
};