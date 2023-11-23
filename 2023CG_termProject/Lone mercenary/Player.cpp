#include "Player.h"
#include "Weapon.h"

// =========================P_Mesh==========================

//P_Mesh::P_Mesh(std::string filename) : Mesh(filename) {};
//
//P_Mesh::~P_Mesh() {};

//==========================================================

//==========================Player===========================

Player::Player(float hp, float max, float spd, float def, float atk)
	: CharacterBase(hp, max, spd, def, atk)
{
	weapon = 나이프; //기본 무기는 나이프
	cur_loc = glm::vec3(-20, 10, 10);				// 초기 위치 지정, 이거 바꿔주면 자연스래 카메라도 위치 바뀜
	cur_rot = glm::vec2(0.0f, 0.0f);
	move[0] = move[1] = move[2] = move[3] = false;
	mousesense = 0.02f;
	pistol = new Pistol("",10,10);
	rifle = new Rifle("",30,30);
	knife = new Knife("",1,1);
}

void Player::animation()
{
	//대각선 동시 키부터 처리하고 싱글키 처리
	if (move[0] && move[1]) { //왼쪽 + 앞
		glm::vec3 dir = glm::vec3(glm::cos(glm::radians(cur_rot.x - 45.0f)), 0, glm::sin(glm::radians(cur_rot.x - 45.0f)));
		cur_loc += (speed * dir) / 60.0f;
	}
	else if (move[0] && move[3]) { //오른쪽 + 앞
		glm::vec3 dir = glm::vec3(glm::cos(glm::radians(cur_rot.x + 45.0f)), 0, glm::sin(glm::radians(cur_rot.x + 45.0f)));
		cur_loc += (speed * dir) / 60.0f;
	}
	else if (move[2] && move[1]) { //왼쪽 + 뒤
		glm::vec3 dir = glm::vec3(glm::cos(glm::radians(cur_rot.x - 135.0f)), 0, glm::sin(glm::radians(cur_rot.x - 135.0f)));
		cur_loc += (speed * dir) / 60.0f;
	}
	else if (move[2] && move[3]) { //오른쪽 + 뒤
		glm::vec3 dir = glm::vec3(glm::cos(glm::radians(cur_rot.x + 135.0f)), 0, glm::sin(glm::radians(cur_rot.x + 135.0f)));
		cur_loc += (speed * dir) / 60.0f;
	}
	else if (move[0]) {
		// 현재 cur_loc에 바라보는 방향으로 spd/60만큼 더한다.(60프레임이니까 4cm/s일시 4/60하자)
		glm::vec3 dir = glm::vec3(glm::cos(glm::radians(cur_rot.x)), 0, glm::sin(glm::radians(cur_rot.x)));
		cur_loc += (speed * dir) / 60.0f;
	}
	else if (move[1]) {
		// 현재 cur_loc에 바라보는 방향의 왼쪽으로 이하 동문
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

void Player::animi_rot(int garo,int sero) {
	//마우스 움직임에 따른 각도 변환
	if (garo > 0) {
		cur_rot.x += mousesense * garo;
	}
	if (garo < 0) {
		cur_rot.x += mousesense * garo;
	}
	if (sero > 0) {
		cur_rot.y -= mousesense * sero;
	}
	if (sero < 0) {
		cur_rot.y -= mousesense * sero;
	}
	if (cur_rot.x > 360.0f) {
		cur_rot.x = 0.0f;
	}
	if (cur_rot.x < -360.0f) {
		cur_rot.x = 0.0f;
	}
	if (cur_rot.y > 90.0f) {
		cur_rot.y = 0.0f;
	}
	if (cur_rot.y < -90.0f) {
		cur_rot.y = 0.0f;
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

void Player::setWeapon(char type)
{
	switch (type) {
	case '1':
		cur_Wea = rifle;
		weapon = cur_Wea->getWep();
		ATK = cur_Wea->getATK();
		std::cout << weapon << " - " << ATK << std::endl;
		break;
	case '2':
		cur_Wea = pistol;
		weapon = cur_Wea->getWep();
		ATK = cur_Wea->getATK();
		std::cout << weapon << " - " << ATK << std::endl;
		break;
	case '3':
		cur_Wea = knife;
		weapon = cur_Wea->getWep();
		ATK = cur_Wea->getATK();
		std::cout << weapon << " - " << ATK << std::endl;
		break;
	}
}

void Player::attack()
{
	cur_Wea->Shoot();
}

void Player::setsensative(char key)
{
	switch (key) {
	case '+':
		mousesense += 0.005f;
		break;
	case '-':
		mousesense -= 0.005f;
		if (mousesense <= 0.0f) {
			mousesense = 0.005f;
		}
		break;
	}
}

int Player::Weapon()
{
	return weapon;
}
//===========================================================