#pragma once
#include "fmod.hpp"
#include "fmod_errors.h"

class Sound {
public:
	Sound();
	~Sound();
	void Shoot_sound();

private:
	void* extradriverdata = 0;
	FMOD::System* ssystem;
	FMOD::Sound* shoot;
	FMOD::Channel* channel = 0; //ÃÑ ¼Ò¸®
	FMOD_RESULT result;
};