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
	NM_zombie(float hp, float max, float spd, float def, float atk, int type);
	~NM_zombie();

	void walk_ani();
	void z_heal(std::vector<EnemyBase*>&);
	NM_Mesh* gethead();
	
	void Render() const;
protected:
private:
	int z_type;
	clock_t start_time{};
	clock_t current_time{};
	double p_delay{};
	NM_Mesh* head;		// �Ӹ�
	NM_Mesh* body;		// ����
	NM_Mesh* arm[2];	// ����, ������
	NM_Mesh* leg[2];	// �޴ٸ�, �����ٸ�
};