#pragma once
#include "Player.h"
#include "GameTimer.h"

class UI {
public:
	UI(CharacterBase*, GameTimer*);
	
	void Render();
	void Update();

	static int h100;
	static int h10;
	static int h1;

private:
	CharacterBase* mPlayer;
	GameTimer* timer;

	Mesh* hp_back;
	Mesh* hp_100;
	Mesh* hp_10;
	Mesh* hp_1;

	Mesh* bullet_back;
	Mesh* cur_b_10;
	Mesh* cur_b_1;
	Mesh* cur_b_sl;
	Mesh* r_b_100;
	Mesh* r_b_10;
	Mesh* r_b_1;
};