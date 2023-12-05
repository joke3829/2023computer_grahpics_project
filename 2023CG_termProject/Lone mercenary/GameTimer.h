//===================================================
// GameTimer.h
// 인게임에 들어갈 타이머
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
	double remaining_time;		// 남은시간
};