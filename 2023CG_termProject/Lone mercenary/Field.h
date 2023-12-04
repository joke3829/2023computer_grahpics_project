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

	int max_alive{};		// �� �ʵ忡 �ִ� ���� ���� ��
	int aliving{};		// �� �ʵ忡 �����ϴ� ���� ��
};