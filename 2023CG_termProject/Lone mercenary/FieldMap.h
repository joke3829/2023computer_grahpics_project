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

	void Render() const;
protected:
private:
	Mesh* bottom{ nullptr };
	// 건물들 추가
};
