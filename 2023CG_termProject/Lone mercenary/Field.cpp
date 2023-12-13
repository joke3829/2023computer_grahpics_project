#include "Field.h"
#include "Player.h"
#include "NM_zombie.h"

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
	// �÷��̾� ������ ����
	dynamic_cast<Player*>(mPlayer)->apply_item();
	//  ������Ʈ ������� �ִϸ��̼� �����ϱ�
	dynamic_cast<Player*>(mPlayer)->animation();
	dynamic_cast<Player*>(mPlayer)->attack();
	mCamera->setCameraEYE(dynamic_cast<Player*>(mPlayer)->getLoc());		// ī�޶� ������Ʈ ���ֱ�
	mCamera->setCameraAngle(dynamic_cast<Player*>(mPlayer)->getRot());
	// �ѱ� ��ġ ����
	dynamic_cast<Player*>(mPlayer)->take_out_Wep();
	dynamic_cast<Player*>(mPlayer)->getWeapon()->setLoc(dynamic_cast<Player*>(mPlayer)->getLoc());
	dynamic_cast<Player*>(mPlayer)->getWeapon()->setRot(dynamic_cast<Player*>(mPlayer)->getWepRot());
	dynamic_cast<Player*>(mPlayer)->reload_ani();


	aliving = 0;
	for (int i = 0; i < enemy_list.size(); ++i) {
		if (aliving < max_alive) {
			if (not enemy_list[i]->Death_check()) {
				enemy_list[i]->setPlayerLoc(mPlayer);
				enemy_list[i]->walk_ani(0);
				/*if (dynamic_cast<NM_zombie*>(enemy_list[i])->getlarm()->collision_check(*mField->gethouse_1())
					or dynamic_cast<NM_zombie*>(enemy_list[i])->getrarm()->collision_check(*mField->gethouse_1())
					or dynamic_cast<NM_zombie*>(enemy_list[i])->getlarm()->collision_check(*mField->gethouse_2())
					or dynamic_cast<NM_zombie*>(enemy_list[i])->getrarm()->collision_check(*mField->gethouse_2())) {
					std::cout << "�浹 ��!" << std::endl;
					dynamic_cast<NM_zombie*>(enemy_list[i])->walk_ani(1);
				}*/
				/*if (dynamic_cast<NM_zombie*>(enemy_list[i])->getlarm()->collision_check(*mField->gethouse_1())) {
					dynamic_cast<NM_zombie*>(enemy_list[i])->back_walk();
				}*/
				/*if (mField->gethouse_1()->collision_check(*dynamic_cast<NM_zombie*>(enemy_list[i])->getlarm())) {
					std::cout << "�浹 ��!" << std::endl;
					dynamic_cast<NM_zombie*>(enemy_list[i])->walk_ani(1);
				}*/
				enemy_list[i]->attack();
				dynamic_cast<NM_zombie*>(enemy_list[i])->z_heal(enemy_list);
				dynamic_cast<NM_zombie*>(enemy_list[i])->z_boom();

				++aliving;
			}
		}
		else
			break;
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

	aliving = 0;
	for (int i = 0; i < enemy_list.size(); ++i) {
		if (aliving < max_alive) {
			if (not enemy_list[i]->Death_check()) {
				enemy_list[i]->Render();
				//std::cout << i << "��° ���� ü��: " << enemy_list[i]->getHP() << std::endl;
				++aliving;
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