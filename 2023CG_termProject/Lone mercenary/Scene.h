//==========================================================
// Scene.h
// 장면을 다형성있게 만들자
//==========================================================

#pragma once

#include "stdafx.h"

class Scene {
public:
	Scene() {};
	~Scene() {};
	virtual void Update() {};
	virtual void Render() {};
private:
};

