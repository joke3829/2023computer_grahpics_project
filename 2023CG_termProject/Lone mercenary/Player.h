//============================================================
// Player.h
// �÷��̾� ���
// �÷��̾� ���� �� ����
//============================================================



#include "CharacterBase.h"

class Player : public CharacterBase {
public:
	Player(float hp, float max, float spd, float def, float atk);

	// �ִϸ��̼� �Լ� �����
	void animation();

	void setMove(char, bool);
	glm::vec3 getLoc();				// ���� ��ġ �޾ƿ���
	glm::vec2 getRot();				// ���� �ٶ󺸴� ���� �޾ƿ���

protected:
private:
<<<<<<< Updated upstream
	glm::vec3 cur_loc;			// �÷��̾� ���� ��ġ, �ѱ�� ī�޶� �Ѱ�����
	glm::vec2 cur_rot;			// �÷��̾ �ٶ󺸴� ����(0, 0)�̸� x���� �����ϴ� ������ �ٶ󺻴�. ���������� �Ѱ��ֱ�
	bool move[4];		// 0 w, 1 a
=======

	bool move[4];

	glm::vec3 cur_loc;
	glm::vec2 cur_rot;
>>>>>>> Stashed changes
};