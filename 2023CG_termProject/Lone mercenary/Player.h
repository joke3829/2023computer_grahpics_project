//============================================================
// Player.h
// �÷��̾� ���
// �÷��̾� ���� �� ����
//============================================================



#include "CharacterBase.h"

class Player : public CharacterBase {
public:
	Player(float hp, float max, float spd, float def, float atk);

<<<<<<< Updated upstream
=======
	// �ִϸ��̼� �Լ� �����
	void animation();
	void setRot();
	void setMove(char, bool);
	glm::vec3 getLoc();				// ���� ��ġ �޾ƿ���
	glm::vec2 getRot();				// ���� �ٶ󺸴� ���� �޾ƿ���

>>>>>>> Stashed changes
protected:
private:
	
};