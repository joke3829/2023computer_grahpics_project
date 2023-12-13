#include "CubeMap.h"

CubeMap::CubeMap()
{
	wall[0] = new Mesh("obj_source\\field\\cube_map400_400.obj", "obj_source\\field\\background_1.png", 1024, 1024);
	wall[1] = new Mesh("obj_source\\field\\cube_map400_400.obj", "obj_source\\field\\background_2.png", 1024, 1024);
	wall[2] = new Mesh("obj_source\\field\\cube_map400_400.obj", "obj_source\\field\\background_3.png", 1024, 1024);
	wall[3] = new Mesh("obj_source\\field\\cube_map400_400.obj", "obj_source\\field\\background_4.png", 1024, 1024);
	sky = new Mesh("obj_source\\field\\cube_map400_400.obj", "obj_source\\field\\background_sky.png", 1024, 1024);


	wall[0]->init_position(0, 0, -200);

	wall[1]->init_rotate(-90, 0, 1, 0);
	wall[1]->init_position(200, 0, 0);

	wall[2]->init_rotate(180, 0, 1, 0);
	wall[2]->init_position(0, 0, 200);

	wall[3]->init_rotate(90, 0, 1, 0);
	wall[3]->init_position(-200, 0, 0);

	sky->init_rotate(90, 1, 0, 0);
	sky->init_position(0, 200, 0);

	wall[0]->setAmb(1.0);
	wall[1]->setAmb(1.0);
	wall[2]->setAmb(1.0);
	wall[3]->setAmb(1.0);
	sky->setAmb(1.0);
}

CubeMap::~CubeMap()
{
	delete wall[0];
	delete wall[1];
	delete wall[2];
	delete wall[3];

	delete sky;
}


void CubeMap::Render()
{
	for (Mesh* m : wall)
		m->Render();
	sky->Render();
}