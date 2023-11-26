#include "NM_zombie.h"
#include "Mesh.h"

NM_zombie::NM_zombie() : EnemyBase() {
	HP = 0;
	MAXHP = 0;
	speed = 0;
	DEF = 0;
	ATK = 0;

	cur_loc = glm::vec3(0.0f);
	cur_rot = glm::vec2(0.0f);

	head = new NM_Mesh("test_obj\\zombie\\NM_zombie_head.obj");
	body = new NM_Mesh("test_obj\\zombie\\NM_zombie_body.obj");
	arm[0] = new NM_Mesh("test_obj\\zombie\\NM_zombie_leftarm.obj");
	arm[1] = new NM_Mesh("test_obj\\zombie\\NM_zombie_rightarm.obj");
	leg[0] = new NM_Mesh("test_obj\\zombie\\NM_zombie_leftleg.obj");
	leg[1] = new NM_Mesh("test_obj\\zombie\\NM_zombie_rightleg.obj");
	
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

NM_zombie::NM_zombie(float hp, float max, float spd, float def, float atk)
	: EnemyBase(hp, max, spd, def, atk)
{

	cur_loc = glm::vec3(0.0f);
	cur_rot = glm::vec3(0.0f);

	head = new NM_Mesh("test_obj\\zombie\\NM_zombie_head.obj");
	body = new NM_Mesh("test_obj\\zombie\\NM_zombie_body.obj");
	arm[0] = new NM_Mesh("test_obj\\zombie\\NM_zombie_leftarm.obj");
	arm[1] = new NM_Mesh("test_obj\\zombie\\NM_zombie_rightarm.obj");
	leg[0] = new NM_Mesh("test_obj\\zombie\\NM_zombie_leftleg.obj");
	leg[1] = new NM_Mesh("test_obj\\zombie\\NM_zombie_rightleg.obj");

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

void NM_zombie::walk_ani()
{
	glm::vec3 z_pos = glm::vec3(cur_loc.x, 0, cur_loc.z);
	glm::vec3 p_pos = glm::vec3(p_loc.x, 0, p_loc.z);

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
	cur_loc += (speed * way) / 60.0f;
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