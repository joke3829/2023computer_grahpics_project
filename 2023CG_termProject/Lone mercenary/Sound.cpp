#include "Sound.h"
#include "stdafx.h"

Sound::Sound()
{
	result = FMOD::System_Create(&ssystem);
	if (result != FMOD_OK)
		exit(0);
	ssystem->init(32, FMOD_INIT_NORMAL, extradriverdata);
	ssystem->createSound("sound\\sound_shoot.wav",FMOD_LOOP_NORMAL, 0, &shoot);	//ÃÑ¼Ò¸®
	channel->stop();
}

Sound::~Sound()
{
}

void Sound::Shoot_sound()
{
	ssystem->playSound(shoot, 0, false, &channel);
	channel->setVolume(0.5);
}
