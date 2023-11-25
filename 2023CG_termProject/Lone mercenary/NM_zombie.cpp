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

	body = new NM_Mesh("test_obj\\test_character.obj");
	body->init_rotate(90, 0, 1, 0);
	
}

NM_zombie::NM_zombie(float hp, float max, float spd, float def, float atk)
	: EnemyBase(hp, max, spd, def, atk)
{

	cur_loc = glm::vec3(0.0f);
	cur_rot = glm::vec3(0.0f);

	body = new NM_Mesh("test_obj\\test_character.obj");
	body->init_scale(0.15);
	body->init_rotate(90, 0, 1, 0);
	body->init_position(0, 5, 0);
}

NM_zombie::~NM_zombie()
{
	if (nullptr != body) {
		delete body;
		body = nullptr;
	}
	/*if (nullptr != leg[0]) {
		delete leg[0];
		leg[0] = nullptr;
	}
	if (nullptr != leg[1]) {
		delete leg[1];
		leg[1] = nullptr;
	}*/
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

	body->setLoc(cur_loc);
	body->setRot(cur_rot);
}

void NM_zombie::Render() const
{
	body->Render();
}