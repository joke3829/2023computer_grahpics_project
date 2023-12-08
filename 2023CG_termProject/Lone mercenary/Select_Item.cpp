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
	button->Render();
	glDisable(GL_BLEND);
}