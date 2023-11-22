#include "Field.h"
#include "Mesh.h"

Field::Field()
{
	if (nullptr == bottom)
		bottom = new Mesh("test_obj\\test_floor.obj");
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