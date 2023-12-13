//===================================================
// GameTimer.h
// �ΰ��ӿ� �� Ÿ�̸�
//===================================================

#pragma once
#include <ctime>
#include "Mesh.h"
#include "stdafx.h"
#include "Player.h"

class GameTimer {
public:
	GameTimer(CharacterBase*);
	~GameTimer();

	void plus_time(int);
	bool check_end();

	void Update();
	void Render();

	int getremaining();

	static int p_num100;
	static int p_num10;
	static int p_num1;
	static int remaining_time;		// �����ð�
private:
	clock_t start_time;
	clock_t cur_time;
	int d_time;
	CharacterBase* mPlayer;
	Mesh* back;
	Mesh* num100;
	Mesh* num10;
	Mesh* num1;
};