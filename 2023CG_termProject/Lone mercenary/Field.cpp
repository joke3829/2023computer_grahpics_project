#include "Field.h"
#include "Mesh.h"

Field::Field()
{
	if (nullptr == bottom)
		bottom = new Mesh("obj_source\\field\\test_floor.obj", "obj_source\\temp_texture.jpg", 1024, 1024);	//
}

Field::~Field()
{
	if (bottom) {
		delete bottom;
		bottom = nullptr;
	}
}

void Field::Render() const
{
	bottom->Render();
}