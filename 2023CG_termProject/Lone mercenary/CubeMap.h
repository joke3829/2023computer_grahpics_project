#pragma once
#include "stdafx.h"
#include "Mesh.h"

class CubeMap {
public:
	CubeMap();
	~CubeMap();

	void Render();
private:
	Mesh* wall[4];
	Mesh* sky;
};