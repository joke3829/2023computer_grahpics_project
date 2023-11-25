//==========================================================
// NM_zombie.h
// 일반 좀비 관리 헤더
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
	NM_Mesh* body;		// 몸통
	//NM_Mesh* leg[2];	// 왼다리, 오른다리
};