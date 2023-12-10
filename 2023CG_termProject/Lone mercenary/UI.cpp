#include "UI.h"

int UI::h100 = 0; int UI::h10 = 0; int UI::h1 = 0;

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


}

void UI::Update()
{
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
	timer->Update();
}

void UI::Render()
{
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	hp_back->Render();
	if(h100 != 0)
		hp_100->Render();
	if(h100 != 0 || h10 != 0)
		hp_10->Render();
	hp_1->Render();

	glDisable(GL_BLEND);
	timer->Render();
}