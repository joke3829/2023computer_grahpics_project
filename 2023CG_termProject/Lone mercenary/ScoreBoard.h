#pragma once
#include "stdafx.h"
#include "Enemy.h"
#include "GameTimer.h"
#include "CubeMap.h"

class ScoreBoard : public Scene {
public:
	ScoreBoard(CubeMap*, std::vector<EnemyBase*>&, GameTimer*, CameraObj*);
	~ScoreBoard();

	void Update_1();
	void Render();

private:
	CubeMap* mCubemap;
	std::vector<EnemyBase*>& list;
	GameTimer* mTimer;
	CameraObj* camera;

	int killcnt{};
	int totalscore{};

	Mesh* back;
	
	Mesh* num_5;
	Mesh* num_4;
	Mesh* num_3;
	Mesh* num_2;
	Mesh* num_1;

	Mesh* gomain;
	Mesh* exitProgram;

	Mesh* ruf;
	Mesh* rhk;
};