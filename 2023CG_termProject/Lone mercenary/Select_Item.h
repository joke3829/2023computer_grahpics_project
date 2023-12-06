#pragma once
#include "Player.h"
#include "CharacterBase.h"
#include "Scene.h"

class Select_Item : public Scene {
public:


	Select_Item(CharacterBase* t_Player)
		: mPlayer(t_Player)
	{
		button = new Mesh("obj_source\\scene_select\\item_button.obj", "obj_source\\scene_select\\vest.png", 1024, 1024);
		button->init_rotate(-90, 0, 1, 0);
		button->setLoc(glm::vec3(50, 0, 0));
	}
	~Select_Item() { 
		mPlayer = nullptr;
		delete button;
	}

	CharacterBase* getPlayer();

	void Update();
	void Render();
private:
	CharacterBase* mPlayer;

	Mesh* button;
};