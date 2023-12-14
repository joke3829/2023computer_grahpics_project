#pragma once

#include <ctime>
#include "CharacterBase.h"
//#include "Player.h"
#include "Sound.h"

class EnemyBase : public CharacterBase {
public:
	EnemyBase() {};
	EnemyBase(float hp, float max, float spd, float def, float atk)
		: CharacterBase(hp, max, spd, def, atk) {
		start_time = clock();
		mSound = MySound::GetInstance();
	};
	virtual ~EnemyBase() {
		mSound = nullptr;
	}

	virtual void walk_ani(int n) {};

	virtual void Render() const {};

	virtual void attack();
	
	

	void setPlayerLoc(CharacterBase*);
	glm::vec3 getLoc();
	
protected:
	glm::vec3 cur_loc{0.0f};
	glm::vec2 cur_rot{0.0f};
	
	CharacterBase* mPlayer;

	int remain{ 10 };
	clock_t cur_time{};
	clock_t start_time{};

	MySound* mSound;
private:
};