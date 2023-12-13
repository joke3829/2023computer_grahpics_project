#include "Timeplus.h"

Timerplus::Timerplus(CharacterBase* t_p, GameTimer* t_t, glm::vec3 t_loc)
	: mPlayer(t_p), timer(t_t), cur_loc(t_loc)
{
	obj = new Mesh("obj_source\\Wall_Clock.obj", "obj_source\\temp_texture.png", 1024, 1024);
	obj->init_scale(0.01);
	obj->init_rotate(-90, 1, 0, 0);
	obj->init_position(0, 8, 0);
	obj->setLoc(cur_loc);
	cur_rot = glm::vec2(0.0f);
	exist = true;
}

Timerplus::~Timerplus()
{
	delete obj;
}

void Timerplus::Render()
{
	if(exist)
		obj->Render();
}

void Timerplus::check_collision()
{
	if (exist) {
		if (glm::distance(glm::vec3(dynamic_cast<Player*>(mPlayer)->getLoc().x, 0, dynamic_cast<Player*>(mPlayer)->getLoc().z), cur_loc) < 5) {
			exist = false;
			timer->plus_time(20);
		}
	}
}

void Timerplus::rot_ani()
{
	if (exist) {
		cur_rot.x += 20.0f / 60.0f;
		if (cur_rot.x >= 360)
			cur_rot.x -= 360;
		obj->setRot(cur_rot);
	}
}