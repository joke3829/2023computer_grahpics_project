#include "ScoreBoard.h"

ScoreBoard::ScoreBoard(CubeMap* t_cube, std::vector<EnemyBase*>& t_list, GameTimer* t_timer, CameraObj* t_camera)
	: mCubemap(t_cube), list(t_list), mTimer(t_timer), camera(t_camera)
{
	

	back = new Mesh("obj_source\\ui\\timer\\background.obj", "obj_source\\ui\\timer\\background.png", 1024, 1024);
	back->init_scale(0.005);
	back->init_rotate(-90, 0, 1, 0);
	back->init_position(0.5, 0, 0);



	num_5 = new Mesh("obj_source\\number\\number.obj", "obj_source\\number\\number_0.png", 1024, 1024);
	num_5->init_scale(0.001);
	num_5->init_rotate(-90, 0, 1, 0);
	num_5->init_position(0.3, 0, -0.06);

	num_4 = new Mesh("obj_source\\number\\number.obj", "obj_source\\number\\number_0.png", 1024, 1024);
	num_4->init_scale(0.001);
	num_4->init_rotate(-90, 0, 1, 0);
	num_4->init_position(0.3, 0, -0.03);

	num_3 = new Mesh("obj_source\\number\\number.obj", "obj_source\\number\\number_0.png", 1024, 1024);
	num_3->init_scale(0.001);
	num_3->init_rotate(-90, 0, 1, 0);
	num_3->init_position(0.3, 0, 0);

	num_2 = new Mesh("obj_source\\number\\number.obj", "obj_source\\number\\number_0.png", 1024, 1024);
	num_2->init_scale(0.001);
	num_2->init_rotate(-90, 0, 1, 0);
	num_2->init_position(0.3, 0, 0.03);

	num_1 = new Mesh("obj_source\\number\\number.obj", "obj_source\\number\\number_0.png", 1024, 1024);
	num_1->init_scale(0.001);
	num_1->init_rotate(-90, 0, 1, 0);
	num_1->init_position(0.3, 0, 0.06);

	back->setAmb(1.0);
	num_5->setAmb(1.0f);
	num_4->setAmb(1.0f);
	num_3->setAmb(1.0);
	num_2->setAmb(1.0);
	num_1->setAmb(1.0f);

	gomain = new Mesh("obj_source\\scene_select\\start_button.obj", "obj_source\\scene_select\\back_menu.png", 1024, 1024);
	gomain->init_scale(0.2);
	gomain->init_rotate(-90, 0, 1, 0);
	gomain->init_position(50, -15, 29);
	gomain->setAmb(1.0f);

	exitProgram = new Mesh("obj_source\\scene_select\\start_button.obj", "obj_source\\scene_select\\exit.png", 1024, 1024);
	exitProgram->init_scale(0.2);
	exitProgram->init_rotate(-90, 0, 1, 0);
	exitProgram->init_position(50, -15, -29);
	exitProgram->setAmb(1.0f);

	ruf = new Mesh("obj_source\\number\\number.obj", "obj_source\\number\\ruf.png", 1024, 1024);
	ruf->init_scale(0.001);
	ruf->init_rotate(-90, 0, 1, 0);
	ruf->init_position(0.3, 0.06, -0.015);
	ruf->setAmb(1.0f);

	rhk = new Mesh("obj_source\\number\\number.obj", "obj_source\\number\\rhk.png", 1024, 1024);
	rhk->init_scale(0.00117);
	rhk->init_rotate(-90, 0, 1, 0);
	rhk->init_position(0.3, 0.06, 0.015);
	rhk->setAmb(1.0f);

}

ScoreBoard::~ScoreBoard()
{
	delete back;
	delete num_5;
	delete num_4;
	delete num_3;
	delete num_2;
	delete num_1;

	delete ruf;
	delete rhk;
}

void ScoreBoard::Update_1()
{
	camera->setCameraAngle(glm::vec2(0, 0));
	camera->setCameraEYE(glm::vec3(0, 0, 0));
	for (int i = 0; i < list.size(); ++i) {
		if (list[i]->Death_check()) {
			totalscore += 100;
			killcnt++;
		}
	}
	int re_time = mTimer->getremaining();
	totalscore += (re_time * 50);
	if (killcnt == MAX_ZOMBIE)		// 올킬 보너스 60은 바꿔주자
		totalscore += 2000;

	switch (totalscore / 10000) {
	case 0:
		num_5->change_texture("obj_source\\number\\number_0.png", 1024, 1024);
		break;
	case 1:
		num_5->change_texture("obj_source\\number\\number_1.png", 1024, 1024);
		break;
	case 2:
		num_5->change_texture("obj_source\\number\\number_2.png", 1024, 1024);
		break;
	case 3:
		num_5->change_texture("obj_source\\number\\number_3.png", 1024, 1024);
		break;
	case 4:
		num_5->change_texture("obj_source\\number\\number_4.png", 1024, 1024);
		break;
	case 5:
		num_5->change_texture("obj_source\\number\\number_5.png", 1024, 1024);
		break;
	case 6:
		num_5->change_texture("obj_source\\number\\number_6.png", 1024, 1024);
		break;
	case 7:
		num_5->change_texture("obj_source\\number\\number_7.png", 1024, 1024);
		break;
	case 8:
		num_5->change_texture("obj_source\\number\\number_8.png", 1024, 1024);
		break;
	case 9:
		num_5->change_texture("obj_source\\number\\number_9.png", 1024, 1024);
		break;
	}
	totalscore -= ((totalscore / 10000) * 10000);
	switch (totalscore / 1000) {
	case 0:
		num_4->change_texture("obj_source\\number\\number_0.png", 1024, 1024);
		break;
	case 1:
		num_4->change_texture("obj_source\\number\\number_1.png", 1024, 1024);
		break;
	case 2:
		num_4->change_texture("obj_source\\number\\number_2.png", 1024, 1024);
		break;
	case 3:
		num_4->change_texture("obj_source\\number\\number_3.png", 1024, 1024);
		break;
	case 4:
		num_4->change_texture("obj_source\\number\\number_4.png", 1024, 1024);
		break;
	case 5:
		num_4->change_texture("obj_source\\number\\number_5.png", 1024, 1024);
		break;
	case 6:
		num_4->change_texture("obj_source\\number\\number_6.png", 1024, 1024);
		break;
	case 7:
		num_4->change_texture("obj_source\\number\\number_7.png", 1024, 1024);
		break;
	case 8:
		num_4->change_texture("obj_source\\number\\number_8.png", 1024, 1024);
		break;
	case 9:
		num_4->change_texture("obj_source\\number\\number_9.png", 1024, 1024);
		break;
	}
	totalscore -= ((totalscore / 1000) * 1000);
	switch (totalscore / 100) {
	case 0:
		num_3->change_texture("obj_source\\number\\number_0.png", 1024, 1024);
		break;
	case 1:
		num_3->change_texture("obj_source\\number\\number_1.png", 1024, 1024);
		break;
	case 2:
		num_3->change_texture("obj_source\\number\\number_2.png", 1024, 1024);
		break;
	case 3:
		num_3->change_texture("obj_source\\number\\number_3.png", 1024, 1024);
		break;
	case 4:
		num_3->change_texture("obj_source\\number\\number_4.png", 1024, 1024);
		break;
	case 5:
		num_3->change_texture("obj_source\\number\\number_5.png", 1024, 1024);
		break;
	case 6:
		num_3->change_texture("obj_source\\number\\number_6.png", 1024, 1024);
		break;
	case 7:
		num_3->change_texture("obj_source\\number\\number_7.png", 1024, 1024);
		break;
	case 8:
		num_3->change_texture("obj_source\\number\\number_8.png", 1024, 1024);
		break;
	case 9:
		num_3->change_texture("obj_source\\number\\number_9.png", 1024, 1024);
		break;
	}
	totalscore -= ((totalscore / 100) * 100);
	switch (totalscore / 10) {
	case 0:
		num_2->change_texture("obj_source\\number\\number_0.png", 1024, 1024);
		break;
	case 1:
		num_2->change_texture("obj_source\\number\\number_1.png", 1024, 1024);
		break;
	case 2:
		num_2->change_texture("obj_source\\number\\number_2.png", 1024, 1024);
		break;
	case 3:
		num_2->change_texture("obj_source\\number\\number_3.png", 1024, 1024);
		break;
	case 4:
		num_2->change_texture("obj_source\\number\\number_4.png", 1024, 1024);
		break;
	case 5:
		num_2->change_texture("obj_source\\number\\number_5.png", 1024, 1024);
		break;
	case 6:
		num_2->change_texture("obj_source\\number\\number_6.png", 1024, 1024);
		break;
	case 7:
		num_2->change_texture("obj_source\\number\\number_7.png", 1024, 1024);
		break;
	case 8:
		num_2->change_texture("obj_source\\number\\number_8.png", 1024, 1024);
		break;
	case 9:
		num_2->change_texture("obj_source\\number\\number_9.png", 1024, 1024);
		break;
	}
	totalscore -= ((totalscore / 10) * 10);
	switch (totalscore) {
	case 0:
		num_1->change_texture("obj_source\\number\\number_0.png", 1024, 1024);
		break;
	case 1:
		num_1->change_texture("obj_source\\number\\number_1.png", 1024, 1024);
		break;
	case 2:
		num_1->change_texture("obj_source\\number\\number_2.png", 1024, 1024);
		break;
	case 3:
		num_1->change_texture("obj_source\\number\\number_3.png", 1024, 1024);
		break;
	case 4:
		num_1->change_texture("obj_source\\number\\number_4.png", 1024, 1024);
		break;
	case 5:
		num_1->change_texture("obj_source\\number\\number_5.png", 1024, 1024);
		break;
	case 6:
		num_1->change_texture("obj_source\\number\\number_6.png", 1024, 1024);
		break;
	case 7:
		num_1->change_texture("obj_source\\number\\number_7.png", 1024, 1024);
		break;
	case 8:
		num_1->change_texture("obj_source\\number\\number_8.png", 1024, 1024);
		break;
	case 9:
		num_1->change_texture("obj_source\\number\\number_9.png", 1024, 1024);
		break;
	}
}

void ScoreBoard::Render()
{
	mCubemap->Render();
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	back->Render();

	num_5->Render();
	num_4->Render();
	num_3->Render();
	num_2->Render();
	num_1->Render();

	gomain->Render();
	exitProgram->Render();

	ruf->Render();
	rhk->Render();

	glDisable(GL_BLEND);
}