//============================================================
// Player.h
// 플레이어 헤더
// 플레이어 조종 및 관리
//============================================================



#include "CharacterBase.h"

class Player : public CharacterBase {
public:
	Player(float hp, float max, float spd, float def, float atk);

<<<<<<< Updated upstream
=======
	// 애니메이션 함수 만들기
	void animation();
	void setRot();
	void setMove(char, bool);
	glm::vec3 getLoc();				// 현재 위치 받아오기
	glm::vec2 getRot();				// 현재 바라보는 방향 받아오기

>>>>>>> Stashed changes
protected:
private:
	
};