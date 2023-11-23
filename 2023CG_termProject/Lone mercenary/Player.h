//============================================================
// Player.h
// 플레이어 헤더
// 플레이어 조종 및 관리
//============================================================



#include "CharacterBase.h"
#include "Weapon.h"

class Player : public CharacterBase {
private:
	glm::vec3 cur_loc;			// 플레이어 현재 위치, 총기랑 카메라에 넘겨주자
	glm::vec2 cur_rot;			// 플레이어가 바라보는 방향(0, 0)이면 x축이 증가하는 방향을 바라본다. 마찬가지로 넘겨주기
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

	// 애니메이션 함수 만들기
	void animation();
	void animi_rot(int, int);
	void setMove(char, bool);
	void setsensative(char);
	void setWeapon(char);
	void attack();
	glm::vec3 getLoc();				// 현재 위치 받아오기
	glm::vec2 getRot();				// 현재 바라보는 방향 받아오기
	int Weapon();
};