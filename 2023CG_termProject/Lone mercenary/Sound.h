#pragma once

#include "stdafx.h"

class MySound {
public:
	MySound();
	~MySound();
	static MySound* GetInstance();

	void play_s_shot();

private:
	static MySound* pSound;

	FMOD::System* ssystem;
	FMOD::Sound* s_reload, *s_shot, *s_boom, *s_heal;	// 추가하자
	FMOD::Channel* shot_channel[3]{};
	FMOD_RESULT result;
	void* extradriverdata = 0;

	int shot_cnt{};
};