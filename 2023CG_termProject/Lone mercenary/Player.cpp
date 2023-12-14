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

	weapon = 나이프; //기본 무기는 나이프
	cur_Wea = knife;

	cur_loc = glm::vec3(0, 10, 0);				// 초기 위치 지정, 이거 바꿔주면 자연스래 카메라도 위치 바뀜
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

	mSound = MySound::GetInstance();
}

void Player::animation()
{
	//대각선 동시 키부터 처리하고 싱글키 처리
	if (move[0] && move[1]) { //왼쪽 + 앞
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
	else if (move[0] && move[3]) { //오른쪽 + 앞
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
	else if (move[2] && move[1]) { //왼쪽 + 뒤
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
	else if (move[2] && move[3]) { //오른쪽 + 뒤
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
		// 현재 cur_loc에 바라보는 방향으로 spd/60만큼 더한다.(60프레임이니까 4cm/s일시 4/60하자)
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
		// 현재 cur_loc에 바라보는 방향의 왼쪽으로 이하 동문
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

void Player::animi_rot(int garo,int sero) {		// 변수 이름??
	//마우스 움직임에 따른 각도 변환
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
		//std::cout << weapon << " - " << ATK << std::endl;
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
		//std::cout << weapon << " - " << ATK << std::endl;
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
		//std::cout << weapon << " - " << ATK << std::endl;
		break;
	case 'r':
		if (cur_Wea != knife) {
			if (cur_Wea->gettotal() != 0) {
				if (cur_Wea->is_max()) {
					mSound->play_s_reload();
					cur_Wea->reloading();
					reloading = true;
				}
			}
		}
		break;
	}
}

void Player::attack(std::vector<EnemyBase*>& list, CameraObj* t_camera)
{
	if (atck) {
		if (cur_Wea == rifle) {
			if (cnt % 10 == 0) {
				cur_Wea->Shoot();
				if (cur_Wea->exist_ammo()) {
					attack_check(list, t_camera);
					mSound->play_s_shot(cur_Wea->getWep());
					cur_rot.y += 1.0f; //반동
					init_Weapon_rot.y += 1.0f; //반동
				}
			}
		}
		else {
			cur_Wea->Shoot();
			if (cur_Wea == pistol) {
				if (cur_Wea->exist_ammo()) {
					attack_check(list, t_camera);
					mSound->play_s_shot(cur_Wea->getWep());
					cur_rot.y += 1.0f; //반동
					init_Weapon_rot.y += 1.0f; //반동
				}
			}
			else {
				attack_check(list, t_camera);
				mSound->play_s_shot(cur_Wea->getWep());
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
			mSound->play_click();
			if (!item[0]) {
				item[0] = true;
				//std::cout << "1번 아이템 선택" << std::endl;
			}
			else {
				item[0] = false;
				//std::cout << "1번 아이템 취소" << std::endl;
			}
		}
		if (356 <= y && y <= 708) {
			mSound->play_click();
			if (!item[2]) {
				item[2] = true;
				//std::cout << "3번 아이템 선택" << std::endl;
			}
			else {
				item[2] = false;
				//std::cout << "3번 아이템 취소" << std::endl;
			}
		}
	}
	if (657 <= x && x <= 1005) {
		if (12 <= y && y <= 355) {
			mSound->play_click();
			if (!item[1]) {
				item[1] = true;
				//std::cout << "2번 아이템 선택" << std::endl;
			}
			else {
				item[1] = false;
				//std::cout << "2번 아이템 취소" << std::endl;
			}
		}
		if (356 <= y && y <= 708) {
			mSound->play_click();
			if (!item[3]) {
				item[3] = true;
				//std::cout << "4번 아이템 선택" << std::endl;
			}
			else {
				item[3] = false;
				//std::cout << "4번 아이템 취소" << std::endl;
			}
		}
	}
}

void Player::apply_item()
{
	if (item[0]) { //방어력 증가
		DEF += 3;
		item[0] = false;
		std::cout << "플레이어 방어력 증가 완료 : " << DEF << std::endl;
	}
	if (item[1]) { //최대 체력 증가
		MAXHP += 200;
		HP += 200;
		item[1] = false;
		std::cout << "플레이어 최대 체력 증가 증가 완료 : " << MAXHP << std::endl;
	}
	if (item[2]) { //탄약 수 2배
		rifle->D_ammo();
		pistol->D_ammo();
		item[2] = false;
		std::cout << "플레이어 탄약 수 증가 완료 : " << std::endl;
	}
	if (item[3]) { //공격력 증가
		bonus_atack = 55;
		item[3] = false;
		std::cout << "플레이어 공격력 증가 완료 : " << ATK << std::endl;
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
{	// 인자 설명 1. 좀비 리스트   2. 카메라(위치랑 바라보는 곳 받아서 광선 구하고
	int aliving = 0;		// 살아있는 좀비 수
	glm::vec3 contact = glm::vec3(1.0f);
	glm::vec3 MinVec = glm::vec3(1.0f);
	glm::vec3 MaxVec = glm::vec3(1.0f);
	glm::vec3 FinalMinVec = glm::vec3(1.0f);
	glm::vec3 FinalMaxVec = glm::vec3(1.0f);
	glm::mat4 toWorld = glm::mat4(1.0f);
	float contact_distance[MAX_ALIVE] = {0.0f}; //거리 담을 곳 
	float mindist = 0.0f;
	bool is_contact = false;
	int bonus_damage = 0;
	switch (weapon) { //내 사거리 조절
	case 나이프:
		mindist = 200.0f;
		break;
	case 권총:
		mindist = 3000.0f;
		break;
	case 라이플:
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
		if (aliving < MAX_ALIVE) {			// 최대 12마리만 필드에 나온다
			// 살았으면 머리 몸통 부위별로 확인해서 
			// update_hp()해준다.
			// 좀비 부위벌로 받아서 체크(일단은 머리만)
			MinVec = dynamic_cast<NM_zombie*>(aliveEnemy[i])->gethead()->getLB();	// <- 바운더리 박스 왼쪽 아래 점
			MaxVec = dynamic_cast<NM_zombie*>(aliveEnemy[i])->gethead()->getRT();	// <- 오른쪽 위
			toWorld = dynamic_cast<NM_zombie*>(aliveEnemy[i])->gethead()->getModelTrans();	// 모델링 변환 해줘야 월드공간 좌표 나온디.
			FinalMinVec = glm::vec3(toWorld * glm::vec4(MinVec, 1.0f)); //변환된 최종 바운더리 박스 왼쪽 아래 점
			FinalMaxVec = glm::vec3(toWorld * glm::vec4(MaxVec, 1.0f)); //변환된 최종 바운더리 박스 오른쪽 위 점

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
			// [1] YZ 평면 검사
			contact = RaytoPlaneYZ(ray_first, ray_last, min_x);
			if (min_y <= contact.y && contact.y <= max_y) {
				if (min_z <= contact.z && contact.z <= max_z) {
					yz_dist = pow(contact.x - ray_first.x, 2) + pow(contact.y - ray_first.y, 2) + pow(contact.z - ray_first.z, 2);
					contact_distance[i] = yz_dist;
					is_contact = true;
					//std::cout << i << "- YZ평면\t" << contact.x << "\t" << contact.y << "\t" << contact.z << std::endl;
				}
			}

			// [2] XZ 평면 검사
			contact = RaytoPlaneXZ(ray_first, ray_last, min_y);
			if (min_x <= contact.x && contact.x <= max_x) {
				if (min_z <= contact.z && contact.z <= max_z) {
					xz_dist = pow(contact.x - ray_first.x, 2) + pow(contact.y - ray_first.y, 2) + pow(contact.z - ray_first.z, 2);
					if (contact_distance[i] != 0.0f) {
						if (xz_dist < contact_distance[i]) {
							contact_distance[i] = xz_dist;
							is_contact = true;
							//std::cout << i << "- XZ평면\t" << contact.x << "\t" << contact.y << "\t" << contact.z << std::endl;
						}
					}
					else {
						contact_distance[i] = xz_dist;
						is_contact = true;
						//std::cout << i << "- XZ평면\t" << contact.x << "\t" << contact.y << "\t" << contact.z << std::endl;
					}
				}
			}

			// [3] XY 평면 검사
			contact = RaytoPlaneXY(ray_first, ray_last, min_z);
			if (min_x <= contact.x && contact.x <= max_x) {
				if (min_y <= contact.y && contact.y <= max_y) {
					xy_dist = pow(contact.x - ray_first.x, 2) + pow(contact.y - ray_first.y, 2) + pow(contact.z - ray_first.z, 2);
					if (contact_distance[i] != 0.0f) {
						if (xy_dist < contact_distance[i]) {
							contact_distance[i] = xy_dist;
							is_contact = true;
							//std::cout << i << "- XY평면\t" << contact.x << "\t" << contact.y << "\t" << contact.z << std::endl;
						}
					}
					else {
						contact_distance[i] = xy_dist;
						is_contact = true;
						//std::cout << i << "- XY평면\t" << contact.x << "\t" << contact.y << "\t" << contact.z << std::endl;
					}
				}
			}

			if (is_contact) {
				is_contact = false;
				++aliving;
				bonus_damage = cur_Wea->getATK();
				dynamic_cast<NM_zombie*>(aliveEnemy[i])->setHit(true);
				continue;
			}

			MinVec = dynamic_cast<NM_zombie*>(aliveEnemy[i])->getbody()->getLB();	// <- 바운더리 박스 왼쪽 아래 점
			MaxVec = dynamic_cast<NM_zombie*>(aliveEnemy[i])->getbody()->getRT();	// <- 오른쪽 위
			toWorld = dynamic_cast<NM_zombie*>(aliveEnemy[i])->getbody()->getModelTrans();	// 모델링 변환 해줘야 월드공간 좌표 나온디.
			FinalMinVec = glm::vec3(toWorld * glm::vec4(MinVec, 1.0f)); //변환된 최종 바운더리 박스 왼쪽 아래 점
			FinalMaxVec = glm::vec3(toWorld * glm::vec4(MaxVec, 1.0f)); //변환된 최종 바운더리 박스 오른쪽 위 점

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
					//std::cout << i << "- YZ평면\t" << contact.x << "\t" << contact.y << "\t" << contact.z << std::endl;
				}
			}

			// [2] XZ 평면 검사
			contact = RaytoPlaneXZ(ray_first, ray_last, min_y);
			if (min_x <= contact.x && contact.x <= max_x) {
				if (min_z <= contact.z && contact.z <= max_z) {
					xz_dist = pow(contact.x - ray_first.x, 2) + pow(contact.y - ray_first.y, 2) + pow(contact.z - ray_first.z, 2);
					if (contact_distance[i] != 0.0f) {
						if (xz_dist < contact_distance[i]) {
							contact_distance[i] = xz_dist;
							is_contact = true;
							//std::cout << i << "- XZ평면\t" << contact.x << "\t" << contact.y << "\t" << contact.z << std::endl;
						}
					}
					else {
						contact_distance[i] = xz_dist;
						is_contact = true;
						//std::cout << i << "- XZ평면\t" << contact.x << "\t" << contact.y << "\t" << contact.z << std::endl;
					}
				}
			}

			// [3] XY 평면 검사
			contact = RaytoPlaneXY(ray_first, ray_last, min_z);
			if (min_x <= contact.x && contact.x <= max_x) {
				if (min_y <= contact.y && contact.y <= max_y) {
					xy_dist = pow(contact.x - ray_first.x, 2) + pow(contact.y - ray_first.y, 2) + pow(contact.z - ray_first.z, 2);
					if (contact_distance[i] != 0.0f) {
						if (xy_dist < contact_distance[i]) {
							contact_distance[i] = xy_dist;
							is_contact = true;
							//std::cout << i << "- XY평면\t" << contact.x << "\t" << contact.y << "\t" << contact.z << std::endl;
						}
					}
					else {
						contact_distance[i] = xy_dist;
						is_contact = true;
						//std::cout << i << "- XY평면\t" << contact.x << "\t" << contact.y << "\t" << contact.z << std::endl;
					}
				}
			}

			if (is_contact) {
				is_contact = false;
				++aliving;
				bonus_damage = 0;
				continue;
			}

			MinVec = dynamic_cast<NM_zombie*>(aliveEnemy[i])->getlarm()->getLB();	// <- 바운더리 박스 왼쪽 아래 점
			MaxVec = dynamic_cast<NM_zombie*>(aliveEnemy[i])->getlarm()->getRT();	// <- 오른쪽 위
			toWorld = dynamic_cast<NM_zombie*>(aliveEnemy[i])->getlarm()->getModelTrans();	// 모델링 변환 해줘야 월드공간 좌표 나온디.
			FinalMinVec = glm::vec3(toWorld * glm::vec4(MinVec, 1.0f)); //변환된 최종 바운더리 박스 왼쪽 아래 점
			FinalMaxVec = glm::vec3(toWorld * glm::vec4(MaxVec, 1.0f)); //변환된 최종 바운더리 박스 오른쪽 위 점

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
					//std::cout << i << "- YZ평면\t" << contact.x << "\t" << contact.y << "\t" << contact.z << std::endl;
				}
			}

			// [2] XZ 평면 검사
			contact = RaytoPlaneXZ(ray_first, ray_last, min_y);
			if (min_x <= contact.x && contact.x <= max_x) {
				if (min_z <= contact.z && contact.z <= max_z) {
					xz_dist = pow(contact.x - ray_first.x, 2) + pow(contact.y - ray_first.y, 2) + pow(contact.z - ray_first.z, 2);
					if (contact_distance[i] != 0.0f) {
						if (xz_dist < contact_distance[i]) {
							contact_distance[i] = xz_dist;
							is_contact = true;
							//std::cout << i << "- XZ평면\t" << contact.x << "\t" << contact.y << "\t" << contact.z << std::endl;
						}
					}
					else {
						contact_distance[i] = xz_dist;
						is_contact = true;
						//std::cout << i << "- XZ평면\t" << contact.x << "\t" << contact.y << "\t" << contact.z << std::endl;
					}
				}
			}

			// [3] XY 평면 검사
			contact = RaytoPlaneXY(ray_first, ray_last, min_z);
			if (min_x <= contact.x && contact.x <= max_x) {
				if (min_y <= contact.y && contact.y <= max_y) {
					xy_dist = pow(contact.x - ray_first.x, 2) + pow(contact.y - ray_first.y, 2) + pow(contact.z - ray_first.z, 2);
					if (contact_distance[i] != 0.0f) {
						if (xy_dist < contact_distance[i]) {
							contact_distance[i] = xy_dist;
							is_contact = true;
							//std::cout << i << "- XY평면\t" << contact.x << "\t" << contact.y << "\t" << contact.z << std::endl;
						}
					}
					else {
						contact_distance[i] = xy_dist;
						is_contact = true;
						//std::cout << i << "- XY평면\t" << contact.x << "\t" << contact.y << "\t" << contact.z << std::endl;
					}
				}
			}

			if (is_contact) {
				is_contact = false;
				++aliving;
				bonus_damage = 0;
				continue;
			}

			MinVec = dynamic_cast<NM_zombie*>(aliveEnemy[i])->getrarm()->getLB();	// <- 바운더리 박스 왼쪽 아래 점
			MaxVec = dynamic_cast<NM_zombie*>(aliveEnemy[i])->getrarm()->getRT();	// <- 오른쪽 위
			toWorld = dynamic_cast<NM_zombie*>(aliveEnemy[i])->getrarm()->getModelTrans();	// 모델링 변환 해줘야 월드공간 좌표 나온디.
			FinalMinVec = glm::vec3(toWorld * glm::vec4(MinVec, 1.0f)); //변환된 최종 바운더리 박스 왼쪽 아래 점
			FinalMaxVec = glm::vec3(toWorld * glm::vec4(MaxVec, 1.0f)); //변환된 최종 바운더리 박스 오른쪽 위 점

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
					//std::cout << i << "- YZ평면\t" << contact.x << "\t" << contact.y << "\t" << contact.z << std::endl;
				}
			}

			// [2] XZ 평면 검사
			contact = RaytoPlaneXZ(ray_first, ray_last, min_y);
			if (min_x <= contact.x && contact.x <= max_x) {
				if (min_z <= contact.z && contact.z <= max_z) {
					xz_dist = pow(contact.x - ray_first.x, 2) + pow(contact.y - ray_first.y, 2) + pow(contact.z - ray_first.z, 2);
					if (contact_distance[i] != 0.0f) {
						if (xz_dist < contact_distance[i]) {
							contact_distance[i] = xz_dist;
							is_contact = true;
							//std::cout << i << "- XZ평면\t" << contact.x << "\t" << contact.y << "\t" << contact.z << std::endl;
						}
					}
					else {
						contact_distance[i] = xz_dist;
						is_contact = true;
						//std::cout << i << "- XZ평면\t" << contact.x << "\t" << contact.y << "\t" << contact.z << std::endl;
					}
				}
			}

			// [3] XY 평면 검사
			contact = RaytoPlaneXY(ray_first, ray_last, min_z);
			if (min_x <= contact.x && contact.x <= max_x) {
				if (min_y <= contact.y && contact.y <= max_y) {
					xy_dist = pow(contact.x - ray_first.x, 2) + pow(contact.y - ray_first.y, 2) + pow(contact.z - ray_first.z, 2);
					if (contact_distance[i] != 0.0f) {
						if (xy_dist < contact_distance[i]) {
							contact_distance[i] = xy_dist;
							is_contact = true;
							//std::cout << i << "- XY평면\t" << contact.x << "\t" << contact.y << "\t" << contact.z << std::endl;
						}
					}
					else {
						contact_distance[i] = xy_dist;
						is_contact = true;
						//std::cout << i << "- XY평면\t" << contact.x << "\t" << contact.y << "\t" << contact.z << std::endl;
					}
				}
			}

			if (is_contact) {
				is_contact = false;
				++aliving;
				bonus_damage = 0;
				continue;
			}

			MinVec = dynamic_cast<NM_zombie*>(aliveEnemy[i])->getlleg()->getLB();	// <- 바운더리 박스 왼쪽 아래 점
			MaxVec = dynamic_cast<NM_zombie*>(aliveEnemy[i])->getlleg()->getRT();	// <- 오른쪽 위
			toWorld = dynamic_cast<NM_zombie*>(aliveEnemy[i])->getlleg()->getModelTrans();	// 모델링 변환 해줘야 월드공간 좌표 나온디.
			FinalMinVec = glm::vec3(toWorld * glm::vec4(MinVec, 1.0f)); //변환된 최종 바운더리 박스 왼쪽 아래 점
			FinalMaxVec = glm::vec3(toWorld * glm::vec4(MaxVec, 1.0f)); //변환된 최종 바운더리 박스 오른쪽 위 점

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
					//std::cout << i << "- YZ평면\t" << contact.x << "\t" << contact.y << "\t" << contact.z << std::endl;
				}
			}

			// [2] XZ 평면 검사
			contact = RaytoPlaneXZ(ray_first, ray_last, min_y);
			if (min_x <= contact.x && contact.x <= max_x) {
				if (min_z <= contact.z && contact.z <= max_z) {
					xz_dist = pow(contact.x - ray_first.x, 2) + pow(contact.y - ray_first.y, 2) + pow(contact.z - ray_first.z, 2);
					if (contact_distance[i] != 0.0f) {
						if (xz_dist < contact_distance[i]) {
							contact_distance[i] = xz_dist;
							is_contact = true;
							//std::cout << i << "- XZ평면\t" << contact.x << "\t" << contact.y << "\t" << contact.z << std::endl;
						}
					}
					else {
						contact_distance[i] = xz_dist;
						is_contact = true;
						//std::cout << i << "- XZ평면\t" << contact.x << "\t" << contact.y << "\t" << contact.z << std::endl;
					}
				}
			}

			// [3] XY 평면 검사
			contact = RaytoPlaneXY(ray_first, ray_last, min_z);
			if (min_x <= contact.x && contact.x <= max_x) {
				if (min_y <= contact.y && contact.y <= max_y) {
					xy_dist = pow(contact.x - ray_first.x, 2) + pow(contact.y - ray_first.y, 2) + pow(contact.z - ray_first.z, 2);
					if (contact_distance[i] != 0.0f) {
						if (xy_dist < contact_distance[i]) {
							contact_distance[i] = xy_dist;
							is_contact = true;
							//std::cout << i << "- XY평면\t" << contact.x << "\t" << contact.y << "\t" << contact.z << std::endl;
						}
					}
					else {
						contact_distance[i] = xy_dist;
						is_contact = true;
						//std::cout << i << "- XY평면\t" << contact.x << "\t" << contact.y << "\t" << contact.z << std::endl;
					}
				}
			}

			if (is_contact) {
				is_contact = false;
				++aliving;
				bonus_damage = 0;
				continue;
			}

			MinVec = dynamic_cast<NM_zombie*>(aliveEnemy[i])->getrleg()->getLB();	// <- 바운더리 박스 왼쪽 아래 점
			MaxVec = dynamic_cast<NM_zombie*>(aliveEnemy[i])->getrleg()->getRT();	// <- 오른쪽 위
			toWorld = dynamic_cast<NM_zombie*>(aliveEnemy[i])->getrleg()->getModelTrans();	// 모델링 변환 해줘야 월드공간 좌표 나온디.
			FinalMinVec = glm::vec3(toWorld * glm::vec4(MinVec, 1.0f)); //변환된 최종 바운더리 박스 왼쪽 아래 점
			FinalMaxVec = glm::vec3(toWorld * glm::vec4(MaxVec, 1.0f)); //변환된 최종 바운더리 박스 오른쪽 위 점

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
					//std::cout << i << "- YZ평면\t" << contact.x << "\t" << contact.y << "\t" << contact.z << std::endl;
				}
			}

			// [2] XZ 평면 검사
			contact = RaytoPlaneXZ(ray_first, ray_last, min_y);
			if (min_x <= contact.x && contact.x <= max_x) {
				if (min_z <= contact.z && contact.z <= max_z) {
					xz_dist = pow(contact.x - ray_first.x, 2) + pow(contact.y - ray_first.y, 2) + pow(contact.z - ray_first.z, 2);
					if (contact_distance[i] != 0.0f) {
						if (xz_dist < contact_distance[i]) {
							contact_distance[i] = xz_dist;
							is_contact = true;
							//std::cout << i << "- XZ평면\t" << contact.x << "\t" << contact.y << "\t" << contact.z << std::endl;
						}
					}
					else {
						contact_distance[i] = xz_dist;
						is_contact = true;
						//std::cout << i << "- XZ평면\t" << contact.x << "\t" << contact.y << "\t" << contact.z << std::endl;
					}
				}
			}

			// [3] XY 평면 검사
			contact = RaytoPlaneXY(ray_first, ray_last, min_z);
			if (min_x <= contact.x && contact.x <= max_x) {
				if (min_y <= contact.y && contact.y <= max_y) {
					xy_dist = pow(contact.x - ray_first.x, 2) + pow(contact.y - ray_first.y, 2) + pow(contact.z - ray_first.z, 2);
					if (contact_distance[i] != 0.0f) {
						if (xy_dist < contact_distance[i]) {
							contact_distance[i] = xy_dist;
							is_contact = true;
							//std::cout << i << "- XY평면\t" << contact.x << "\t" << contact.y << "\t" << contact.z << std::endl;
						}
					}
					else {
						contact_distance[i] = xy_dist;
						is_contact = true;
						//std::cout << i << "- XY평면\t" << contact.x << "\t" << contact.y << "\t" << contact.z << std::endl;
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
	for (int i = 0;i < alive;i++) { //가장 가까운 좀비 찾기
		if (contact_distance[i] != 0.0f) {
			if (mindist > contact_distance[i]) {
				mindist = contact_distance[i];
				whoisfirst = i;
			}
		}
	}
	if (whoisfirst != -1) {
		aliveEnemy[whoisfirst]->Update_HP(-(ATK + bonus_damage)); //공격력만큼 감소
		//std::cout << whoisfirst << "\t-\t" << aliveEnemy[whoisfirst]->getHP() << std::endl;
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