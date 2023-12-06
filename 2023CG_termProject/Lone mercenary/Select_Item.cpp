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
	button->Render();
	glDisable(GL_BLEND);
}