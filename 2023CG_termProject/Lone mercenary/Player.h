//============================================================
// Player.h
// �÷��̾� ���
// �÷��̾� ���� �� ����
//============================================================



#include "CharacterBase.h"
#include "Weapon.h"

class Player : public CharacterBase {
private:
	glm::vec3 cur_loc;			// �÷��̾� ���� ��ġ, �ѱ�� ī�޶� �Ѱ�����
	glm::vec2 cur_rot;			// �÷��̾ �ٶ󺸴� ����(0, 0)�̸� x���� �����ϴ� ������ �ٶ󺻴�. ���������� �Ѱ��ֱ�
	bool move[4];		// 0 w, 1 a
	int weapon;
	float mousesense;
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
	glm::vec3 getLoc();				// ���� ��ġ �޾ƿ���
	glm::vec2 getRot();				// ���� �ٶ󺸴� ���� �޾ƿ���
	int Weapon();
};