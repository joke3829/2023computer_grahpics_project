//==========================================================
// Field.h
// �ʵ� ���� ���
//==========================================================

#pragma once

#include "stdafx.h"

class Mesh;
class Field {
public:
	Field();
	~Field();

	void Render() const;
protected:
private:
	Mesh* bottom{ nullptr };
	// �ǹ��� �߰�
};
