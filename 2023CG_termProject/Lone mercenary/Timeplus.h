#pragma once
#include "Player.h"
#include "GameTimer.h"

class Timerplus {
public:
	Timerplus(CharacterBase*, GameTimer*, glm::vec3);
	~Timerplus();
	void check_collision();
	void setLoc();

	void rot_ani();

	void Render();
private:
	GameTimer* timer;
	CharacterBase* mPlayer;
	Mesh* obj;

	bool  exist;
	glm::vec3 cur_loc;
	glm::vec2 cur_rot;

};