#include "Field.h"
#include "Mesh.h"

Field::Field()
{
	if (nullptr == bottom)
		bottom = new Mesh("obj\\field\\test_floor.obj", "obj\\temp_texture.jpg", 1024, 1024);	//
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