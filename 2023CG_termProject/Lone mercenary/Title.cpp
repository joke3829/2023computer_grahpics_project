#include "Title.h"

Title::Title(CubeMap* t_cube)
	: mCubemap(t_cube)
{
	Title_image = new Mesh("obj_source\\title\\title.obj", "obj_source\\title\\title.png", 1024, 1024);
	Title_image->init_scale(0.15);
	Title_image->init_rotate(-90, 0, 1, 0);
	Title_image->init_position(20, 3, -7);
	Title_image->setAmb(1.0f);
}

Title::~Title()
{
	delete Title_image;
}

void Title::Render()
{
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	mCubemap->Render();
	Title_image->Render();
	glDisable(GL_BLEND);
}