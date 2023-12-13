#pragma once
#include "Player.h"
#include "CharacterBase.h"
#include "Scene.h"
#include "CubeMap.h"

class Select_Item : public Scene {
public:


	Select_Item(CharacterBase* t_Player, CubeMap* t_cube)
		: mPlayer(t_Player), mCubemap(t_cube)
	{
		button[0] = new Mesh("obj_source\\scene_select\\item_button.obj", "obj_source\\scene_select\\vest.png", 1024, 1024);
		button[0]->init_rotate(-90, 0, 1, 0);
		button[0]->setLoc(glm::vec3(50, 10, -11));

		button[1] = new Mesh("obj_source\\scene_select\\item_button.obj", "obj_source\\scene_select\\health_pack.png", 1024, 1024);
		button[1]->init_rotate(-90, 0, 1, 0);
		button[1]->setLoc(glm::vec3(50, 10, 11));

		button[2] = new Mesh("obj_source\\scene_select\\item_button.obj", "obj_source\\scene_select\\ammo_box.png", 1024, 1024);
		button[2]->init_rotate(-90, 0, 1, 0);
		button[2]->setLoc(glm::vec3(50, -10, -11));

		button[3] = new Mesh("obj_source\\scene_select\\item_button.obj", "obj_source\\scene_select\\blueprint.png", 1024, 1024);
		button[3]->init_rotate(-90, 0, 1, 0);
		button[3]->setLoc(glm::vec3(50, -10, 11));

		check[0] = new Mesh("obj_source\\scene_select\\item_button.obj", "obj_source\\scene_select\\check.png", 1024, 1024);
		check[0]->init_rotate(-90, 0, 1, 0);
		check[0]->setLoc(glm::vec3(45, 10, -10));

		check[1] = new Mesh("obj_source\\scene_select\\item_button.obj", "obj_source\\scene_select\\check.png", 1024, 1024);
		check[1]->init_rotate(-90, 0, 1, 0);
		check[1]->setLoc(glm::vec3(45, 10, 11));

		check[2] = new Mesh("obj_source\\scene_select\\item_button.obj", "obj_source\\scene_select\\check.png", 1024, 1024);
		check[2]->init_rotate(-90, 0, 1, 0);
		check[2]->setLoc(glm::vec3(45, -9, -10));

		check[3] = new Mesh("obj_source\\scene_select\\item_button.obj", "obj_source\\scene_select\\check.png", 1024, 1024);
		check[3]->init_rotate(-90, 0, 1, 0);
		check[3]->setLoc(glm::vec3(45, -9, 11));

		startbutton = new Mesh("obj_source\\scene_select\\start_button.obj", "obj_source\\scene_select\\start_button.png", 1024, 1024);
		startbutton->init_scale(0.2);
		startbutton->init_rotate(-90, 0, 1, 0);
		startbutton->init_position(50, -15, 29);
		for (int i = 0; i < 4; ++i) {
			button[i]->setAmb(1.0f);
			check[i]->setAmb(1.0f);
		}
		startbutton->setAmb(1.0f);
	}
	~Select_Item() { 
		mPlayer = nullptr;
		delete button[0];
		delete button[1];
		delete button[2];
		delete button[3];

		delete check[0];
		delete check[1];
		delete check[2];
		delete check[3];

		delete startbutton;
	}

	CharacterBase* getPlayer();

	void Update();
	void Render();
private:
	CharacterBase* mPlayer;
	CubeMap* mCubemap;

	Mesh* button[4];
	Mesh* check[4];
	Mesh* startbutton;
};