#include "Enemy.h"
#include "Player.h"
void EnemyBase::setPlayerLoc(CharacterBase* t_p)
{
	mPlayer = t_p;
}

glm::vec3 EnemyBase::getLoc()
{
	return cur_loc;
}

void EnemyBase::attack()
{
	cur_time = clock();
	int i_time = static_cast<int>((cur_time - start_time) / CLOCKS_PER_SEC);
	if (i_time >= 2) {
		glm::vec3 p_loc(dynamic_cast<Player*>(mPlayer)->getLoc().x, 0, dynamic_cast<Player*>(mPlayer)->getLoc().z);
		if (glm::distance(p_loc, cur_loc) < 4) {
			mSound->play_damaged();
			mPlayer->Update_HP(-ATK);
			start_time = clock();
		}
	}
}

