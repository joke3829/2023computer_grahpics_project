#include "NM_zombie.h"
#include "Mesh.h"
#include "Player.h"
#include "Field.h"
#include "GameTimer.h"

NM_zombie::NM_zombie() : EnemyBase() {
	HP = 0;
	MAXHP = 0;
	speed = 0;
	DEF = 0;
	ATK = 0;

	cur_loc = glm::vec3(0.0f);
	cur_rot = glm::vec2(0.0f);

	head = new NM_Mesh("obj_source\\zombie\\NM_zombie\\NM_zombie_head.obj", "obj_source\\zombie\\NM_zombie\\head_colorBase_test.jpg", 1024, 1024);
	body = new NM_Mesh("obj_source\\zombie\\NM_zombie\\NM_zombie_body.obj", "obj_source\\zombie\\NM_zombie\\body_colorBase_test.jpg", 1024, 1024);
	arm[0] = new NM_Mesh("obj_source\\zombie\\NM_zombie\\NM_zombie_leftarm.obj", "obj_source\\zombie\\NM_zombie\\leftarm_colorBase_test.jpg", 1024, 1024);
	arm[1] = new NM_Mesh("obj_source\\zombie\\NM_zombie\\NM_zombie_rightarm.obj", "obj_source\\zombie\\NM_zombie\\rightarm_colorBase_test.jpg", 1024, 1024);
	leg[0] = new NM_Mesh("obj_source\\zombie\\NM_zombie\\NM_zombie_leftleg.obj", "obj_source\\zombie\\NM_zombie\\leftleg_colorBase_test.jpg", 1024, 1024);
	leg[1] = new NM_Mesh("obj_source\\zombie\\NM_zombie\\NM_zombie_rightleg.obj", "obj_source\\zombie\\NM_zombie\\rightleg_colorBase_test.jpg", 1024, 1024);
	
	head->init_scale(0.15);
	body->init_scale(0.15);
	arm[0]->init_scale(0.15);
	arm[1]->init_scale(0.15);
	leg[0]->init_scale(0.15);
	leg[1]->init_scale(0.15);

	head->init_rotate(90, 0, 1, 0);
	body->init_rotate(90, 0, 1, 0);
	arm[0]->init_rotate(90, 0, 1, 0);
	arm[1]->init_rotate(90, 0, 1, 0);
	leg[0]->init_rotate(90, 0, 1, 0);
	leg[1]->init_rotate(90, 0, 1, 0);

	head->init_position(0, 10, 0);
	body->init_position(-0.1, 7, 0);
	arm[0]->init_position(1.73, 8.4, -1.2);
	arm[1]->init_position(1.45, 8.4, 1.2);
	leg[0]->init_position(-0.02, 3, -0.5);
	leg[1]->init_position(-0.02, 3, 0.5);
}

NM_zombie::NM_zombie(float hp, float max, float spd, float def, float atk, int type)
	: EnemyBase(hp, max, spd, def, atk)
{
	hithead = false;
	start_time = clock();
	std::random_device rd;
	std::default_random_engine dre(rd());
	std::uniform_int_distribution<int> uid(1, 4);

	std::uniform_int_distribution<int> z_rnd(-30, 30);
	z_type = type;
	switch (uid(dre)) {
	case 1:
		cur_loc = glm::vec3(100, 0, z_rnd(dre));
		break;
	case 2:
		cur_loc = glm::vec3(z_rnd(dre), 0, 100);
		break;
	case 3:
		cur_loc = glm::vec3(-100, 0, z_rnd(dre));
		break;
	case 4:
		cur_loc = glm::vec3(z_rnd(dre), 0, -100);
		break;
	}
	cur_rot = glm::vec3(0.0f);

	switch (z_type) {
	case ÀÏ¹Ý:
		head = new NM_Mesh("obj_source\\zombie\\NM_zombie\\NM_zombie_head.obj", "obj_source\\zombie\\NM_zombie\\head_colorBase_test.png", 1024, 1024);
		body = new NM_Mesh("obj_source\\zombie\\NM_zombie\\NM_zombie_body.obj", "obj_source\\zombie\\NM_zombie\\body_colorBase_test.png", 1024, 1024);
		arm[0] = new NM_Mesh("obj_source\\zombie\\NM_zombie\\NM_zombie_leftarm.obj", "obj_source\\zombie\\NM_zombie\\leftarm_colorBase_test.png", 1024, 1024);
		arm[1] = new NM_Mesh("obj_source\\zombie\\NM_zombie\\NM_zombie_rightarm.obj", "obj_source\\zombie\\NM_zombie\\rightarm_colorBase_test.png", 1024, 1024);
		leg[0] = new NM_Mesh("obj_source\\zombie\\NM_zombie\\NM_zombie_leftleg.obj", "obj_source\\zombie\\NM_zombie\\leftleg_colorBase_test.png", 1024, 1024);
		leg[1] = new NM_Mesh("obj_source\\zombie\\NM_zombie\\NM_zombie_rightleg.obj", "obj_source\\zombie\\NM_zombie\\rightleg_colorBase_test.png", 1024, 1024);
		break;
	case Èú·¯:
		head = new NM_Mesh("obj_source\\zombie\\NM_zombie\\NM_zombie_head.obj", "obj_source\\zombie\\NM_zombie\\heal_z_head.png", 1024, 1024);
		body = new NM_Mesh("obj_source\\zombie\\NM_zombie\\NM_zombie_body.obj", "obj_source\\zombie\\NM_zombie\\heal_z_body.png", 1024, 1024);
		arm[0] = new NM_Mesh("obj_source\\zombie\\NM_zombie\\NM_zombie_leftarm.obj", "obj_source\\zombie\\NM_zombie\\heal_z_leftarm.png", 1024, 1024);
		arm[1] = new NM_Mesh("obj_source\\zombie\\NM_zombie\\NM_zombie_rightarm.obj", "obj_source\\zombie\\NM_zombie\\heal_z_rightarm.png", 1024, 1024);
		leg[0] = new NM_Mesh("obj_source\\zombie\\NM_zombie\\NM_zombie_leftleg.obj", "obj_source\\zombie\\NM_zombie\\heal_z_leftleg.png", 1024, 1024);
		leg[1] = new NM_Mesh("obj_source\\zombie\\NM_zombie\\NM_zombie_rightleg.obj", "obj_source\\zombie\\NM_zombie\\heal_z_rightleg.png", 1024, 1024);
		break;
	case Æø¹ß:
		head = new NM_Mesh("obj_source\\zombie\\NM_zombie\\NM_zombie_head.obj", "obj_source\\zombie\\NM_zombie\\bomb_zombie.png", 1024, 1024);
		body = new NM_Mesh("obj_source\\zombie\\NM_zombie\\NM_zombie_body.obj", "obj_source\\zombie\\NM_zombie\\bomb_zombie.png", 1024, 1024);
		arm[0] = new NM_Mesh("obj_source\\zombie\\NM_zombie\\NM_zombie_leftarm.obj", "obj_source\\zombie\\NM_zombie\\bomb_zombie.png", 1024, 1024);
		arm[1] = new NM_Mesh("obj_source\\zombie\\NM_zombie\\NM_zombie_rightarm.obj", "obj_source\\zombie\\NM_zombie\\bomb_zombie.png", 1024, 1024);
		leg[0] = new NM_Mesh("obj_source\\zombie\\NM_zombie\\NM_zombie_leftleg.obj", "obj_source\\zombie\\NM_zombie\\bomb_zombie.png", 1024, 1024);
		leg[1] = new NM_Mesh("obj_source\\zombie\\NM_zombie\\NM_zombie_rightleg.obj", "obj_source\\zombie\\NM_zombie\\bomb_zombie.png", 1024, 1024);
		break;
	}
	head->init_scale(0.15);
	body->init_scale(0.15);
	arm[0]->init_scale(0.15);
	arm[1]->init_scale(0.15);
	leg[0]->init_scale(0.15);
	leg[1]->init_scale(0.15);

	head->init_rotate(90, 0, 1, 0);
	body->init_rotate(90, 0, 1, 0);
	arm[0]->init_rotate(90, 0, 1, 0);
	arm[1]->init_rotate(90, 0, 1, 0);
	leg[0]->init_rotate(90, 0, 1, 0);
	leg[1]->init_rotate(90, 0, 1, 0);

	head->init_position(0, 10, 0);
	body->init_position(-0.1, 7, 0);
	arm[0]->init_position(1.73, 8.4, -1.2);
	arm[1]->init_position(1.45, 8.4, 1.2);
	leg[0]->init_position(-0.02, 3, -0.5);
	leg[1]->init_position(-0.02, 3, 0.5);

	head->setLoc(cur_loc);
	head->setRot(cur_rot);
	body->setLoc(cur_loc);
	body->setRot(cur_rot);
	arm[0]->setLoc(cur_loc);
	arm[0]->setRot(cur_rot);
	arm[1]->setLoc(cur_loc);
	arm[1]->setRot(cur_rot);
	leg[0]->setLoc(cur_loc);
	leg[0]->setRot(cur_rot);
	leg[1]->setLoc(cur_loc);
	leg[1]->setRot(cur_rot);
}

NM_zombie::~NM_zombie()
{
	if (nullptr != head) {
		delete head;
		head = nullptr;
	}
	if (nullptr != body) {
		delete body;
		body = nullptr;
	}
	if (nullptr != arm[0]) {
		delete arm[0];
		arm[0] = nullptr;
	}
	if (nullptr != arm[1]) {
		delete arm[1];
		arm[1] = nullptr;
	}
	if (nullptr != leg[0]) {
		delete leg[0];
		leg[0] = nullptr;
	}
	if (nullptr != leg[1]) {
		delete leg[1];
		leg[1] = nullptr;
	}
}

void NM_zombie::walk_ani(int n)
{
	glm::vec3 z_pos = glm::vec3(cur_loc.x, 0, cur_loc.z);
	glm::vec3 p_pos = glm::vec3(dynamic_cast<Player*>(mPlayer)->getLoc().x, 0, dynamic_cast<Player*>(mPlayer)->getLoc().z);

	float slope;

	if (z_pos.x == p_pos.x) {
		slope = (z_pos.z - p_pos.z) / (z_pos.x - (p_pos.x + 0.0000000001));
	}
	else
		slope = (z_pos.z - p_pos.z) / (z_pos.x - p_pos.x);

	float angle = glm::atan(slope);
	float degree = angle * 180 / glm::pi<float>();

	if (z_pos.x > p_pos.x)
		degree += 180;


	cur_rot.x = degree;
	glm::vec3 way = glm::normalize(glm::vec3(glm::cos(glm::radians(cur_rot.x)), 0, glm::sin(glm::radians(cur_rot.x))));
	if (n == 0)
		cur_loc += (speed * way) / 60.0f;
	else
		cur_loc -= (speed * way) / 60.0f;
	if(glm::distance(cur_loc, p_pos) < 3)
		cur_loc -= (speed * way) / 60.0f;

	head->setLoc(cur_loc);
	head->setRot(cur_rot);
	body->setLoc(cur_loc);
	body->setRot(cur_rot);
	arm[0]->setLoc(cur_loc);
	arm[0]->setRot(cur_rot);
	arm[1]->setLoc(cur_loc);
	arm[1]->setRot(cur_rot);
	leg[0]->setLoc(cur_loc);
	leg[0]->setRot(cur_rot);
	leg[1]->setLoc(cur_loc);
	leg[1]->setRot(cur_rot);
}

void NM_zombie::Render() const
{
	head->Render();
	body->Render();
	arm[0]->Render();
	arm[1]->Render();
	leg[0]->Render();
	leg[1]->Render();
}

void NM_zombie::z_heal(std::vector<EnemyBase*>& temp_list)
{
	if (Èú·¯ == z_type && not Death_check()) {
		h_current_time = clock();
		double dd = (h_current_time - h_start_time) / CLOCKS_PER_SEC;
		if (dd > 10.0) {
			mSound->play_zom(Èú·¯);
			int aliving{};
			for (int i = Field::first_zom; i < temp_list.size(); ++i) {
				if (temp_list.size() > aliving && aliving < MAX_ALIVE) {
					if (not temp_list[i]->Death_check()) {
						if (glm::distance(cur_loc, temp_list[i]->getLoc()) < 40) {
							temp_list[i]->Update_HP(100);
							//std::cout << i << "\t-\t" << temp_list[i]->getHP() << std::endl;
						}
						++aliving;
					}
				}
				else
					break;
			}
			h_start_time = clock();
		}
	}
}

void NM_zombie::z_boom()
{
	if (Æø¹ß == z_type && not Death_check()) {
		h_current_time = clock();
		double dd = (h_current_time - h_start_time) / CLOCKS_PER_SEC;
		if (dd > 10.0) {
			mSound->play_zom(Æø¹ß);
			glm::vec3 p_loc = glm::vec3(dynamic_cast<Player*>(mPlayer)->getLoc().x, 0, dynamic_cast<Player*>(mPlayer)->getLoc().z);
			if (glm::distance(p_loc, cur_loc) < 29) {
				mPlayer->Update_HP(-45);
			}
			h_start_time = clock();
		}
	}
}


NM_Mesh* NM_zombie::gethead()
{
	return head;
}

NM_Mesh* NM_zombie::getbody()
{
	return body;
}

NM_Mesh* NM_zombie::getlarm()
{
	return arm[0];
}

NM_Mesh* NM_zombie::getrarm()
{
	return arm[1];
}

NM_Mesh* NM_zombie::getlleg()
{
	return leg[0];
}

NM_Mesh* NM_zombie::getrleg()
{
	return leg[1];
}

void NM_zombie::setHit(bool n)
{
	hithead = n;
}

bool NM_zombie::Death_check()
{
	if (HP <= 0) {
		if (hithead){
			GameTimer::remaining_time += 10;
			hithead = false;
		}
		return true;
	}

	hithead = false;
	return false;
}