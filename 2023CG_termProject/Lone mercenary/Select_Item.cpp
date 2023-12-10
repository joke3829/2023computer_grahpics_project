#include "Select_Item.h"


CharacterBase* Select_Item::getPlayer()
{
	return mPlayer;
}

void Select_Item::Update()
{

}

void Select_Item::Render()
{
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	mCubemap->Render();
	startbutton->Render();
	button[0]->Render();
	button[1]->Render();
	button[2]->Render();
	button[3]->Render();

	if(dynamic_cast<Player*>(mPlayer)->getItemapp(0))
		check[0]->Render();
	if (dynamic_cast<Player*>(mPlayer)->getItemapp(1))
		check[1]->Render();
	if (dynamic_cast<Player*>(mPlayer)->getItemapp(2))
		check[2]->Render();
	if (dynamic_cast<Player*>(mPlayer)->getItemapp(3))
		check[3]->Render();
	glDisable(GL_BLEND);
}