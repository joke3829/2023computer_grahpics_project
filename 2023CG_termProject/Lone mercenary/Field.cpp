#include "Field.h"
#include "Player.h"

Field::Field(CharacterBase* t_player, FieldMap* t_field, CameraObj* t_camera, std::vector<EnemyBase*>& t_list)
	: mPlayer(t_player), mField(t_field), mCamera(t_camera), enemy_list(t_list)
{
	max_alive = 6;
}

Field::~Field()
{
	mPlayer = nullptr;
	mField = nullptr;
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


	aliving = 0;
	for (int i = 0; enemy_list.size(); ++i) {
		if (aliving < max_alive) {
			if (not enemy_list[i]->Death_check()) {
				enemy_list[i]->setPlayerLoc(dynamic_cast<Player*>(mPlayer)->getLoc());
				enemy_list[i]->walk_ani();
				++aliving;
			}
		}
		else
			break;
	}
}

void Field::Render()
{
	mField->Render();
	dynamic_cast<Player*>(mPlayer)->getWeapon()->Render();

	aliving = 0;
	for (int i = 0; enemy_list.size(); ++i) {
		if (aliving < max_alive) {
			if (not enemy_list[i]->Death_check()) {
				enemy_list[i]->Render();
				++aliving;
			}
		}
		else
			break;
	}
}

CharacterBase* Field::getPlayer()
{
	return mPlayer;
}

CameraObj* Field::getCamera()
{
	return mCamera;
}