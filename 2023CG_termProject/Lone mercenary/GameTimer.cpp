#include "GameTimer.h"

int GameTimer::p_num100 = 0;
int GameTimer::p_num10 = 0;
int GameTimer::p_num1 = 0;
int GameTimer::remaining_time = 0;

GameTimer::GameTimer(CharacterBase* t_player)
	: mPlayer(t_player)
{
	start_time = clock();
	remaining_time = 180;	//180초

	back = new Mesh("obj_source\\ui\\timer\\background.obj", "obj_source\\ui\\timer\\background.png", 1024, 1024);
	back->init_scale(0.002);
	back->init_rotate(-90, 0, 1, 0);
	back->init_position(0.5, 0.2, 0);	// 10.045
	num100 = new Mesh("obj_source\\number\\number.obj", "obj_source\\number\\number_0.png", 1024, 1024);
	num100->init_scale(0.0005);
	num100->init_rotate(-90, 0, 1, 0);
	num100->init_position(0.3, 0.11, -0.015);	// 10.037
	num10 = new Mesh("obj_source\\number\\number.obj", "obj_source\\number\\number_0.png", 1024, 1024);
	num10->init_scale(0.0005);
	num10->init_rotate(-90, 0, 1, 0);
	num10->init_position(0.3, 0.11, 0);
	num1 = new Mesh("obj_source\\number\\number.obj", "obj_source\\number\\number_0.png", 1024, 1024);
	num1->init_scale(0.0005);
	num1->init_rotate(-90, 0, 1, 0);
	num1->init_position(0.3, 0.11, 0.015);

	p_num100 = 0;
	p_num10 = 0;
	p_num1 = 0;

	back->setAmb(1.0);
	num100->setAmb(1.0);
	num10->setAmb(1.0);
	num1->setAmb(1.0);
}

GameTimer::~GameTimer()
{
	delete back;
	delete num100;
	delete num10;
	delete num1;
}

void GameTimer::plus_time(int extra_time) // 머리를 맞추거나 특수좀비 킬시 불러주자
{
	remaining_time += extra_time;
}

bool GameTimer::check_end()
{
	if (d_time > remaining_time) {
		std::cout << "시간 끝!" << '\n';
		return true;
	}

	return false;
}

void GameTimer::Update()
{
	cur_time = clock();
	d_time = static_cast<int>((cur_time - start_time) / CLOCKS_PER_SEC);
	int render_time = remaining_time - d_time;
	if (render_time / 100 != p_num100) {
		switch (render_time / 100) {
		case 0:
			num100->change_texture("obj_source\\number\\number_0.png", 1024, 1024);
			break;
		case 1:
			num100->change_texture("obj_source\\number\\number_1.png", 1024, 1024);
			break;
		case 2:
			num100->change_texture("obj_source\\number\\number_2.png", 1024, 1024);
			break;
		case 3:
			num100->change_texture("obj_source\\number\\number_3.png", 1024, 1024);
			break;
		case 4:
			num100->change_texture("obj_source\\number\\number_4.png", 1024, 1024);
			break;
		case 5:
			num100->change_texture("obj_source\\number\\number_5.png", 1024, 1024);
			break;
		case 6:
			num100->change_texture("obj_source\\number\\number_6.png", 1024, 1024);
			break;
		case 7:
			num100->change_texture("obj_source\\number\\number_7.png", 1024, 1024);
			break;
		case 8:
			num100->change_texture("obj_source\\number\\number_8.png", 1024, 1024);
			break;
		case 9:
			num100->change_texture("obj_source\\number\\number_9.png", 1024, 1024);
			break;
		}
		p_num100 = render_time / 100;
	}
	render_time -= (p_num100 * 100);
	if (render_time / 10 != p_num10) {
		switch (render_time / 10) {
		case 0:
			num10->change_texture("obj_source\\number\\number_0.png", 1024, 1024);
			break;
		case 1:
			num10->change_texture("obj_source\\number\\number_1.png", 1024, 1024);
			break;
		case 2:
			num10->change_texture("obj_source\\number\\number_2.png", 1024, 1024);
			break;
		case 3:
			num10->change_texture("obj_source\\number\\number_3.png", 1024, 1024);
			break;
		case 4:
			num10->change_texture("obj_source\\number\\number_4.png", 1024, 1024);
			break;
		case 5:
			num10->change_texture("obj_source\\number\\number_5.png", 1024, 1024);
			break;
		case 6:
			num10->change_texture("obj_source\\number\\number_6.png", 1024, 1024);
			break;
		case 7:
			num10->change_texture("obj_source\\number\\number_7.png", 1024, 1024);
			break;
		case 8:
			num10->change_texture("obj_source\\number\\number_8.png", 1024, 1024);
			break;
		case 9:
			num10->change_texture("obj_source\\number\\number_9.png", 1024, 1024);
			break;
		}
		p_num10 = render_time / 10;
	}
	render_time -= (p_num10 * 10);
	if (render_time != p_num1) {
		switch (render_time) {
		case 0:
			num1->change_texture("obj_source\\number\\number_0.png", 1024, 1024);
			break;
		case 1:
			num1->change_texture("obj_source\\number\\number_1.png", 1024, 1024);
			break;
		case 2:
			num1->change_texture("obj_source\\number\\number_2.png", 1024, 1024);
			break;
		case 3:
			num1->change_texture("obj_source\\number\\number_3.png", 1024, 1024);
			break;
		case 4:
			num1->change_texture("obj_source\\number\\number_4.png", 1024, 1024);
			break;
		case 5:
			num1->change_texture("obj_source\\number\\number_5.png", 1024, 1024);
			break;
		case 6:
			num1->change_texture("obj_source\\number\\number_6.png", 1024, 1024);
			break;
		case 7:
			num1->change_texture("obj_source\\number\\number_7.png", 1024, 1024);
			break;
		case 8:
			num1->change_texture("obj_source\\number\\number_8.png", 1024, 1024);
			break;
		case 9:
			num1->change_texture("obj_source\\number\\number_9.png", 1024, 1024);
			break;
		}
		p_num1 = render_time;
	}

	back->setLoc(dynamic_cast<Player*>(mPlayer)->getLoc());
	back->setRot(dynamic_cast<Player*>(mPlayer)->getRot());
	num100->setLoc(dynamic_cast<Player*>(mPlayer)->getLoc());
	num100->setRot(dynamic_cast<Player*>(mPlayer)->getRot());
	num10->setLoc(dynamic_cast<Player*>(mPlayer)->getLoc());
	num10->setRot(dynamic_cast<Player*>(mPlayer)->getRot());
	num1->setLoc(dynamic_cast<Player*>(mPlayer)->getLoc());
	num1->setRot(dynamic_cast<Player*>(mPlayer)->getRot());
}

void GameTimer::Render()
{
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	back->Render();
	num100->Render();
	num10->Render();
	num1->Render();
	glDisable(GL_BLEND);
}

int GameTimer::getremaining()
{
	return remaining_time - d_time;
}