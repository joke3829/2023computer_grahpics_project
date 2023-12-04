#include "FieldMap.h"
#include "Mesh.h"

FieldMap::FieldMap()
{
	if (nullptr == bottom)
		bottom = new Mesh("obj_source\\field\\test_floor.obj", "obj_source\\temp_texture.jpg", 1024, 1024);	//
}

FieldMap::~FieldMap()
{
	if (bottom) {
		delete bottom;
		bottom = nullptr;
	}
}

void FieldMap::Render() const
{
	bottom->Render();
}