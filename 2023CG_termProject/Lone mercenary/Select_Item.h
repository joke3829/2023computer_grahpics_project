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
		button = new Mesh("obj_source\\scene_select\\item_button.obj", "obj_source\\scene_select\\vest.png", 1024, 1024);
		button->init_rotate(-90, 0, 1, 0);
		button->setLoc(glm::vec3(50, 0, 0));

		startbutton = new Mesh("obj_source\\scene_select\\start_button.obj", "obj_source\\scene_select\\start_button.png", 1024, 1024);
		startbutton->init_scale(0.15);
		startbutton->init_rotate(-90, 0, 1, 0);
		startbutton->init_position(60, 0, 0);
	}
	~Select_Item() { 
		mPlayer = nullptr;
		delete button;
		delete startbutton;
	}

	CharacterBase* getPlayer();

	void Update();
	void Render();
private:
	CharacterBase* mPlayer;
	CubeMap* mCubemap;

	Mesh* button;
	Mesh* startbutton;
};