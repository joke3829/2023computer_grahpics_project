//============================================================
// Player.h
// �÷��̾� ���
// �÷��̾� ���� �� ����
//============================================================

#include "CharacterBase.h"
#include "Mesh.h"

//class P_Mesh : public Mesh {
//public:
//	P_Mesh(std::string);
//	~P_Mesh();
//protected:
//private:
//	// Mesh�� ����� ���� ȸ���̳� ��ȯ �ֱ�
//	// ȸ���̳� ���������ֱ�
//};

class Player : public CharacterBase {
public:
	Player();
	Player(float hp, float max, float spd, float def, float atk);
	~Player();
protected:
private:
	
};