//=================================================
// ItemBox.h
// �ʵ忡 ����� ������ �ڽ��� �����.
//=================================================
#pragma once
#include <ctime>
#include "stdafx.h"
#include "Mesh.h"
#include "GameTimer.h"
class ItemBox {
public:
	ItemBox(GameTimer*, CharacterBase*);
	~ItemBox();

	void check_collision();
	void check_time();
	void setLoc();

	void rot_ani();

	void Render();
private:
	GameTimer* timer;
	CharacterBase* mPlayer;
	Mesh* box;

	bool  exist;
	glm::vec3 cur_loc;
	glm::vec2 cur_rot;

	int remaining;
	clock_t i_time;
	clock_t l_time;
};
