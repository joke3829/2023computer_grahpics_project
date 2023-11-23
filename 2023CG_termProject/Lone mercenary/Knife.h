//=========================================================
// Knife.h
// ������ Ŭ����
//=========================================================
#pragma once

#include "stdafx.h"
#include "Mesh.h"
#include "CharacterBase.h"

class Knife :  public CharacterBase, public Mesh {
public:
	Knife(std::string filename, int s_ammo, int r_ammo);

	float getATK();					// ���ݷ� �޾ƿ���
	void Shoot();
protected:
private:
	int weapon_num;			// ���� ��ȣ


	int total_ammo;			// �� ź�� ��
	int reloaded_ammo;		// ������ ź���


};