//============================================================
// Player.h
// �÷��̾� ���
// �÷��̾� ���� �� ����
//============================================================


#pragma once
#include "CharacterBase.h"
#include "CameraObj.h"
#include "Weapon.h"
#include "Enemy.h"
#include "Scene.h"

class Player : public CharacterBase {
private:
	glm::vec3 cur_loc;			// �÷��̾� ���� ��ġ, �ѱ�� ī�޶� �Ѱ�����
	glm::vec2 cur_rot;			// �÷��̾ �ٶ󺸴� ����(0, 0)�̸� x���� �����ϴ� ������ �ٶ󺻴�. ���������� �Ѱ��ֱ�
	glm::vec2 init_Weapon_rot;
	bool item[4];
	bool move[4];		// 0 w, 1 a
	bool atck;
	bool changing;
	bool reloading;
	bool knife_at;
	int weapon;
	int cnt; //������ �ð��� ����!
	float mousesense;
	float angle;
	int type;
	int cnt_knife;
	Scene* mScene;
	Weapon* cur_Wea = nullptr;
	Weapon* pistol;
	Weapon* rifle;
	Weapon* knife;

protected:

public:
	Player(float hp, float max, float spd, float def, float atk);

	// �ִϸ��̼� �Լ� �����
	void animation();
	void animi_rot(int, int);
	void setMove(char, bool);
	void setsensative(char);
	void setWeapon(char);
	void attack();
	void conti_attack(bool);
	void take_out_Wep();
	void set_item(int, int);
	void apply_item();
	void reload_ani();
	bool do_reload_ani();
	void knife_move();

	void attack_check(std::vector<EnemyBase*>&, CameraObj*);	// ������ ����� ��ҳ�?
	glm::vec3 RaytoPlaneXY(glm::vec3,glm::vec3,float);			// XY��� ����
	glm::vec3 RaytoPlaneXZ(glm::vec3,glm::vec3,float);			// XZ��� ����
	glm::vec3 RaytoPlaneYZ(glm::vec3,glm::vec3,float);			// YZ��� ����

	glm::vec3 getLoc();				// ���� ��ġ �޾ƿ���
	glm::vec2 getRot();				// ���� �ٶ󺸴� ���� �޾ƿ���
	glm::vec2 getWepRot();			// ���� �ٶ󺸴� ���⿡ ���� �ѱ���ġ �����ϱ�

	Weapon* getWeapon() const;		// ���� ��� �ִ� ���� ���� �ޱ�
	int Weapon();
	bool getItemapp(int n);
};