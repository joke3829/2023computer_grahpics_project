//=========================================================
// NMMesh.h
// 보통 좀비들이 사용할 매시 베이스
//=========================================================
#pragma once

#include "Mesh.h"

class NM_Mesh : public Mesh {
public:
	NM_Mesh(std::string filename, std::string f_path, int w_size, int h_size)
		: Mesh(filename, f_path, w_size, h_size) {};
	virtual ~NM_Mesh() {};

	void leg_ani();
protected:
private:
};
