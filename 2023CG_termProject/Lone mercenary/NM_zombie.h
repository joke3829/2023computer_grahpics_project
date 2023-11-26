//==========================================================
// NM_zombie.h
// �Ϲ� ���� ���� ���
//==========================================================

#pragma once

#include "Enemy.h"
#include "NMMesh.h"

class NM_zombie : public EnemyBase {
public:
	NM_zombie();
	NM_zombie(float hp, float max, float spd, float def, float atk);
	~NM_zombie();

	void walk_ani();
	
	void Render() const;
protected:
private:
	NM_Mesh* head;		// �Ӹ�
	NM_Mesh* body;		// ����
	NM_Mesh* arm[2];	// ����, ������
	NM_Mesh* leg[2];	// �޴ٸ�, �����ٸ�
};