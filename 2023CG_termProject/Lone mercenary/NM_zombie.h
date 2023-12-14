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
	NM_zombie(float hp, float max, float spd, float def, float atk, int type);
	~NM_zombie();

	void walk_ani(int n);
	void setHit(bool);

	void z_heal(std::vector<EnemyBase*>&);
	void z_boom();
	NM_Mesh* gethead();
	NM_Mesh* getbody();
	NM_Mesh* getlarm();
	NM_Mesh* getrarm();
	NM_Mesh* getlleg();
	NM_Mesh* getrleg();

	bool Death_check();
	
	void Render() const;
protected:
private:
	int z_type;
	clock_t h_start_time{};
	clock_t h_current_time{};
	double p_delay{};
	NM_Mesh* head;		// ¸Ó¸®
	NM_Mesh* body;		// ¸öÅë
	NM_Mesh* arm[2];	// ¿ÞÆÈ, ¿À¸¥ÆÈ
	NM_Mesh* leg[2];	// ¿Þ´Ù¸®, ¿À¸¥´Ù¸®

	bool hithead;
};