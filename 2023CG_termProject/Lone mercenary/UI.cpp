#include "UI.h"

int UI::h100 = 0; int UI::h10 = 0; int UI::h1 = 0;
int UI::c1 = 0; int UI::c10 = 0;
int UI::r100 = 0; int UI::r10 = 0; int UI::r1 = 0;

UI::UI(CharacterBase* t_pl, GameTimer* t_time)
	:mPlayer(t_pl), timer(t_time)
{
	hp_back = new Mesh("obj_source\\ui\\hp\\back.obj", "obj_source\\ui\\hp\\back.png", 1024, 1024);
	hp_back->init_scale(0.004);
	hp_back->init_rotate(-90, 0, 1, 0);
	hp_back->init_position(0.5, -0.19, -0.29);

	hp_100 = new Mesh("obj_source\\number\\number.obj", "obj_source\\number\\number_0.png", 1024, 1024);
	hp_100->init_scale(0.0007);
	hp_100->init_rotate(-90, 0, 1, 0);
	hp_100->init_position(0.3, -0.105, -0.19);
	hp_10 = new Mesh("obj_source\\number\\number.obj", "obj_source\\number\\number_0.png", 1024, 1024);
	hp_10->init_scale(0.0007);
	hp_10->init_rotate(-90, 0, 1, 0);
	hp_10->init_position(0.3, -0.105, -0.17);
	hp_1 = new Mesh("obj_source\\number\\number.obj", "obj_source\\number\\number_0.png", 1024, 1024);
	hp_1->init_scale(0.0007);
	hp_1->init_rotate(-90, 0, 1, 0);
	hp_1->init_position(0.3, -0.105, -0.15);

	h100 = h10 = h1 = 0;

	bullet_back = new Mesh("obj_source\\ui\\hp\\back.obj", "obj_source\\ui\\hp\\back.png", 1024, 1024);
	bullet_back->init_scale(0.004);
	bullet_back->init_rotate(-90, 0, 1, 0);
	bullet_back->init_position(0.5, -0.19, 0.29);

	cur_b_10 = new Mesh("obj_source\\number\\number.obj", "obj_source\\number\\number_0.png", 1024, 1024);
	cur_b_10->init_scale(0.0007);
	cur_b_10->init_rotate(-90, 0, 1, 0);
	cur_b_10->init_position(0.3, -0.105, 0.11);
	cur_b_1 = new Mesh("obj_source\\number\\number.obj", "obj_source\\number\\number_0.png", 1024, 1024);
	cur_b_1->init_scale(0.0007);
	cur_b_1->init_rotate(-90, 0, 1, 0);
	cur_b_1->init_position(0.3, -0.105, 0.13);
	cur_b_sl = new Mesh("obj_source\\number\\number.obj", "obj_source\\number\\number_slash.png", 1024, 1024);
	cur_b_sl->init_scale(0.0007);
	cur_b_sl->init_rotate(-90, 0, 1, 0);
	cur_b_sl->init_position(0.3, -0.105, 0.15);
	r_b_100 = new Mesh("obj_source\\number\\number.obj", "obj_source\\number\\number_0.png", 1024, 1024);
	r_b_100->init_scale(0.0007);
	r_b_100->init_rotate(-90, 0, 1, 0);
	r_b_100->init_position(0.3, -0.105, 0.17);
	r_b_10 = new Mesh("obj_source\\number\\number.obj", "obj_source\\number\\number_0.png", 1024, 1024);
	r_b_10->init_scale(0.0007);
	r_b_10->init_rotate(-90, 0, 1, 0);
	r_b_10->init_position(0.3, -0.105, 0.19);
	r_b_1 = new Mesh("obj_source\\number\\number.obj", "obj_source\\number\\number_0.png", 1024, 1024);
	r_b_1->init_scale(0.0007);
	r_b_1->init_rotate(-90, 0, 1, 0);
	r_b_1->init_position(0.3, -0.105, 0.21);

	c10 = c1 = r100 = r10 = r1 = 0;

	crossline = new Mesh("obj_source\\ui\\crossline.obj", "obj_source\\ui\\crossline.png", 1024, 1024);
	crossline->init_scale(0.001);
	crossline->init_rotate(-90, 0, 1, 0);
	crossline->init_position(0.3, 0, 0);

	hp_back->setAmb(1.0);
	hp_100->setAmb(1.0);
	hp_10->setAmb(1.0);
	hp_1->setAmb(1.0);

	bullet_back->setAmb(1.0);
	cur_b_10->setAmb(1.0f);
	cur_b_1->setAmb(1.0f);
	cur_b_sl->setAmb(1.0f);
	r_b_100->setAmb(1.0f);
	r_b_10->setAmb(1.0f);
	r_b_1->setAmb(1.0f);

	crossline->setAmb(1.0f);
}

UI::~UI()
{
	delete hp_back;
	delete hp_100;
	delete hp_10;
	delete hp_1;

	delete bullet_back;
	delete cur_b_10;
	delete cur_b_1;
	delete cur_b_sl;
	delete r_b_100;
	delete r_b_10;
	delete r_b_1;

	delete crossline;
}

void UI::Update()
{
	//============================================================
	hp_back->setLoc(dynamic_cast<Player*>(mPlayer)->getLoc());
	hp_back->setRot(dynamic_cast<Player*>(mPlayer)->getRot());

	hp_100->setLoc(dynamic_cast<Player*>(mPlayer)->getLoc());
	hp_100->setRot(dynamic_cast<Player*>(mPlayer)->getRot());
	hp_10->setLoc(dynamic_cast<Player*>(mPlayer)->getLoc());
	hp_10->setRot(dynamic_cast<Player*>(mPlayer)->getRot());
	hp_1->setLoc(dynamic_cast<Player*>(mPlayer)->getLoc());
	hp_1->setRot(dynamic_cast<Player*>(mPlayer)->getRot());

	int php =mPlayer->getHP();
	if (php / 100 != h100) {
		switch (php / 100) {
		case 0:
			hp_100->change_texture("obj_source\\number\\number_0.png", 1024, 1024);
			break;
		case 1:
			hp_100->change_texture("obj_source\\number\\number_1.png", 1024, 1024);
			break;
		case 2:
			hp_100->change_texture("obj_source\\number\\number_2.png", 1024, 1024);
			break;
		case 3:
			hp_100->change_texture("obj_source\\number\\number_3.png", 1024, 1024);
			break;
		case 4:
			hp_100->change_texture("obj_source\\number\\number_4.png", 1024, 1024);
			break;
		case 5:
			hp_100->change_texture("obj_source\\number\\number_5.png", 1024, 1024);
			break;
		case 6:
			hp_100->change_texture("obj_source\\number\\number_6.png", 1024, 1024);
			break;
		case 7:
			hp_100->change_texture("obj_source\\number\\number_7.png", 1024, 1024);
			break;
		case 8:
			hp_100->change_texture("obj_source\\number\\number_8.png", 1024, 1024);
			break;
		case 9:
			hp_100->change_texture("obj_source\\number\\number_9.png", 1024, 1024);
			break;
		}
		h100 = php / 100;
	}
	php -= (h100 * 100);
	if (php / 10 != h10) {
		switch (php / 10) {
		case 0:
			hp_10->change_texture("obj_source\\number\\number_0.png", 1024, 1024);
			break;
		case 1:
			hp_10->change_texture("obj_source\\number\\number_1.png", 1024, 1024);
			break;
		case 2:
			hp_10->change_texture("obj_source\\number\\number_2.png", 1024, 1024);
			break;
		case 3:
			hp_10->change_texture("obj_source\\number\\number_3.png", 1024, 1024);
			break;
		case 4:
			hp_10->change_texture("obj_source\\number\\number_4.png", 1024, 1024);
			break;
		case 5:
			hp_10->change_texture("obj_source\\number\\number_5.png", 1024, 1024);
			break;
		case 6:
			hp_10->change_texture("obj_source\\number\\number_6.png", 1024, 1024);
			break;
		case 7:
			hp_10->change_texture("obj_source\\number\\number_7.png", 1024, 1024);
			break;
		case 8:
			hp_10->change_texture("obj_source\\number\\number_8.png", 1024, 1024);
			break;
		case 9:
			hp_10->change_texture("obj_source\\number\\number_9.png", 1024, 1024);
			break;
		}
		h10 = php / 10;
	}
	php -= (h10 * 10);
	if (php != h1) {
		switch (php) {
		case 0:
			hp_1->change_texture("obj_source\\number\\number_0.png", 1024, 1024);
			break;
		case 1:
			hp_1->change_texture("obj_source\\number\\number_1.png", 1024, 1024);
			break;
		case 2:
			hp_1->change_texture("obj_source\\number\\number_2.png", 1024, 1024);
			break;
		case 3:
			hp_1->change_texture("obj_source\\number\\number_3.png", 1024, 1024);
			break;
		case 4:
			hp_1->change_texture("obj_source\\number\\number_4.png", 1024, 1024);
			break;
		case 5:
			hp_1->change_texture("obj_source\\number\\number_5.png", 1024, 1024);
			break;
		case 6:
			hp_1->change_texture("obj_source\\number\\number_6.png", 1024, 1024);
			break;
		case 7:
			hp_1->change_texture("obj_source\\number\\number_7.png", 1024, 1024);
			break;
		case 8:
			hp_1->change_texture("obj_source\\number\\number_8.png", 1024, 1024);
			break;
		case 9:
			hp_1->change_texture("obj_source\\number\\number_9.png", 1024, 1024);
			break;
		}
		h1 = php;
	}

	//============================================================
	bullet_back->setLoc(dynamic_cast<Player*>(mPlayer)->getLoc());
	bullet_back->setRot(dynamic_cast<Player*>(mPlayer)->getRot());


	cur_b_10->setLoc(dynamic_cast<Player*>(mPlayer)->getLoc());
	cur_b_10->setRot(dynamic_cast<Player*>(mPlayer)->getRot());
	cur_b_1->setLoc(dynamic_cast<Player*>(mPlayer)->getLoc());
	cur_b_1->setRot(dynamic_cast<Player*>(mPlayer)->getRot());
	cur_b_sl->setLoc(dynamic_cast<Player*>(mPlayer)->getLoc());
	cur_b_sl->setRot(dynamic_cast<Player*>(mPlayer)->getRot());

	r_b_100->setLoc(dynamic_cast<Player*>(mPlayer)->getLoc());
	r_b_100->setRot(dynamic_cast<Player*>(mPlayer)->getRot());
	r_b_10->setLoc(dynamic_cast<Player*>(mPlayer)->getLoc());
	r_b_10->setRot(dynamic_cast<Player*>(mPlayer)->getRot());
	r_b_1->setLoc(dynamic_cast<Player*>(mPlayer)->getLoc());
	r_b_1->setRot(dynamic_cast<Player*>(mPlayer)->getRot());

	int c_bullet = dynamic_cast<Player*>(mPlayer)->getWeapon()->getreloaded();
	int t_bullet = dynamic_cast<Player*>(mPlayer)->getWeapon()->gettotal();
	if (c_bullet / 10 != c10) {
		switch (c_bullet / 10) {
		case 0:
			cur_b_10->change_texture("obj_source\\number\\number_0.png", 1024, 1024);
			break;
		case 1:
			cur_b_10->change_texture("obj_source\\number\\number_1.png", 1024, 1024);
			break;
		case 2:
			cur_b_10->change_texture("obj_source\\number\\number_2.png", 1024, 1024);
			break;
		case 3:
			cur_b_10->change_texture("obj_source\\number\\number_3.png", 1024, 1024);
			break;
		case 4:
			cur_b_10->change_texture("obj_source\\number\\number_4.png", 1024, 1024);
			break;
		case 5:
			cur_b_10->change_texture("obj_source\\number\\number_5.png", 1024, 1024);
			break;
		case 6:
			cur_b_10->change_texture("obj_source\\number\\number_6.png", 1024, 1024);
			break;
		case 7:
			cur_b_10->change_texture("obj_source\\number\\number_7.png", 1024, 1024);
			break;
		case 8:
			cur_b_10->change_texture("obj_source\\number\\number_8.png", 1024, 1024);
			break;
		case 9:
			cur_b_10->change_texture("obj_source\\number\\number_9.png", 1024, 1024);
			break;
		}
		c10 = c_bullet / 10;
	}
	c_bullet -= (c10 * 10);
	if (c_bullet != c1) {
		switch (c_bullet) {
		case 0:
			cur_b_1->change_texture("obj_source\\number\\number_0.png", 1024, 1024);
			break;
		case 1:
			cur_b_1->change_texture("obj_source\\number\\number_1.png", 1024, 1024);
			break;
		case 2:
			cur_b_1->change_texture("obj_source\\number\\number_2.png", 1024, 1024);
			break;
		case 3:
			cur_b_1->change_texture("obj_source\\number\\number_3.png", 1024, 1024);
			break;
		case 4:
			cur_b_1->change_texture("obj_source\\number\\number_4.png", 1024, 1024);
			break;
		case 5:
			cur_b_1->change_texture("obj_source\\number\\number_5.png", 1024, 1024);
			break;
		case 6:
			cur_b_1->change_texture("obj_source\\number\\number_6.png", 1024, 1024);
			break;
		case 7:
			cur_b_1->change_texture("obj_source\\number\\number_7.png", 1024, 1024);
			break;
		case 8:
			cur_b_1->change_texture("obj_source\\number\\number_8.png", 1024, 1024);
			break;
		case 9:
			cur_b_1->change_texture("obj_source\\number\\number_9.png", 1024, 1024);
			break;
		}
		c1 = c_bullet;
	}

	if (t_bullet / 100 != r100) {
		switch (t_bullet / 100) {
		case 0:
			r_b_100->change_texture("obj_source\\number\\number_0.png", 1024, 1024);
			break;
		case 1:
			r_b_100->change_texture("obj_source\\number\\number_1.png", 1024, 1024);
			break;
		case 2:
			r_b_100->change_texture("obj_source\\number\\number_2.png", 1024, 1024);
			break;
		case 3:
			r_b_100->change_texture("obj_source\\number\\number_3.png", 1024, 1024);
			break;
		case 4:
			r_b_100->change_texture("obj_source\\number\\number_4.png", 1024, 1024);
			break;
		case 5:
			r_b_100->change_texture("obj_source\\number\\number_5.png", 1024, 1024);
			break;
		case 6:
			r_b_100->change_texture("obj_source\\number\\number_6.png", 1024, 1024);
			break;
		case 7:
			r_b_100->change_texture("obj_source\\number\\number_7.png", 1024, 1024);
			break;
		case 8:
			r_b_100->change_texture("obj_source\\number\\number_8.png", 1024, 1024);
			break;
		case 9:
			r_b_100->change_texture("obj_source\\number\\number_9.png", 1024, 1024);
			break;
		}
		r100 = t_bullet / 100;
	}
	t_bullet -= (r100 * 100);
	if (t_bullet / 10 != r10) {
		switch (t_bullet / 10) {
		case 0:
			r_b_10->change_texture("obj_source\\number\\number_0.png", 1024, 1024);
			break;
		case 1:
			r_b_10->change_texture("obj_source\\number\\number_1.png", 1024, 1024);
			break;
		case 2:
			r_b_10->change_texture("obj_source\\number\\number_2.png", 1024, 1024);
			break;
		case 3:
			r_b_10->change_texture("obj_source\\number\\number_3.png", 1024, 1024);
			break;
		case 4:
			r_b_10->change_texture("obj_source\\number\\number_4.png", 1024, 1024);
			break;
		case 5:
			r_b_10->change_texture("obj_source\\number\\number_5.png", 1024, 1024);
			break;
		case 6:
			r_b_10->change_texture("obj_source\\number\\number_6.png", 1024, 1024);
			break;
		case 7:
			r_b_10->change_texture("obj_source\\number\\number_7.png", 1024, 1024);
			break;
		case 8:
			r_b_10->change_texture("obj_source\\number\\number_8.png", 1024, 1024);
			break;
		case 9:
			r_b_10->change_texture("obj_source\\number\\number_9.png", 1024, 1024);
			break;
		}
		r10 = t_bullet / 10;
	}
	t_bullet -= (r10 * 10);
	if (t_bullet != r1) {
		switch (t_bullet) {
		case 0:
			r_b_1->change_texture("obj_source\\number\\number_0.png", 1024, 1024);
			break;
		case 1:
			r_b_1->change_texture("obj_source\\number\\number_1.png", 1024, 1024);
			break;
		case 2:
			r_b_1->change_texture("obj_source\\number\\number_2.png", 1024, 1024);
			break;
		case 3:
			r_b_1->change_texture("obj_source\\number\\number_3.png", 1024, 1024);
			break;
		case 4:
			r_b_1->change_texture("obj_source\\number\\number_4.png", 1024, 1024);
			break;
		case 5:
			r_b_1->change_texture("obj_source\\number\\number_5.png", 1024, 1024);
			break;
		case 6:
			r_b_1->change_texture("obj_source\\number\\number_6.png", 1024, 1024);
			break;
		case 7:
			r_b_1->change_texture("obj_source\\number\\number_7.png", 1024, 1024);
			break;
		case 8:
			r_b_1->change_texture("obj_source\\number\\number_8.png", 1024, 1024);
			break;
		case 9:
			r_b_1->change_texture("obj_source\\number\\number_9.png", 1024, 1024);
			break;
		}
		r1 = t_bullet;
	}
	//============================================================

	crossline->setLoc(dynamic_cast<Player*>(mPlayer)->getLoc());
	crossline->setRot(dynamic_cast<Player*>(mPlayer)->getRot());

	timer->Update();
}

void UI::Render()
{
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	hp_back->Render();
	bullet_back->Render();
	if(h100 != 0)
		hp_100->Render();
	if(h100 != 0 || h10 != 0)
		hp_10->Render();
	hp_1->Render();

	if(c10 != 0)
		cur_b_10->Render();
	cur_b_1->Render();
	cur_b_sl->Render();
	if(r100 !=0)
		r_b_100->Render();
	if(r100!= 0 ||r10 !=0)
		r_b_10->Render();
	r_b_1->Render();

	crossline->Render();


	glDisable(GL_BLEND);
	timer->Render();
}