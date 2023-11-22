//==========================================================
// NM_zombie.h
// 일반 좀비 관리 헤더
//==========================================================

#pragma once

#include "CharacterBase.h"

class Mesh;
class NM_zombie : public CharacterBase {
public:
	NM_zombie();
	NM_zombie(float hp, float max, float spd, float def, float atk);
	~NM_zombie();

	void animation();

	void Render() const;
protected:
private:
	Mesh* body;		// 몸통
	Mesh* leg[2];	// 왼다리, 오른다리

	glm::vec3 cur_loc;
	glm::vec2 cur_rot;
};