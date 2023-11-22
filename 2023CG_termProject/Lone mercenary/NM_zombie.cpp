#include "NM_zombie.h"
#include "Mesh.h"

NM_zombie::NM_zombie() : CharacterBase() {
	HP = 0;
	MAXHP = 0;
	speed = 0;
	DEF = 0;
	ATK = 0;

	cur_loc = glm::vec3(0.0f);
	cur_rot = glm::vec3(0.0f);

	body = new Mesh("상체");
	leg[0] = new Mesh("왼다리");
	leg[1] = new Mesh("오른다리");

	
}

NM_zombie::NM_zombie(float hp, float max, float spd, float def, float atk)
	: CharacterBase(hp, max, spd, def, atk)
{

	cur_loc = glm::vec3(0.0f);
	cur_rot = glm::vec3(0.0f);

	body = new Mesh("상체");
	leg[0] = new Mesh("왼다리");
	leg[1] = new Mesh("오른다리");
}

NM_zombie::~NM_zombie()
{
	if (nullptr != body) {
		delete body;
		body = nullptr;
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

void NM_zombie::Render() const
{
	body->Render();
	leg[0]->Render();
	leg[1]->Render();
}