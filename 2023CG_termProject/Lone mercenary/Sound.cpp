#include "Sound.h"

MySound* MySound::pSound = nullptr;

MySound* MySound::GetInstance()
{
	if (pSound) {
		return pSound;
	}
	else {
		pSound = new MySound;
		return pSound;
	}
}

MySound::MySound()
{
	result = FMOD::System_Create(&ssystem);
	if (result != FMOD_OK)
		exit(0);

	ssystem->init(32, FMOD_INIT_NORMAL, extradriverdata);
	ssystem->createSound("sound\\rifle.mp3", FMOD_DEFAULT, 0, &s_rshot);
	ssystem->createSound("sound\\pistol_shot.mp3", FMOD_DEFAULT, 0, &s_pshot);
	ssystem->createSound("sound\\knife_attack.mp3", FMOD_DEFAULT, 0, &s_kshot);

	ssystem->createSound("sound\\ingame_reload.mp3", FMOD_DEFAULT, 0, &s_reload);
	ssystem->createSound("sound\\damaged.mp3", FMOD_DEFAULT, 0, &damaged);
	ssystem->createSound("sound\\item_pickup.mp3", FMOD_DEFAULT, 0, &pickup);

	ssystem->createSound("sound\\reload.mp3", FMOD_DEFAULT, 0, &c_reload);
	ssystem->createSound("sound\\click.mp3", FMOD_DEFAULT, 0, &click);

	ssystem->createSound("sound\\z_heal.mp3", FMOD_DEFAULT, 0, &s_heal);
	ssystem->createSound("sound\\z_boom.mp3", FMOD_DEFAULT, 0, &s_boom);

	ssystem->createSound("sound\\duskyisland_purplesearoad.ogg", FMOD_LOOP_NORMAL, 0, &main_bgm);
	ssystem->createSound("sound\\Looming Dread_RE2.mp3", FMOD_LOOP_NORMAL, 0, &field_bgm);
	ssystem->createSound("sound\\City Walk.mp3", FMOD_LOOP_NORMAL, 0, &result_bgm);
}

MySound::~MySound()
{
	ssystem->close();
	ssystem->release();
}

void MySound::play_s_shot(int n)
{
	switch (shot_cnt) {
	case 0:
		shot_channel[1]->stop();
		break;
	case 1:
		shot_channel[2]->stop();
		break;
	case 2:
		shot_channel[0]->stop();
		break;
	}

	switch (n) {
	case ³ªÀÌÇÁ:
		ssystem->playSound(s_kshot, 0, false, &shot_channel[shot_cnt]);
		break;
	case ±ÇÃÑ:
		ssystem->playSound(s_pshot, 0, false, &shot_channel[shot_cnt]);
		break;
	case ¶óÀÌÇÃ:
		ssystem->playSound(s_rshot, 0, false, &shot_channel[shot_cnt]);
		break;
	}
	++shot_cnt;
	if (shot_cnt >= 3) {
		shot_cnt = 0;
	}
}

void MySound::play_zom(int n) {
	switch (zc_cnt) {
	case 0:
		shot_channel[1]->stop();
		break;
	case 1:
		shot_channel[2]->stop();
		break;
	case 2:
		shot_channel[0]->stop();
		break;
	}

	switch (n) {
	case Èú·¯:
		ssystem->playSound(s_heal, 0, false, &zombie_channel[zc_cnt]);
		break;
	case Æø¹ß:
		ssystem->playSound(s_boom, 0, false, &zombie_channel[zc_cnt]);
		break;
	}


	++zc_cnt;
	if (zc_cnt >= 3) {
		zc_cnt = 0;
	}
}

void MySound::play_mainbgm()
{
	bgm_channel->stop();
	bgm_channel->setVolume(0.8);
	ssystem->playSound(main_bgm, 0, false, &bgm_channel);
}

void MySound::play_fieldbgm()
{
	bgm_channel->stop();
	bgm_channel->setVolume(0.6);
	ssystem->playSound(field_bgm, 0, false, &bgm_channel);
}

void MySound::bgm_off()
{
	bgm_channel->stop();
}

void MySound::play_click()
{
	effect_channel->stop();
	ssystem->playSound(click, 0, false, &effect_channel);
}

void MySound::play_c_reload()
{
	effect_channel->stop();
	ssystem->playSound(c_reload, 0, false, &effect_channel);
}

void MySound::play_damaged()
{
	effect_channel->stop();
	ssystem->playSound(damaged, 0, false, &effect_channel);
}

void MySound::play_pick()
{
	effect_channel->stop();
	ssystem->playSound(pickup, 0, false, &effect_channel);
}

void MySound::play_s_reload()
{
	effect_channel->stop();
	ssystem->playSound(s_reload, 0, false, &effect_channel);
}

void MySound::play_resultbgm()
{
	bgm_channel->stop();
	bgm_channel->setVolume(1.0);
	ssystem->playSound(result_bgm, 0, false, &bgm_channel);
}