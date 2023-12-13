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
	ssystem->createSound("sound\\rifle.mp3", FMOD_DEFAULT, 0, &s_shot);
}

MySound::~MySound()
{
	ssystem->close();
	ssystem->release();
}

void MySound::play_s_shot()
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

	ssystem->playSound(s_shot, 0, false, &shot_channel[shot_cnt]);
	++shot_cnt;
	if (shot_cnt >= 3) {
		shot_cnt = 0;
	}
}