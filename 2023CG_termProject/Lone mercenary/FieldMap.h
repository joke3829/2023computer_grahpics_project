//==========================================================
// Field.h
// �ʵ� ���� ���
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
	// �ǹ��� �߰�
};
