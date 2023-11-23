//==========================================================
// NM_zombie.h
// �Ϲ� ���� ���� ���
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
	Mesh* body;		// ����
	Mesh* leg[2];	// �޴ٸ�, �����ٸ�

	glm::vec3 cur_loc;
	glm::vec2 cur_rot;
};