#pragma once

#include "CharacterBase.h"

class EnemyBase : public CharacterBase {
public:
	EnemyBase() {};
	EnemyBase(float hp, float max, float spd, float def, float atk)
		: CharacterBase(hp, max, spd, def, atk) {};
	virtual ~EnemyBase() {};

	virtual void walk_ani(int n) {};

	virtual void Render() const {};

	void setPlayerLoc(glm::vec3);
	glm::vec3 getLoc();
	
protected:
	glm::vec3 cur_loc{0.0f};
	glm::vec2 cur_rot{0.0f};
	
	glm::vec3 p_loc{0.0f};
private:
};