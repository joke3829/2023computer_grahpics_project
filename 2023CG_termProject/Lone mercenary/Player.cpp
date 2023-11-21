#include "Player.h"

// =========================P_Mesh==========================

//P_Mesh::P_Mesh(std::string filename) : Mesh(filename) {};
//
//P_Mesh::~P_Mesh() {};

//==========================================================

//==========================Player===========================

Player::Player(float hp, float max, float spd, float def, float atk)
	: CharacterBase(hp, max, spd, def, atk)
{
	cur_loc = glm::vec3(0.0f);				// 초기 위치 지정, 이거 바꿔주면 자연스래 카메라도 위치 바뀜
	cur_rot = glm::vec2(0.0f);
	move[0] = move[1] = move[2] = move[3] = false;
}

void Player::animation()
{
	// ex)
	if (move[0]) {
		// 현재 cur_loc에 바라보는 방향으로 spd/60만큼 더한다.(60프레임이니까 4cm/s일시 4/60하자)
		
	}
	else if (move[1]) {
		// 현재 cur_loc에 바라보는 방향의 왼쪽으로 이하 동문
	}
	//대각선도 해줄 수 있으면 하자
	else if (move[0] && move[1]) {
		
	}
}

glm::vec3 Player::getLoc()
{
	return cur_loc;
}

glm::vec2 Player::getRot()
{
	return cur_rot;
}

void Player::setMove(char way, bool flag)
{
	switch (way) {
	case 'w':
		move[0] = flag;
		break;
	case 'a':
		move[1] = flag;
		break;
	case 's':
		move[2] = flag;
		break;
	case 'd':
		move[3] = flag;
		break;
	}
}

//===========================================================