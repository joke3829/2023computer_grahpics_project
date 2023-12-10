#pragma once
#include "Scene.h"
#include "CubeMap.h"

class Title : public Scene {
public:
	Title(CubeMap*);
	~Title();

	void Render();
private:
	CubeMap* mCubemap;
	Mesh* Title_image;
};