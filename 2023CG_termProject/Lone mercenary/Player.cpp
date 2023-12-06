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
	pistol = new Pistol("obj_source\\weapon\\pistol\\obj_pistol.obj", "obj_source\\weapon\\pistol\\texture_pistol.png", 1024, 1024, 10, 10, 10);
	rifle = new Rifle("obj_source\\weapon\\rifle\\obj_rifle.obj", "obj_source\\weapon\\rifle\\texture_rifle.png", 1024, 1024, 30, 30, 20);
	knife = new Knife("obj_source\\weapon\\knife\\Knife.obj", "obj_source\\weapon\\knife\\texture_knife.png", 1024, 1024, 1, 1, 5);

	rifle->init_scale(0.2);
	rifle->init_rotate(-90, 0, 1, 0);
	rifle->init_position(1, -0.5, 0.35);

	pistol->init_scale(0.5);
	pistol->init_rotate(-90, 0, 1, 0);
	pistol->init_position(1, -0.5, 0.35);

	knife->init_scale(0.5);
	knife->init_rotate(90, 1, 0, 0);
	knife->init_rotate(180, 0, 0, 1);
	knife->init_position(1.3, -0.5, 0.65);

	weapon = ������; //�⺻ ����� ������
	cur_Wea = knife;

	cur_loc = glm::vec3(0, 10, 0);				// �ʱ� ��ġ ����, �̰� �ٲ��ָ� �ڿ����� ī�޶� ��ġ �ٲ�
	cur_rot = glm::vec2(0.0f, 0.0f);
	init_Weapon_rot = glm::vec2(cur_rot.x, cur_rot.y + 90.0f);
	move[0] = move[1] = move[2] = move[3] = false;
	item[0] = item[1] = item[2] = item[3] = false;
	atck = false;
	changing = true;
	cnt = 0;
	mousesense = 0.02f;


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
		glm::vec3 dir = glm::vec3(glm::cos(glm::radians(cur_rot.x)), 0, glm::sin(glm::radians(cur_rot.x)));
		cur_loc += (speed * dir) / 60.0f;
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

void Player::animi_rot(int garo,int sero) {		// ���� �̸�??
	//���콺 �����ӿ� ���� ���� ��ȯ
	if (garo > 0) {
		cur_rot.x += mousesense * garo;
		init_Weapon_rot.x += mousesense * garo;
	}
	if (garo < 0) {
		cur_rot.x += mousesense * garo;
		init_Weapon_rot.x += mousesense * garo;
	}
	if (sero > 0) {
		cur_rot.y -= mousesense * sero;
		init_Weapon_rot.y -= mousesense * sero;
	}
	if (sero < 0) {
		cur_rot.y -= mousesense * sero;
		init_Weapon_rot.y -= mousesense * sero;
	}
	if (cur_rot.x > 360.0f) {
		cur_rot.x = 0.0f;
		init_Weapon_rot.x = 0.0f;
	}
	if (cur_rot.x < -360.0f) {
		cur_rot.x = 0.0f;
		init_Weapon_rot.x = 0.0f;
	}
	if (cur_rot.y > 87.0f) {
		cur_rot.y = 87.0f;
		init_Weapon_rot.y = 87.0f;
	}
	if (cur_rot.y < -87.0f) {
		cur_rot.y = -87.0f;
		init_Weapon_rot.y = 87.0f;
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

glm::vec2 Player::getWepRot()
{
	return init_Weapon_rot;
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
		init_Weapon_rot.x = cur_rot.x;
		init_Weapon_rot.y = cur_rot.y + 90.0f;
		changing = true;
		std::cout << weapon << " - " << ATK << std::endl;
		break;
	case '2':
		cur_Wea = pistol;
		weapon = cur_Wea->getWep();
		ATK = cur_Wea->getATK();
		init_Weapon_rot.x = cur_rot.x;
		init_Weapon_rot.y = cur_rot.y + 90.0f;
		changing = true;
		std::cout << weapon << " - " << ATK << std::endl;
		break;
	case '3':
		cur_Wea = knife;
		weapon = cur_Wea->getWep();
		ATK = cur_Wea->getATK();
		init_Weapon_rot.x = cur_rot.x;
		init_Weapon_rot.y = cur_rot.y + 90.0f;
		changing = true;
		std::cout << weapon << " - " << ATK << std::endl;
		break;
	case 'r':
		cur_Wea->reloading();
		break;
	}
}

void Player::attack()
{
	if (atck) {
		if (cur_Wea == rifle) {
			if (cnt % 10 == 0) {
				cur_Wea->Shoot();
				if (cur_Wea->exist_ammo()) {
					cur_rot.y += 1.0f; //�ݵ�
					init_Weapon_rot.y += 1.0f; //�ݵ�
				}
			}
		}
		else {
			cur_Wea->Shoot();
			if (cur_Wea == pistol) {
				if (cur_Wea->exist_ammo()) {
					cur_rot.y += 1.0f; //�ݵ�
					init_Weapon_rot.y += 1.0f; //�ݵ�
				}
			}
			atck = false;
		}
		cnt++;
	}
}

void Player::conti_attack(bool St)
{
	atck = St;
	cnt = 0;
}

void Player::take_out_Wep()
{
	if (changing) {
		init_Weapon_rot.y -= 5.0f;
		if (cur_rot.y - 2.5f <= init_Weapon_rot.y && init_Weapon_rot.y <= cur_rot.y + 2.5f) {
			changing = false;
		}
	}
}

void Player::set_item(int x,int y)
{
	if (200 <= x && x <= 400) {
		if (200 <= y && y <= 300) {
			if (!item[0]) {
				item[0] = true;
				std::cout << "1�� ������ ����" << std::endl;
			}
			else {
				item[0] = false;
				std::cout << "1�� ������ ���" << std::endl;
			}
		}
		if (400 <= y && y <= 500) {
			if (!item[2]) {
				item[2] = true;
				std::cout << "3�� ������ ����" << std::endl;
			}
			else {
				item[2] = false;
				std::cout << "3�� ������ ���" << std::endl;
			}
		}
	}
	if (500 <= x && x <= 700) {
		if (200 <= y && y <= 300) {
			if (!item[1]) {
				item[1] = true;
				std::cout << "2�� ������ ����" << std::endl;
			}
			else {
				item[1] = false;
				std::cout << "2�� ������ ���" << std::endl;
			}
		}
		if (400 <= y && y <= 500) {
			if (!item[3]) {
				item[3] = true;
				std::cout << "4�� ������ ����" << std::endl;
			}
			else {
				item[3] = false;
				std::cout << "4�� ������ ���" << std::endl;
			}
		}
	}
}

void Player::apply_item()
{
	if (item[0]) { //���� ����
		DEF += 30;
		item[0] = false;
		std::cout << "�÷��̾� ���� ���� �Ϸ� : " << DEF << std::endl;
	}
	if (item[1]) { //�ִ� ü�� ����
		MAXHP += 200;
		item[1] = false;
		std::cout << "�÷��̾� �ִ� ü�� ���� ���� �Ϸ� : " << MAXHP << std::endl;
	}
	if (item[2]) { //ź�� �� 2��
		rifle->D_ammo();
		pistol->D_ammo();
		item[2] = false;
		std::cout << "�÷��̾� ź�� �� ���� �Ϸ� : " << std::endl;
	}
	if (item[3]) { //���ݷ� ����
		ATK += 5;
		item[3] = false;
		std::cout << "�÷��̾� ���ݷ� ���� �Ϸ� : " << ATK << std::endl;
	}
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

Weapon* Player::getWeapon() const
{
	return cur_Wea;
}
//===========================================================