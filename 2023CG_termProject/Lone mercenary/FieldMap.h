//==========================================================
// Field.h
// 필드 관리 헤더
//==========================================================

#pragma once

#include "stdafx.h"

class Mesh;
class FieldMap {
public:
	FieldMap();
	~FieldMap();

	Mesh* gethouse_1();
	Mesh* gethouse_2();
	Mesh* gethouse_3();
	Mesh* gethouse_4();

	void Render() const;
protected:
private:
	Mesh* bottom{ nullptr };
	// 건물들 추가
	Mesh* house_1;
	Mesh* house_2;
	Mesh* house_3;
	Mesh* house_4;
};
