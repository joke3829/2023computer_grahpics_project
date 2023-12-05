#pragma once
#include "Player.h"
#include "CharacterBase.h"
#include "Scene.h"

class Select_Item : public Scene {
public:
	Select_Item(CharacterBase* t_Player)
		: mPlayer(t_Player)
	{}
	~Select_Item() { mPlayer = nullptr; }

	CharacterBase* getPlayer();

	void Update();
	void Render();
private:
	CharacterBase* mPlayer;
};