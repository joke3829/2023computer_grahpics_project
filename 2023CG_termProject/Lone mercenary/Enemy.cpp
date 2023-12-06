#include "Enemy.h"

void EnemyBase::setPlayerLoc(glm::vec3 p_nloc)
{
	p_loc = p_nloc;
}

glm::vec3 EnemyBase::getLoc()
{
	return cur_loc;
}