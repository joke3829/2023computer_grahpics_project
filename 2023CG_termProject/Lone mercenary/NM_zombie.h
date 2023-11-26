//==========================================================
// NM_zombie.h
// ÀÏ¹Ý Á»ºñ °ü¸® Çì´õ
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
	NM_Mesh* head;		// ¸Ó¸®
	NM_Mesh* body;		// ¸öÅë
	NM_Mesh* arm[2];	// ¿ÞÆÈ, ¿À¸¥ÆÈ
	NM_Mesh* leg[2];	// ¿Þ´Ù¸®, ¿À¸¥´Ù¸®
};