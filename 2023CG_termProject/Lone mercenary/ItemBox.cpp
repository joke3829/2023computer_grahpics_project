#include "ItemBox.h"

ItemBox::ItemBox(GameTimer* t_time, CharacterBase* t_play)
	: timer(t_time), mPlayer(t_play)
{
	box = new Mesh("obj_source\\field\\item_box.obj", "obj_source\\field\\item_box.png", 1024, 1024);
	box->init_scale(0.5);
	exist = false;
	remaining = 8;
	l_time = clock();

	mSound = MySound::GetInstance();
}

ItemBox::~ItemBox()
{
	delete box;
	timer = nullptr;
	mPlayer = nullptr;
	mSound = nullptr;
}

void ItemBox::Render()
{
	if(exist)
		box->Render();
}

void ItemBox::check_collision()
{
	if (exist) {
		if (glm::distance(glm::vec3(dynamic_cast<Player*>(mPlayer)->getLoc().x , 0, dynamic_cast<Player*>(mPlayer)->getLoc().z), cur_loc) < 5) {
			exist = false;
			l_time = clock();
			int heal = 2;
			if (mPlayer->getHP() < 100) {
				heal = 6;
			}
			std::random_device rd;
			std::default_random_engine dre(rd());
			std::uniform_int_distribution<int> uid(1, 10);

			mSound->play_pick();

			if (uid(dre) <= heal || dynamic_cast<Player*>(mPlayer)->getWeapon()->getWep() == ³ªÀÌÇÁ)
				mPlayer->Update_HP(50);
			else
				dynamic_cast<Player*>(mPlayer)->getWeapon()->plusammo(100);
		}
	}
}

void ItemBox::rot_ani()
{
	if (exist) {
		cur_rot.x += 20.0f / 60.0f;
		if (cur_rot.x >= 360)
			cur_rot.x -= 360;
		box->setRot(cur_rot);
	}
}


void ItemBox::check_time()
{
	if (not exist) {
		i_time = clock();
		int cc = static_cast<int>((i_time - l_time) / CLOCKS_PER_SEC);
		if (cc >= remaining) {
			exist = true;
			setLoc();
		}
	}
}

void ItemBox::setLoc()
{
	std::random_device rd;
	std::default_random_engine dre(rd());
	std::uniform_int_distribution<int> uid(-45, 45);
	cur_loc = glm::vec3(uid(dre), 0, uid(dre));
	cur_rot = glm::vec2(0.0f);
	box->setLoc(cur_loc);
}