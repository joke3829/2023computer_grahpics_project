#include "Field.h"
#include "Player.h"
#include "NM_zombie.h"

int Field::first_zom = 0;

Field::Field(CharacterBase* t_player, FieldMap* t_field, CameraObj* t_camera, std::vector<EnemyBase*>& t_list, GameTimer* t_timer, CubeMap* t_cube)
	: mPlayer(t_player), mField(t_field), mCamera(t_camera), enemy_list(t_list), mTimer(t_timer), mCubemap(t_cube)
{
	mUi = new UI(mPlayer, mTimer);
	max_alive = 12;
	item = new ItemBox(mTimer, mPlayer);
	sandglass[0] = new Timerplus(mPlayer, mTimer, glm::vec3(-100, 0, 20));
	sandglass[1] = new Timerplus(mPlayer, mTimer, glm::vec3(20, 0, -100));
	sandglass[2] = new Timerplus(mPlayer, mTimer, glm::vec3(-20, 0, 70));
}

Field::~Field()
{
	delete mUi;
	mPlayer = nullptr;
	mField = nullptr;
	delete item;
	for (int i = 0; i < 3; ++i)
		delete sandglass[i];
}

void Field::Update()
{
	// 플레이어 아이템 적용
	dynamic_cast<Player*>(mPlayer)->apply_item();
	//  업데이트 헤더에서 애니메이션 적용하기
	dynamic_cast<Player*>(mPlayer)->animation();
	dynamic_cast<Player*>(mPlayer)->attack();
	mCamera->setCameraEYE(dynamic_cast<Player*>(mPlayer)->getLoc());		// 카메라 업데이트 해주기
	mCamera->setCameraAngle(dynamic_cast<Player*>(mPlayer)->getRot());
	// 총기 위치 변경
	dynamic_cast<Player*>(mPlayer)->take_out_Wep();
	dynamic_cast<Player*>(mPlayer)->getWeapon()->setLoc(dynamic_cast<Player*>(mPlayer)->getLoc());
	dynamic_cast<Player*>(mPlayer)->getWeapon()->setRot(dynamic_cast<Player*>(mPlayer)->getWepRot());
	dynamic_cast<Player*>(mPlayer)->reload_ani();

	int alive{};
	EnemyBase* aliveEnemy[6];
	bool update_first = false;
	for (int i = first_zom; i < enemy_list.size(); ++i) {
		if (not enemy_list[i]->Death_check()) {
			if (not update_first) {
				first_zom = i;
				update_first = true;
			}
			aliveEnemy[alive++] = enemy_list[i];
			if (6 == alive)
				break;
		}
	}

	for (int i = 0; i < alive; ++i) {
		aliveEnemy[i]->setPlayerLoc(mPlayer);
		if (dynamic_cast<NM_zombie*>(aliveEnemy[i])->getlarm()->collision_check(*mField->gethouse_1())
			|| dynamic_cast<NM_zombie*>(aliveEnemy[i])->getlarm()->collision_check(*mField->gethouse_2())
			|| dynamic_cast<NM_zombie*>(aliveEnemy[i])->getlarm()->collision_check(*mField->gethouse_3())
			|| dynamic_cast<NM_zombie*>(aliveEnemy[i])->getlarm()->collision_check(*mField->gethouse_4())
			|| check_zomcol(aliveEnemy, i))
			aliveEnemy[i]->walk_ani(1);
		else
			aliveEnemy[i]->walk_ani(0);
		enemy_list[i]->attack();
		dynamic_cast<NM_zombie*>(enemy_list[i])->z_heal(enemy_list);
		dynamic_cast<NM_zombie*>(enemy_list[i])->z_boom();
	}

	for (Timerplus*& t : sandglass) {
		t->check_collision();
		t->rot_ani();
	}
	item->check_collision();
	item->check_time();
	item->rot_ani();
	mUi->Update();
}

void Field::Render()
{
	mCubemap->Render();
	mField->Render();
	dynamic_cast<Player*>(mPlayer)->getWeapon()->Render();

	int alive{};
	for (int i = first_zom; i < enemy_list.size(); ++i) {
		if (alive < 6) {
			if (not enemy_list[i]->Death_check()) {
				enemy_list[i]->Render();
				++alive;
			}
		}
		else
			break;
	}
	for (Timerplus*& t : sandglass)
		t->Render();
	item->Render();
	mUi->Render();
}

CharacterBase* Field::getPlayer()
{
	return mPlayer;
}

CameraObj* Field::getCamera()
{
	return mCamera;
}

std::vector<EnemyBase*>& Field::getList()
{
	return enemy_list;
}

bool Field::check_zomcol(EnemyBase* t_list[], int myNum)
{
	for (int i = 0; i < myNum; ++i) {
		if (dynamic_cast<NM_zombie*>(t_list[myNum])->getlarm()->collision_check(
			*(dynamic_cast<NM_zombie*>(t_list[i])->getlarm()))
			|| dynamic_cast<NM_zombie*>(t_list[myNum])->getlarm()->collision_check(
				*(dynamic_cast<NM_zombie*>(t_list[i])->getrarm()))
			|| dynamic_cast<NM_zombie*>(t_list[myNum])->getlarm()->collision_check(
				*(dynamic_cast<NM_zombie*>(t_list[i])->getbody()))
			|| dynamic_cast<NM_zombie*>(t_list[myNum])->getrarm()->collision_check(
				*(dynamic_cast<NM_zombie*>(t_list[i])->getlarm()))
			|| dynamic_cast<NM_zombie*>(t_list[myNum])->getrarm()->collision_check(
				*(dynamic_cast<NM_zombie*>(t_list[i])->getrarm()))
			|| dynamic_cast<NM_zombie*>(t_list[myNum])->getrarm()->collision_check(
				*(dynamic_cast<NM_zombie*>(t_list[i])->getbody()))
			|| dynamic_cast<NM_zombie*>(t_list[myNum])->getbody()->collision_check(
				*(dynamic_cast<NM_zombie*>(t_list[i])->getlarm()))
			|| dynamic_cast<NM_zombie*>(t_list[myNum])->getbody()->collision_check(
				*(dynamic_cast<NM_zombie*>(t_list[i])->getrarm()))
			|| dynamic_cast<NM_zombie*>(t_list[myNum])->getbody()->collision_check(
				*(dynamic_cast<NM_zombie*>(t_list[i])->getbody())))
			return true;
	}
	return false;
}