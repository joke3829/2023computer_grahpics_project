#pragma once
#include "Scene.h"
#include "CharacterBase.h"
#include "FieldMap.h"
#include "Enemy.h"
#include "CameraObj.h"
#include "GameTimer.h"
#include "CubeMap.h"


class Field : public Scene {
public:
	Field(CharacterBase*, FieldMap*, CameraObj*, std::vector<EnemyBase*>&, GameTimer*, CubeMap*);
	~Field();

	CharacterBase* getPlayer();
	CameraObj* getCamera();

	void Update();
	void Render();
private:
	CharacterBase* mPlayer{ nullptr };
	FieldMap* mField;
	CubeMap* mCubemap;
	std::vector<EnemyBase*> enemy_list;
	CameraObj* mCamera{ nullptr };
	GameTimer* mTimer{ nullptr };

	int max_alive{};		// �� �ʵ忡 �ִ� ���� ���� ��
	int aliving{};		// �� �ʵ忡 �����ϴ� ���� ��
};