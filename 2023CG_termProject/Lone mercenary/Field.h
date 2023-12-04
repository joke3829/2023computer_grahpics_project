#pragma once
#include "Scene.h"
#include "CharacterBase.h"
#include "FieldMap.h"
#include "Enemy.h"
#include "CameraObj.h"


class Field : public Scene {
public:
	Field(CharacterBase*, FieldMap*, CameraObj*, std::vector<EnemyBase*>&);
	~Field();

	CharacterBase* getPlayer();
	CameraObj* getCamera();

	void Update();
	void Render();
private:
	CharacterBase* mPlayer{ nullptr };
	FieldMap* mField;
	std::vector<EnemyBase*> enemy_list;
	CameraObj* mCamera{ nullptr };

	int max_alive{};		// 한 필드에 최대 존재 좀비 수
	int aliving{};		// 한 필드에 존재하는 좀비 수
};