//=========================================================
// NMMesh.h
// ���� ������� ����� �Ž� ���̽�
//=========================================================
#pragma once

#include "Mesh.h"

class NM_Mesh : public Mesh {
public:
	NM_Mesh(std::string filename)
		: Mesh(filename) {};
	virtual ~NM_Mesh() {};

	void leg_ani();
protected:
private:
};
