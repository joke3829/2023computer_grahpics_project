//===================================================
// GameTimer.h
// �ΰ��ӿ� �� Ÿ�̸�
//===================================================

#pragma once
#include <ctime>
#include "stdafx.h"

class GameTimer {
public:
	GameTimer();

	void plus_time(double);
	bool check_end();

	void Update();
	void Render();
private:
	clock_t start_time;
	clock_t cur_time;
	double d_time;
	double remaining_time;		// �����ð�
};