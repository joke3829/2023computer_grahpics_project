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
	cur_loc = glm::vec3(-20, 0, 10);				// �ʱ� ��ġ ����, �̰� �ٲ��ָ� �ڿ����� ī�޶� ��ġ �ٲ�
	cur_rot = glm::vec2(0.0f,0.0f);
	move[0] = move[1] = move[2] = move[3] = false;
}

void Player::animation()
{
	//�밢�� ���� Ű���� ó���ϰ� �̱�Ű ó��
	if (move[0] && move[1]) { //���� + ��
		glm::vec3 dir = glm::vec3(glm::cos(glm::radians(cur_rot.x - 45.0f)), 0, glm::sin(glm::radians(cur_rot.x - 45.0f)));
		cur_loc += (speed * dir) / 60.0f;
	}
	else if (move[0] && move[3]) { //������ + ��
		glm::vec3 dir = glm::vec3(glm::cos(glm::radians(cur_rot.x + 45.0f)), 0, glm::sin(glm::radians(cur_rot.x + 45.0f)));
		cur_loc += (speed * dir) / 60.0f;
	}
	else if (move[2] && move[1]) { //���� + ��
		glm::vec3 dir = glm::vec3(glm::cos(glm::radians(cur_rot.x - 135.0f)), 0, glm::sin(glm::radians(cur_rot.x - 135.0f)));
		cur_loc += (speed * dir) / 60.0f;
	}
	else if (move[2] && move[3]) { //������ + ��
		glm::vec3 dir = glm::vec3(glm::cos(glm::radians(cur_rot.x + 135.0f)), 0, glm::sin(glm::radians(cur_rot.x + 135.0f)));
		cur_loc += (speed * dir) / 60.0f;
	}
	else if (move[0]) {
		// ���� cur_loc�� �ٶ󺸴� �������� spd/60��ŭ ���Ѵ�.(60�������̴ϱ� 4cm/s�Ͻ� 4/60����)
<<<<<<< Updated upstream
		
=======
		glm::vec3 dir = glm::vec3(glm::cos(glm::radians(cur_rot.x)), 0, glm::sin(glm::radians(cur_rot.x)));
		cur_loc += (speed * dir) / 60.0f;
>>>>>>> Stashed changes
	}
	else if (move[1]) {
		// ���� cur_loc�� �ٶ󺸴� ������ �������� ���� ����
		glm::vec3 dir = glm::vec3(glm::cos(glm::radians(cur_rot.x - 90.0f)), 0, glm::sin(glm::radians(cur_rot.x - 90.0f)));
		cur_loc += (speed * dir) / 60.0f;
	}
	else if (move[2]) {
		glm::vec3 dir = glm::vec3(glm::cos(glm::radians(cur_rot.x - 180.0f)), 0, glm::sin(glm::radians(cur_rot.x - 180.0f)));
		cur_loc += (speed * dir) / 60.0f;
	}
	else if (move[3]) {
		glm::vec3 dir = glm::vec3(glm::cos(glm::radians(cur_rot.x + 90.0f)), 0, glm::sin(glm::radians(cur_rot.x + 90.0f)));
		cur_loc += (speed * dir) / 60.0f;
	}
}

void Player::setRot() {
	//���콺 �����ӿ� ���� ���� ��ȯ
	cur_rot += 1.0f;
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