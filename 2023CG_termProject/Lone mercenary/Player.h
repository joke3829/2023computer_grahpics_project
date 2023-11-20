//============================================================
// Player.h
// 플레이어 헤더
// 플레이어 조종 및 관리
//============================================================

#include "CharacterBase.h"
#include "Mesh.h"

//class P_Mesh : public Mesh {
//public:
//	P_Mesh(std::string);
//	~P_Mesh();
//protected:
//private:
//	// Mesh가 사용할 여러 회전이나 변환 넣기
//	// 회전이나 여러가지넣기
//};

class Player : public CharacterBase {
public:
	Player();
	Player(float hp, float max, float spd, float def, float atk);
	~Player();
protected:
private:
	
};