#include "GameTimer.h"

GameTimer::GameTimer()
{
	start_time = clock();
	remaining_time = 180;	//180초
}

void GameTimer::plus_time(double extra_time) // 머리를 맞추거나 특수좀비 킬시 불러주자
{
	remaining_time += extra_time;
}

bool GameTimer::check_end()
{
	if (d_time > remaining_time) {
		std::cout << "시간 끝!" << '\n';
		return true;
	}

	return false;
}

void GameTimer::Update()
{
	cur_time = clock();
	d_time = static_cast<double>(cur_time - start_time) / CLOCKS_PER_SEC;
}

void GameTimer::Render()
{
	std::cout << "남은 시간" << static_cast<int>(remaining_time - d_time) << '\n';
}