#include "FieldMap.h"
#include "Mesh.h"

FieldMap::FieldMap()
{
	if (nullptr == bottom)
		bottom = new Mesh("obj_source\\field\\floor300_300.obj", "obj_source\\field\\bottom_texture.png", 1024, 1024);	//

	house_1 = new Mesh("obj_source\\field\\house.obj", "obj_source\\field\\house_texture.png", 1024, 1024);
	house_2 = new Mesh("obj_source\\field\\house.obj", "obj_source\\field\\house_texture.png", 1024, 1024);
	house_3 = new Mesh("obj_source\\field\\house.obj", "obj_source\\field\\house_texture.png", 1024, 1024);
	house_4 = new Mesh("obj_source\\field\\house.obj", "obj_source\\field\\house_texture.png", 1024, 1024);
	//house_1->init_rotate(45, 0, 1, 0);
	house_1->init_position(-100, 0, -100);
	house_2->init_position(-100, 0, 100);
	house_3->init_position(100, 0, 100);
	house_4->init_position(100, 0, -100);
}

FieldMap::~FieldMap()
{
	if (bottom) {
		delete bottom;
		bottom = nullptr;
	}
	delete house_1;
	delete house_3;
	delete house_2;
	delete house_4;
}

void FieldMap::Render() const
{
	bottom->Render();
	house_1->Render();
	house_2->Render();
	house_3->Render();
	house_4->Render();
}

Mesh* FieldMap::gethouse_1()
{
	return house_1;
}

Mesh* FieldMap::gethouse_2()
{
	return house_2;
}
Mesh* FieldMap::gethouse_3()
{
	return house_3;
}
Mesh* FieldMap::gethouse_4()
{
	return house_4;
}