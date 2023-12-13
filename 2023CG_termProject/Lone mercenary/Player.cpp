#include "Player.h"
#include "Weapon.h"
#include "NM_zombie.h"
#include "CameraObj.h"
#include "Field.h"

// =========================P_Mesh==========================

//P_Mesh::P_Mesh(std::string filename) : Mesh(filename) {};
//
//P_Mesh::~P_Mesh() {};

//==========================================================

//==========================Player===========================

Player::Player(float hp, float max, float spd, float def, float atk)
	: CharacterBase(hp, max, spd, def, atk)
{
	pistol = new Pistol("obj_source\\weapon\\pistol\\obj_pistol.obj", "obj_source\\weapon\\pistol\\texture_pistol.png", 1024, 1024, 10, 10, 250);
	rifle = new Rifle("obj_source\\weapon\\rifle\\obj_rifle.obj", "obj_source\\weapon\\rifle\\texture_rifle.png", 1024, 1024, 30, 30, 270);
	knife = new Knife("obj_source\\weapon\\knife\\Knife.obj", "obj_source\\weapon\\knife\\texture_knife.png", 1024, 1024, 1, 1, 260);

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
	reloading = false;
	knife_at = false;
	cnt = 0;
	mousesense = 0.02f;
	angle = 0.0f;
	type = 0;
	bonus_atack = 0;
}

void Player::animation()
{
	//�밢�� ���� Ű���� ó���ϰ� �̱�Ű ó��
	if (move[0] && move[1]) { //���� + ��
		glm::vec3 dir = glm::vec3(glm::cos(glm::radians(cur_rot.x - 45.0f)), 0, glm::sin(glm::radians(cur_rot.x - 45.0f)));
		cur_loc += (speed * dir) / 60.0f;
		if (cur_loc.x >= 150.0f || cur_loc.x <= -150.0f) {
			cur_loc -= (speed * dir) / 60.0f;
		}
		if (cur_loc.z >= 150.0f || cur_loc.z <= -150.0f) {
			cur_loc -= (speed * dir) / 60.0f;
		}
		if ((-150.0f <= cur_loc.x && cur_loc.x <= -50.0f) || (50.0f <= cur_loc.x && cur_loc.x <= 150.0f)) {
			if (-150.0f <= cur_loc.z && cur_loc.z <= -50.0f) {
				cur_loc -= (speed * dir) / 60.0f;
			}
			if (50.0f <= cur_loc.z && cur_loc.z <= 150.0f) {
				cur_loc -= (speed * dir) / 60.0f;
			}
		}
	}
	else if (move[0] && move[3]) { //������ + ��
		glm::vec3 dir = glm::vec3(glm::cos(glm::radians(cur_rot.x + 45.0f)), 0, glm::sin(glm::radians(cur_rot.x + 45.0f)));
		cur_loc += (speed * dir) / 60.0f;
		if (cur_loc.x >= 150.0f || cur_loc.x <= -150.0f) {
			cur_loc -= (speed * dir) / 60.0f;
		}
		if (cur_loc.z >= 150.0f || cur_loc.z <= -150.0f) {
			cur_loc -= (speed * dir) / 60.0f;
		}
		if ((-150.0f <= cur_loc.x && cur_loc.x <= -50.0f) || (50.0f <= cur_loc.x && cur_loc.x <= 150.0f)) {
			if (-150.0f <= cur_loc.z && cur_loc.z <= -50.0f) {
				cur_loc -= (speed * dir) / 60.0f;
			}
			if (50.0f <= cur_loc.z && cur_loc.z <= 150.0f) {
				cur_loc -= (speed * dir) / 60.0f;
			}
		}
	}
	else if (move[2] && move[1]) { //���� + ��
		glm::vec3 dir = glm::vec3(glm::cos(glm::radians(cur_rot.x - 135.0f)), 0, glm::sin(glm::radians(cur_rot.x - 135.0f)));
		cur_loc += (speed * dir) / 60.0f;
		if (cur_loc.x >= 150.0f || cur_loc.x <= -150.0f) {
			cur_loc -= (speed * dir) / 60.0f;
		}
		if (cur_loc.z >= 150.0f || cur_loc.z <= -150.0f) {
			cur_loc -= (speed * dir) / 60.0f;
		}
		if ((-150.0f <= cur_loc.x && cur_loc.x <= -50.0f) || (50.0f <= cur_loc.x && cur_loc.x <= 150.0f)) {
			if (-150.0f <= cur_loc.z && cur_loc.z <= -50.0f) {
				cur_loc -= (speed * dir) / 60.0f;
			}
			if (50.0f <= cur_loc.z && cur_loc.z <= 150.0f) {
				cur_loc -= (speed * dir) / 60.0f;
			}
		}
	}
	else if (move[2] && move[3]) { //������ + ��
		glm::vec3 dir = glm::vec3(glm::cos(glm::radians(cur_rot.x + 135.0f)), 0, glm::sin(glm::radians(cur_rot.x + 135.0f)));
		cur_loc += (speed * dir) / 60.0f;
		if (cur_loc.x >= 150.0f || cur_loc.x <= -150.0f) {
			cur_loc -= (speed * dir) / 60.0f;
		}
		if (cur_loc.z >= 150.0f || cur_loc.z <= -150.0f) {
			cur_loc -= (speed * dir) / 60.0f;
		}
		if ((-150.0f <= cur_loc.x && cur_loc.x <= -50.0f) || (50.0f <= cur_loc.x && cur_loc.x <= 150.0f)) {
			if (-150.0f <= cur_loc.z && cur_loc.z <= -50.0f) {
				cur_loc -= (speed * dir) / 60.0f;
			}
			if (50.0f <= cur_loc.z && cur_loc.z <= 150.0f) {
				cur_loc -= (speed * dir) / 60.0f;
			}
		}
	}
	else if (move[0]) {
		// ���� cur_loc�� �ٶ󺸴� �������� spd/60��ŭ ���Ѵ�.(60�������̴ϱ� 4cm/s�Ͻ� 4/60����)
		glm::vec3 dir = glm::vec3(glm::cos(glm::radians(cur_rot.x)), 0, glm::sin(glm::radians(cur_rot.x)));
		cur_loc += (speed * dir) / 60.0f;
		if (cur_loc.x >= 150.0f || cur_loc.x <= -150.0f) {
			cur_loc -= (speed * dir) / 60.0f;
		}
		if (cur_loc.z >= 150.0f || cur_loc.z <= -150.0f) {
			cur_loc -= (speed * dir) / 60.0f;
		}
		if ((-150.0f <= cur_loc.x && cur_loc.x <= -50.0f) || (50.0f <= cur_loc.x && cur_loc.x <= 150.0f)) {
			if (-150.0f <= cur_loc.z && cur_loc.z <= -50.0f) {
				cur_loc -= (speed * dir) / 60.0f;
			}
			if (50.0f <= cur_loc.z && cur_loc.z <= 150.0f) {
				cur_loc -= (speed * dir) / 60.0f;
			}
		}
	}
	else if (move[1]) {
		// ���� cur_loc�� �ٶ󺸴� ������ �������� ���� ����
		glm::vec3 dir = glm::vec3(glm::cos(glm::radians(cur_rot.x - 90.0f)), 0, glm::sin(glm::radians(cur_rot.x - 90.0f)));
		cur_loc += (speed * dir) / 60.0f;
		if (cur_loc.x >= 150.0f || cur_loc.x <= -150.0f) {
			cur_loc -= (speed * dir) / 60.0f;
		}
		if (cur_loc.z >= 150.0f || cur_loc.z <= -150.0f) {
			cur_loc -= (speed * dir) / 60.0f;
		}
		if ((-150.0f <= cur_loc.x && cur_loc.x <= -50.0f) || (50.0f <= cur_loc.x && cur_loc.x <= 150.0f)) {
			if (-150.0f <= cur_loc.z && cur_loc.z <= -50.0f) {
				cur_loc -= (speed * dir) / 60.0f;
			}
			if (50.0f <= cur_loc.z && cur_loc.z <= 150.0f) {
				cur_loc -= (speed * dir) / 60.0f;
			}
		}
	}
	else if (move[2]) {
		glm::vec3 dir = glm::vec3(glm::cos(glm::radians(cur_rot.x - 180.0f)), 0, glm::sin(glm::radians(cur_rot.x - 180.0f)));
		cur_loc += (speed * dir) / 60.0f;
		if (cur_loc.x >= 150.0f || cur_loc.x <= -150.0f) {
			cur_loc -= (speed * dir) / 60.0f;
		}
		if (cur_loc.z >= 150.0f || cur_loc.z <= -150.0f) {
			cur_loc -= (speed * dir) / 60.0f;
		}
		if ((-150.0f <= cur_loc.x && cur_loc.x <= -50.0f) || (50.0f <= cur_loc.x && cur_loc.x <= 150.0f)) {
			if (-150.0f <= cur_loc.z && cur_loc.z <= -50.0f) {
				cur_loc -= (speed * dir) / 60.0f;
			}
			if (50.0f <= cur_loc.z && cur_loc.z <= 150.0f) {
				cur_loc -= (speed * dir) / 60.0f;
			}
		}
	}
	else if (move[3]) {
		glm::vec3 dir = glm::vec3(glm::cos(glm::radians(cur_rot.x + 90.0f)), 0, glm::sin(glm::radians(cur_rot.x + 90.0f)));
		cur_loc += (speed * dir) / 60.0f;
		if (cur_loc.x >= 150.0f || cur_loc.x <= -150.0f) {
			cur_loc -= (speed * dir) / 60.0f;
		}
		if (cur_loc.z >= 150.0f || cur_loc.z <= -150.0f) {
			cur_loc -= (speed * dir) / 60.0f;
		}
		if ((-150.0f <= cur_loc.x && cur_loc.x <= -50.0f) || (50.0f <= cur_loc.x && cur_loc.x <= 150.0f)) {
			if (-150.0f <= cur_loc.z && cur_loc.z <= -50.0f) {
				cur_loc -= (speed * dir) / 60.0f;
			}
			if (50.0f <= cur_loc.z && cur_loc.z <= 150.0f) {
				cur_loc -= (speed * dir) / 60.0f;
			}
		}
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
		if (bonus_atack != 0) {
			ATK += bonus_atack;
		}
		init_Weapon_rot.x = cur_rot.x;
		init_Weapon_rot.y = cur_rot.y + 90.0f;
		changing = true;
		std::cout << weapon << " - " << ATK << std::endl;
		break;
	case '2':
		cur_Wea = pistol;
		weapon = cur_Wea->getWep();
		ATK = cur_Wea->getATK();
		if (bonus_atack != 0) {
			ATK += bonus_atack;
		}
		init_Weapon_rot.x = cur_rot.x;
		init_Weapon_rot.y = cur_rot.y + 90.0f;
		changing = true;
		std::cout << weapon << " - " << ATK << std::endl;
		break;
	case '3':
		cur_Wea = knife;
		weapon = cur_Wea->getWep();
		ATK = cur_Wea->getATK();
		if (bonus_atack != 0) {
			ATK += bonus_atack;
		}
		init_Weapon_rot.x = cur_rot.x;
		init_Weapon_rot.y = cur_rot.y + 90.0f;
		changing = true;
		std::cout << weapon << " - " << ATK << std::endl;
		break;
	case 'r':
		if (cur_Wea != knife) {
			if (cur_Wea->gettotal() != 0) {
				if (cur_Wea->is_max()) {
					cur_Wea->reloading();
					reloading = true;
				}
			}
		}
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
			else {
				knife_at = true;
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
	if (274 <= x && x <= 623) {
		if (12 <= y && y <= 355) {
			if (!item[0]) {
				item[0] = true;
				//std::cout << "1�� ������ ����" << std::endl;
			}
			else {
				item[0] = false;
				//std::cout << "1�� ������ ���" << std::endl;
			}
		}
		if (356 <= y && y <= 708) {
			if (!item[2]) {
				item[2] = true;
				//std::cout << "3�� ������ ����" << std::endl;
			}
			else {
				item[2] = false;
				//std::cout << "3�� ������ ���" << std::endl;
			}
		}
	}
	if (657 <= x && x <= 1005) {
		if (12 <= y && y <= 355) {
			if (!item[1]) {
				item[1] = true;
				//std::cout << "2�� ������ ����" << std::endl;
			}
			else {
				item[1] = false;
				//std::cout << "2�� ������ ���" << std::endl;
			}
		}
		if (356 <= y && y <= 708) {
			if (!item[3]) {
				item[3] = true;
				//std::cout << "4�� ������ ����" << std::endl;
			}
			else {
				item[3] = false;
				//std::cout << "4�� ������ ���" << std::endl;
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
		HP += 200;
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
		bonus_atack = 200;
		item[3] = false;
		std::cout << "�÷��̾� ���ݷ� ���� �Ϸ� : " << ATK << std::endl;
	}
}

void Player::reload_ani()
{
	if (reloading) {
		if (type == 0) {
			init_Weapon_rot.x -= 5.0f;
			angle -= 5.0f;
			if (angle <= -45.0f) {
				type = 1;
			}
		}
		if (type == 1) {
			init_Weapon_rot.x += 5.0f;
			angle += 5.0f;
			if (angle >= 0.0f) {
				type = 0;
				angle = 0.0f;
				reloading = false;
			}
		}
	}
}

bool Player::do_reload_ani()
{
	return reloading;
}

void Player::knife_AT_ani()
{
	if (knife_at) {
		if (type == 0) {
			init_Weapon_rot.x -= 3.0f;
			angle -= 3.0f;
			if (angle <= -15.0f) {
				type = 1;
			}
		}
		if (type == 1) {
			init_Weapon_rot.x += 3.0f;
			angle += 3.0f;
			if (angle >= 15.0f) {
				type = 2;
			}
		}
		if (type == 2) {
			init_Weapon_rot.x -= 3.0f;
			angle -= 3.0f;
			if (angle <= 0.0f) {
				type = 0;
				angle = 0.0f;
				knife_at = false;
			}
		}
	}
}

bool Player::check_reload_ammo()
{
	return cur_Wea->exist_ammo();
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

void Player::attack_check(std::vector<EnemyBase*>& temp_list, CameraObj* temp_camera)
{	// ���� ���� 1. ���� ����Ʈ   2. ī�޶�(��ġ�� �ٶ󺸴� �� �޾Ƽ� ���� ���ϰ�
	int aliving = 0;		// ����ִ� ���� ��
	glm::vec3 contact = glm::vec3(1.0f);
	glm::vec3 MinVec = glm::vec3(1.0f);
	glm::vec3 MaxVec = glm::vec3(1.0f);
	glm::vec3 FinalMinVec = glm::vec3(1.0f);
	glm::vec3 FinalMaxVec = glm::vec3(1.0f);
	glm::mat4 toWorld = glm::mat4(1.0f);
	float contact_distance[MAX_ALIVE] = {0.0f}; //�Ÿ� ���� �� 
	float mindist = 0.0f;
	bool is_contact = false;
	int bonus_damage = 0;
	switch (weapon) { //�� ��Ÿ� ����
	case ������:
		mindist = 200.0f;
		break;
	case ����:
		mindist = 3000.0f;
		break;
	case ������:
		mindist = 8000.0f;
		break;
	}
	glm::vec3 ray_first = glm::vec3(temp_camera->getEYE());
	glm::vec3 ray_last = glm::vec3(temp_camera->getAT());
	glm::vec3 ray = ray_last - ray_first;
	//std::cout << ray_first.x << "\t" << ray_first.y << "\t" << ray_first.z << std::endl;
	//std::cout << ray.x << "\t" << ray.y << "\t" << ray.z << std::endl;
	int alive{};
	EnemyBase* aliveEnemy[MAX_ALIVE];
	bool update_first = false;
	for (int i = Field::first_zom; i < temp_list.size(); ++i) {
		if (not temp_list[i]->Death_check()) {
			if (not update_first) {
				Field::first_zom = i;
				update_first = true;
			}
			aliveEnemy[alive++] = temp_list[i];
			if (MAX_ALIVE == alive)
				break;
		}
	}
	for (int i = 0; i < alive; ++i) {
		float xz_dist = 0.0f;
		float yz_dist = 0.0f;
		float xy_dist = 0.0f;
		float min_x = 0.0f, max_x = 0.0f;
		float min_y = 0.0f, max_y = 0.0f;
		float min_z = 0.0f, max_z = 0.0f;
		if (aliving < MAX_ALIVE) {			// �ִ� 12������ �ʵ忡 ���´�
			// ������� �Ӹ� ���� �������� Ȯ���ؼ� 
			// update_hp()���ش�.
			// ���� �������� �޾Ƽ� üũ(�ϴ��� �Ӹ���)
			MinVec = dynamic_cast<NM_zombie*>(aliveEnemy[i])->gethead()->getLB();	// <- �ٿ���� �ڽ� ���� �Ʒ� ��
			MaxVec = dynamic_cast<NM_zombie*>(aliveEnemy[i])->gethead()->getRT();	// <- ������ ��
			toWorld = dynamic_cast<NM_zombie*>(aliveEnemy[i])->gethead()->getModelTrans();	// �𵨸� ��ȯ ����� ������� ��ǥ ���µ�.
			FinalMinVec = glm::vec3(toWorld * glm::vec4(MinVec, 1.0f)); //��ȯ�� ���� �ٿ���� �ڽ� ���� �Ʒ� ��
			FinalMaxVec = glm::vec3(toWorld * glm::vec4(MaxVec, 1.0f)); //��ȯ�� ���� �ٿ���� �ڽ� ������ �� ��

			if (FinalMaxVec.x > FinalMinVec.x) {
				min_x = FinalMinVec.x;
				max_x = FinalMaxVec.x;
			}
			else {
				min_x = FinalMaxVec.x;
				max_x = FinalMinVec.x;
			}
			if (FinalMaxVec.y > FinalMinVec.y) {
				min_y = FinalMinVec.y;
				max_y = FinalMaxVec.y;
			}
			else {
				min_y = FinalMaxVec.y;
				max_y = FinalMinVec.y;
			}
			if (FinalMaxVec.z > FinalMinVec.z) {
				min_z = FinalMinVec.z;
				max_z = FinalMaxVec.z;
			}
			else {
				min_z = FinalMaxVec.z;
				max_z = FinalMinVec.z;
			}
			// [1] YZ ��� �˻�
			contact = RaytoPlaneYZ(ray_first, ray_last, min_x);
			if (min_y <= contact.y && contact.y <= max_y) {
				if (min_z <= contact.z && contact.z <= max_z) {
					yz_dist = pow(contact.x - ray_first.x, 2) + pow(contact.y - ray_first.y, 2) + pow(contact.z - ray_first.z, 2);
					contact_distance[i] = yz_dist;
					is_contact = true;
					//std::cout << i << "- YZ���\t" << contact.x << "\t" << contact.y << "\t" << contact.z << std::endl;
				}
			}

			// [2] XZ ��� �˻�
			contact = RaytoPlaneXZ(ray_first, ray_last, min_y);
			if (min_x <= contact.x && contact.x <= max_x) {
				if (min_z <= contact.z && contact.z <= max_z) {
					xz_dist = pow(contact.x - ray_first.x, 2) + pow(contact.y - ray_first.y, 2) + pow(contact.z - ray_first.z, 2);
					if (contact_distance[i] != 0.0f) {
						if (xz_dist < contact_distance[i]) {
							contact_distance[i] = xz_dist;
							is_contact = true;
							//std::cout << i << "- XZ���\t" << contact.x << "\t" << contact.y << "\t" << contact.z << std::endl;
						}
					}
					else {
						contact_distance[i] = xz_dist;
						is_contact = true;
						//std::cout << i << "- XZ���\t" << contact.x << "\t" << contact.y << "\t" << contact.z << std::endl;
					}
				}
			}

			// [3] XY ��� �˻�
			contact = RaytoPlaneXY(ray_first, ray_last, min_z);
			if (min_x <= contact.x && contact.x <= max_x) {
				if (min_y <= contact.y && contact.y <= max_y) {
					xy_dist = pow(contact.x - ray_first.x, 2) + pow(contact.y - ray_first.y, 2) + pow(contact.z - ray_first.z, 2);
					if (contact_distance[i] != 0.0f) {
						if (xy_dist < contact_distance[i]) {
							contact_distance[i] = xy_dist;
							is_contact = true;
							//std::cout << i << "- XY���\t" << contact.x << "\t" << contact.y << "\t" << contact.z << std::endl;
						}
					}
					else {
						contact_distance[i] = xy_dist;
						is_contact = true;
						//std::cout << i << "- XY���\t" << contact.x << "\t" << contact.y << "\t" << contact.z << std::endl;
					}
				}
			}

			if (is_contact) {
				is_contact = false;
				++aliving;
				bonus_damage = 200;
				dynamic_cast<NM_zombie*>(aliveEnemy[i])->setHit(true);
				continue;
			}

			MinVec = dynamic_cast<NM_zombie*>(aliveEnemy[i])->getbody()->getLB();	// <- �ٿ���� �ڽ� ���� �Ʒ� ��
			MaxVec = dynamic_cast<NM_zombie*>(aliveEnemy[i])->getbody()->getRT();	// <- ������ ��
			toWorld = dynamic_cast<NM_zombie*>(aliveEnemy[i])->getbody()->getModelTrans();	// �𵨸� ��ȯ ����� ������� ��ǥ ���µ�.
			FinalMinVec = glm::vec3(toWorld * glm::vec4(MinVec, 1.0f)); //��ȯ�� ���� �ٿ���� �ڽ� ���� �Ʒ� ��
			FinalMaxVec = glm::vec3(toWorld * glm::vec4(MaxVec, 1.0f)); //��ȯ�� ���� �ٿ���� �ڽ� ������ �� ��

			if (FinalMaxVec.x > FinalMinVec.x) {
				min_x = FinalMinVec.x;
				max_x = FinalMaxVec.x;
			}
			else {
				min_x = FinalMaxVec.x;
				max_x = FinalMinVec.x;
			}
			if (FinalMaxVec.y > FinalMinVec.y) {
				min_y = FinalMinVec.y;
				max_y = FinalMaxVec.y;
			}
			else {
				min_y = FinalMaxVec.y;
				max_y = FinalMinVec.y;
			}
			if (FinalMaxVec.z > FinalMinVec.z) {
				min_z = FinalMinVec.z;
				max_z = FinalMaxVec.z;
			}
			else {
				min_z = FinalMaxVec.z;
				max_z = FinalMinVec.z;
			}
			contact = RaytoPlaneYZ(ray_first, ray_last, min_x);
			if (min_y <= contact.y && contact.y <= max_y) {
				if (min_z <= contact.z && contact.z <= max_z) {
					yz_dist = pow(contact.x - ray_first.x, 2) + pow(contact.y - ray_first.y, 2) + pow(contact.z - ray_first.z, 2);
					contact_distance[i] = yz_dist;
					is_contact = true;
					//std::cout << i << "- YZ���\t" << contact.x << "\t" << contact.y << "\t" << contact.z << std::endl;
				}
			}

			// [2] XZ ��� �˻�
			contact = RaytoPlaneXZ(ray_first, ray_last, min_y);
			if (min_x <= contact.x && contact.x <= max_x) {
				if (min_z <= contact.z && contact.z <= max_z) {
					xz_dist = pow(contact.x - ray_first.x, 2) + pow(contact.y - ray_first.y, 2) + pow(contact.z - ray_first.z, 2);
					if (contact_distance[i] != 0.0f) {
						if (xz_dist < contact_distance[i]) {
							contact_distance[i] = xz_dist;
							is_contact = true;
							//std::cout << i << "- XZ���\t" << contact.x << "\t" << contact.y << "\t" << contact.z << std::endl;
						}
					}
					else {
						contact_distance[i] = xz_dist;
						is_contact = true;
						//std::cout << i << "- XZ���\t" << contact.x << "\t" << contact.y << "\t" << contact.z << std::endl;
					}
				}
			}

			// [3] XY ��� �˻�
			contact = RaytoPlaneXY(ray_first, ray_last, min_z);
			if (min_x <= contact.x && contact.x <= max_x) {
				if (min_y <= contact.y && contact.y <= max_y) {
					xy_dist = pow(contact.x - ray_first.x, 2) + pow(contact.y - ray_first.y, 2) + pow(contact.z - ray_first.z, 2);
					if (contact_distance[i] != 0.0f) {
						if (xy_dist < contact_distance[i]) {
							contact_distance[i] = xy_dist;
							is_contact = true;
							//std::cout << i << "- XY���\t" << contact.x << "\t" << contact.y << "\t" << contact.z << std::endl;
						}
					}
					else {
						contact_distance[i] = xy_dist;
						is_contact = true;
						//std::cout << i << "- XY���\t" << contact.x << "\t" << contact.y << "\t" << contact.z << std::endl;
					}
				}
			}

			if (is_contact) {
				is_contact = false;
				++aliving;
				bonus_damage = 0;
				continue;
			}

			MinVec = dynamic_cast<NM_zombie*>(aliveEnemy[i])->getlarm()->getLB();	// <- �ٿ���� �ڽ� ���� �Ʒ� ��
			MaxVec = dynamic_cast<NM_zombie*>(aliveEnemy[i])->getlarm()->getRT();	// <- ������ ��
			toWorld = dynamic_cast<NM_zombie*>(aliveEnemy[i])->getlarm()->getModelTrans();	// �𵨸� ��ȯ ����� ������� ��ǥ ���µ�.
			FinalMinVec = glm::vec3(toWorld * glm::vec4(MinVec, 1.0f)); //��ȯ�� ���� �ٿ���� �ڽ� ���� �Ʒ� ��
			FinalMaxVec = glm::vec3(toWorld * glm::vec4(MaxVec, 1.0f)); //��ȯ�� ���� �ٿ���� �ڽ� ������ �� ��

			if (FinalMaxVec.x > FinalMinVec.x) {
				min_x = FinalMinVec.x;
				max_x = FinalMaxVec.x;
			}
			else {
				min_x = FinalMaxVec.x;
				max_x = FinalMinVec.x;
			}
			if (FinalMaxVec.y > FinalMinVec.y) {
				min_y = FinalMinVec.y;
				max_y = FinalMaxVec.y;
			}
			else {
				min_y = FinalMaxVec.y;
				max_y = FinalMinVec.y;
			}
			if (FinalMaxVec.z > FinalMinVec.z) {
				min_z = FinalMinVec.z;
				max_z = FinalMaxVec.z;
			}
			else {
				min_z = FinalMaxVec.z;
				max_z = FinalMinVec.z;
			}
			contact = RaytoPlaneYZ(ray_first, ray_last, min_x);
			if (min_y <= contact.y && contact.y <= max_y) {
				if (min_z <= contact.z && contact.z <= max_z) {
					yz_dist = pow(contact.x - ray_first.x, 2) + pow(contact.y - ray_first.y, 2) + pow(contact.z - ray_first.z, 2);
					contact_distance[i] = yz_dist;
					is_contact = true;
					//std::cout << i << "- YZ���\t" << contact.x << "\t" << contact.y << "\t" << contact.z << std::endl;
				}
			}

			// [2] XZ ��� �˻�
			contact = RaytoPlaneXZ(ray_first, ray_last, min_y);
			if (min_x <= contact.x && contact.x <= max_x) {
				if (min_z <= contact.z && contact.z <= max_z) {
					xz_dist = pow(contact.x - ray_first.x, 2) + pow(contact.y - ray_first.y, 2) + pow(contact.z - ray_first.z, 2);
					if (contact_distance[i] != 0.0f) {
						if (xz_dist < contact_distance[i]) {
							contact_distance[i] = xz_dist;
							is_contact = true;
							//std::cout << i << "- XZ���\t" << contact.x << "\t" << contact.y << "\t" << contact.z << std::endl;
						}
					}
					else {
						contact_distance[i] = xz_dist;
						is_contact = true;
						//std::cout << i << "- XZ���\t" << contact.x << "\t" << contact.y << "\t" << contact.z << std::endl;
					}
				}
			}

			// [3] XY ��� �˻�
			contact = RaytoPlaneXY(ray_first, ray_last, min_z);
			if (min_x <= contact.x && contact.x <= max_x) {
				if (min_y <= contact.y && contact.y <= max_y) {
					xy_dist = pow(contact.x - ray_first.x, 2) + pow(contact.y - ray_first.y, 2) + pow(contact.z - ray_first.z, 2);
					if (contact_distance[i] != 0.0f) {
						if (xy_dist < contact_distance[i]) {
							contact_distance[i] = xy_dist;
							is_contact = true;
							//std::cout << i << "- XY���\t" << contact.x << "\t" << contact.y << "\t" << contact.z << std::endl;
						}
					}
					else {
						contact_distance[i] = xy_dist;
						is_contact = true;
						//std::cout << i << "- XY���\t" << contact.x << "\t" << contact.y << "\t" << contact.z << std::endl;
					}
				}
			}

			if (is_contact) {
				is_contact = false;
				++aliving;
				bonus_damage = 0;
				continue;
			}

			MinVec = dynamic_cast<NM_zombie*>(aliveEnemy[i])->getrarm()->getLB();	// <- �ٿ���� �ڽ� ���� �Ʒ� ��
			MaxVec = dynamic_cast<NM_zombie*>(aliveEnemy[i])->getrarm()->getRT();	// <- ������ ��
			toWorld = dynamic_cast<NM_zombie*>(aliveEnemy[i])->getrarm()->getModelTrans();	// �𵨸� ��ȯ ����� ������� ��ǥ ���µ�.
			FinalMinVec = glm::vec3(toWorld * glm::vec4(MinVec, 1.0f)); //��ȯ�� ���� �ٿ���� �ڽ� ���� �Ʒ� ��
			FinalMaxVec = glm::vec3(toWorld * glm::vec4(MaxVec, 1.0f)); //��ȯ�� ���� �ٿ���� �ڽ� ������ �� ��

			if (FinalMaxVec.x > FinalMinVec.x) {
				min_x = FinalMinVec.x;
				max_x = FinalMaxVec.x;
			}
			else {
				min_x = FinalMaxVec.x;
				max_x = FinalMinVec.x;
			}
			if (FinalMaxVec.y > FinalMinVec.y) {
				min_y = FinalMinVec.y;
				max_y = FinalMaxVec.y;
			}
			else {
				min_y = FinalMaxVec.y;
				max_y = FinalMinVec.y;
			}
			if (FinalMaxVec.z > FinalMinVec.z) {
				min_z = FinalMinVec.z;
				max_z = FinalMaxVec.z;
			}
			else {
				min_z = FinalMaxVec.z;
				max_z = FinalMinVec.z;
			}
			contact = RaytoPlaneYZ(ray_first, ray_last, min_x);
			if (min_y <= contact.y && contact.y <= max_y) {
				if (min_z <= contact.z && contact.z <= max_z) {
					yz_dist = pow(contact.x - ray_first.x, 2) + pow(contact.y - ray_first.y, 2) + pow(contact.z - ray_first.z, 2);
					contact_distance[i] = yz_dist;
					is_contact = true;
					//std::cout << i << "- YZ���\t" << contact.x << "\t" << contact.y << "\t" << contact.z << std::endl;
				}
			}

			// [2] XZ ��� �˻�
			contact = RaytoPlaneXZ(ray_first, ray_last, min_y);
			if (min_x <= contact.x && contact.x <= max_x) {
				if (min_z <= contact.z && contact.z <= max_z) {
					xz_dist = pow(contact.x - ray_first.x, 2) + pow(contact.y - ray_first.y, 2) + pow(contact.z - ray_first.z, 2);
					if (contact_distance[i] != 0.0f) {
						if (xz_dist < contact_distance[i]) {
							contact_distance[i] = xz_dist;
							is_contact = true;
							//std::cout << i << "- XZ���\t" << contact.x << "\t" << contact.y << "\t" << contact.z << std::endl;
						}
					}
					else {
						contact_distance[i] = xz_dist;
						is_contact = true;
						//std::cout << i << "- XZ���\t" << contact.x << "\t" << contact.y << "\t" << contact.z << std::endl;
					}
				}
			}

			// [3] XY ��� �˻�
			contact = RaytoPlaneXY(ray_first, ray_last, min_z);
			if (min_x <= contact.x && contact.x <= max_x) {
				if (min_y <= contact.y && contact.y <= max_y) {
					xy_dist = pow(contact.x - ray_first.x, 2) + pow(contact.y - ray_first.y, 2) + pow(contact.z - ray_first.z, 2);
					if (contact_distance[i] != 0.0f) {
						if (xy_dist < contact_distance[i]) {
							contact_distance[i] = xy_dist;
							is_contact = true;
							//std::cout << i << "- XY���\t" << contact.x << "\t" << contact.y << "\t" << contact.z << std::endl;
						}
					}
					else {
						contact_distance[i] = xy_dist;
						is_contact = true;
						//std::cout << i << "- XY���\t" << contact.x << "\t" << contact.y << "\t" << contact.z << std::endl;
					}
				}
			}

			if (is_contact) {
				is_contact = false;
				++aliving;
				bonus_damage = 0;
				continue;
			}

			MinVec = dynamic_cast<NM_zombie*>(aliveEnemy[i])->getlleg()->getLB();	// <- �ٿ���� �ڽ� ���� �Ʒ� ��
			MaxVec = dynamic_cast<NM_zombie*>(aliveEnemy[i])->getlleg()->getRT();	// <- ������ ��
			toWorld = dynamic_cast<NM_zombie*>(aliveEnemy[i])->getlleg()->getModelTrans();	// �𵨸� ��ȯ ����� ������� ��ǥ ���µ�.
			FinalMinVec = glm::vec3(toWorld * glm::vec4(MinVec, 1.0f)); //��ȯ�� ���� �ٿ���� �ڽ� ���� �Ʒ� ��
			FinalMaxVec = glm::vec3(toWorld * glm::vec4(MaxVec, 1.0f)); //��ȯ�� ���� �ٿ���� �ڽ� ������ �� ��

			if (FinalMaxVec.x > FinalMinVec.x) {
				min_x = FinalMinVec.x;
				max_x = FinalMaxVec.x;
			}
			else {
				min_x = FinalMaxVec.x;
				max_x = FinalMinVec.x;
			}
			if (FinalMaxVec.y > FinalMinVec.y) {
				min_y = FinalMinVec.y;
				max_y = FinalMaxVec.y;
			}
			else {
				min_y = FinalMaxVec.y;
				max_y = FinalMinVec.y;
			}
			if (FinalMaxVec.z > FinalMinVec.z) {
				min_z = FinalMinVec.z;
				max_z = FinalMaxVec.z;
			}
			else {
				min_z = FinalMaxVec.z;
				max_z = FinalMinVec.z;
			}
			contact = RaytoPlaneYZ(ray_first, ray_last, min_x);
			if (min_y <= contact.y && contact.y <= max_y) {
				if (min_z <= contact.z && contact.z <= max_z) {
					yz_dist = pow(contact.x - ray_first.x, 2) + pow(contact.y - ray_first.y, 2) + pow(contact.z - ray_first.z, 2);
					contact_distance[i] = yz_dist;
					is_contact = true;
					//std::cout << i << "- YZ���\t" << contact.x << "\t" << contact.y << "\t" << contact.z << std::endl;
				}
			}

			// [2] XZ ��� �˻�
			contact = RaytoPlaneXZ(ray_first, ray_last, min_y);
			if (min_x <= contact.x && contact.x <= max_x) {
				if (min_z <= contact.z && contact.z <= max_z) {
					xz_dist = pow(contact.x - ray_first.x, 2) + pow(contact.y - ray_first.y, 2) + pow(contact.z - ray_first.z, 2);
					if (contact_distance[i] != 0.0f) {
						if (xz_dist < contact_distance[i]) {
							contact_distance[i] = xz_dist;
							is_contact = true;
							//std::cout << i << "- XZ���\t" << contact.x << "\t" << contact.y << "\t" << contact.z << std::endl;
						}
					}
					else {
						contact_distance[i] = xz_dist;
						is_contact = true;
						//std::cout << i << "- XZ���\t" << contact.x << "\t" << contact.y << "\t" << contact.z << std::endl;
					}
				}
			}

			// [3] XY ��� �˻�
			contact = RaytoPlaneXY(ray_first, ray_last, min_z);
			if (min_x <= contact.x && contact.x <= max_x) {
				if (min_y <= contact.y && contact.y <= max_y) {
					xy_dist = pow(contact.x - ray_first.x, 2) + pow(contact.y - ray_first.y, 2) + pow(contact.z - ray_first.z, 2);
					if (contact_distance[i] != 0.0f) {
						if (xy_dist < contact_distance[i]) {
							contact_distance[i] = xy_dist;
							is_contact = true;
							//std::cout << i << "- XY���\t" << contact.x << "\t" << contact.y << "\t" << contact.z << std::endl;
						}
					}
					else {
						contact_distance[i] = xy_dist;
						is_contact = true;
						//std::cout << i << "- XY���\t" << contact.x << "\t" << contact.y << "\t" << contact.z << std::endl;
					}
				}
			}

			if (is_contact) {
				is_contact = false;
				++aliving;
				bonus_damage = 0;
				continue;
			}

			MinVec = dynamic_cast<NM_zombie*>(aliveEnemy[i])->getrleg()->getLB();	// <- �ٿ���� �ڽ� ���� �Ʒ� ��
			MaxVec = dynamic_cast<NM_zombie*>(aliveEnemy[i])->getrleg()->getRT();	// <- ������ ��
			toWorld = dynamic_cast<NM_zombie*>(aliveEnemy[i])->getrleg()->getModelTrans();	// �𵨸� ��ȯ ����� ������� ��ǥ ���µ�.
			FinalMinVec = glm::vec3(toWorld * glm::vec4(MinVec, 1.0f)); //��ȯ�� ���� �ٿ���� �ڽ� ���� �Ʒ� ��
			FinalMaxVec = glm::vec3(toWorld * glm::vec4(MaxVec, 1.0f)); //��ȯ�� ���� �ٿ���� �ڽ� ������ �� ��

			if (FinalMaxVec.x > FinalMinVec.x) {
				min_x = FinalMinVec.x;
				max_x = FinalMaxVec.x;
			}
			else {
				min_x = FinalMaxVec.x;
				max_x = FinalMinVec.x;
			}
			if (FinalMaxVec.y > FinalMinVec.y) {
				min_y = FinalMinVec.y;
				max_y = FinalMaxVec.y;
			}
			else {
				min_y = FinalMaxVec.y;
				max_y = FinalMinVec.y;
			}
			if (FinalMaxVec.z > FinalMinVec.z) {
				min_z = FinalMinVec.z;
				max_z = FinalMaxVec.z;
			}
			else {
				min_z = FinalMaxVec.z;
				max_z = FinalMinVec.z;
			}
			contact = RaytoPlaneYZ(ray_first, ray_last, min_x);
			if (min_y <= contact.y && contact.y <= max_y) {
				if (min_z <= contact.z && contact.z <= max_z) {
					yz_dist = pow(contact.x - ray_first.x, 2) + pow(contact.y - ray_first.y, 2) + pow(contact.z - ray_first.z, 2);
					contact_distance[i] = yz_dist;
					is_contact = true;
					//std::cout << i << "- YZ���\t" << contact.x << "\t" << contact.y << "\t" << contact.z << std::endl;
				}
			}

			// [2] XZ ��� �˻�
			contact = RaytoPlaneXZ(ray_first, ray_last, min_y);
			if (min_x <= contact.x && contact.x <= max_x) {
				if (min_z <= contact.z && contact.z <= max_z) {
					xz_dist = pow(contact.x - ray_first.x, 2) + pow(contact.y - ray_first.y, 2) + pow(contact.z - ray_first.z, 2);
					if (contact_distance[i] != 0.0f) {
						if (xz_dist < contact_distance[i]) {
							contact_distance[i] = xz_dist;
							is_contact = true;
							//std::cout << i << "- XZ���\t" << contact.x << "\t" << contact.y << "\t" << contact.z << std::endl;
						}
					}
					else {
						contact_distance[i] = xz_dist;
						is_contact = true;
						//std::cout << i << "- XZ���\t" << contact.x << "\t" << contact.y << "\t" << contact.z << std::endl;
					}
				}
			}

			// [3] XY ��� �˻�
			contact = RaytoPlaneXY(ray_first, ray_last, min_z);
			if (min_x <= contact.x && contact.x <= max_x) {
				if (min_y <= contact.y && contact.y <= max_y) {
					xy_dist = pow(contact.x - ray_first.x, 2) + pow(contact.y - ray_first.y, 2) + pow(contact.z - ray_first.z, 2);
					if (contact_distance[i] != 0.0f) {
						if (xy_dist < contact_distance[i]) {
							contact_distance[i] = xy_dist;
							is_contact = true;
							//std::cout << i << "- XY���\t" << contact.x << "\t" << contact.y << "\t" << contact.z << std::endl;
						}
					}
					else {
						contact_distance[i] = xy_dist;
						is_contact = true;
						//std::cout << i << "- XY���\t" << contact.x << "\t" << contact.y << "\t" << contact.z << std::endl;
					}
				}
			}

			if (is_contact) {
				is_contact = false;
				++aliving;
				bonus_damage = 0;
				continue;
			}
		}
	}
	int whoisfirst = -1;
	for (int i = 0;i < alive;i++) { //���� ����� ���� ã��
		if (contact_distance[i] != 0.0f) {
			if (mindist > contact_distance[i]) {
				mindist = contact_distance[i];
				whoisfirst = i;
			}
		}
	}
	if (whoisfirst != -1) {
		aliveEnemy[whoisfirst]->Update_HP(-(ATK + bonus_damage)); //���ݷ¸�ŭ ����
		std::cout << whoisfirst << "\t-\t" << aliveEnemy[whoisfirst]->getHP() << std::endl;
	}
}

glm::vec3 Player::RaytoPlaneXY(glm::vec3 A, glm::vec3 B, float plane)
{
	float ratio = (B.z - plane) / (B.z - A.z);
	glm::vec3 C = glm::vec3(1.0f);
	C.x = (A.x - B.x) * ratio + (B.x);
	C.y = (A.y - B.y) * ratio + (B.y);
	C.z = plane;
	return C;
}

glm::vec3 Player::RaytoPlaneXZ(glm::vec3 A, glm::vec3 B, float plane)
{
	float ratio = (B.y - plane) / (B.y - A.y);
	glm::vec3 C = glm::vec3(1.0f);
	C.x = (A.x - B.x) * ratio + (B.x);
	C.z = (A.z - B.z) * ratio + (B.z);
	C.y = plane;
	return C;
}

glm::vec3 Player::RaytoPlaneYZ(glm::vec3 A, glm::vec3 B, float plane)
{
	float ratio = (B.x - plane) / (B.x - A.x);
	glm::vec3 C = glm::vec3(1.0f);
	C.y = (A.y - B.y) * ratio + (B.y);
	C.z = (A.z - B.z) * ratio + (B.z);
	C.x = plane;
	return C;
}
//===========================================================

bool Player::getItemapp(int n)
{
	return item[n];
}