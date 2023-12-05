#include "GameTimer.h"

GameTimer::GameTimer()
{
	start_time = clock();
	remaining_time = 180;	//180��
}

void GameTimer::plus_time(double extra_time) // �Ӹ��� ���߰ų� Ư������ ų�� �ҷ�����
{
	remaining_time += extra_time;
}

bool GameTimer::check_end()
{
	if (d_time > remaining_time) {
		std::cout << "�ð� ��!" << '\n';
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
	std::cout << "���� �ð�" << static_cast<int>(remaining_time - d_time) << '\n';
}