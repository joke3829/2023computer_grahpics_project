#include "Player.h"

// =========================P_Mesh==========================

P_Mesh::P_Mesh() : Mesh() {};

P_Mesh::P_Mesh(std::string filename) : Mesh(filename) {};

P_Mesh::~P_Mesh() {};

//==========================================================

//==========================Player===========================

Player::Player() : CharacterBase() {};

Player::Player(float hp, float max, float spd, float def, float atk)
	: CharacterBase(hp, max, spd, def, atk)
{
	arm = new P_Mesh("test_obj\\cube.obj");
}

Player::~Player()
{
	delete arm;
}

//===========================================================