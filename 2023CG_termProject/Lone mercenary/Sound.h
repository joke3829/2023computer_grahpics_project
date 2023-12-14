#pragma once

#include "stdafx.h"

class MySound {
public:
	MySound();
	~MySound();
	static MySound* GetInstance();

	void play_s_shot(int);
	void play_mainbgm();
	void play_fieldbgm();
	void play_resultbgm();

	void play_zom(int);

	void play_click();
	void play_c_reload();
	void play_damaged();
	void play_pick();
	void play_s_reload();

	void bgm_off();

private:
	static MySound* pSound;

	FMOD::System* ssystem;
	FMOD::Sound* s_reload, * s_rshot, * s_pshot, * s_kshot, *s_boom, * s_heal;	// 추가하자
	FMOD::Sound* c_reload, * damaged, * click, * pickup;
	FMOD::Sound* main_bgm, *field_bgm, *result_bgm;	// 추가하자
	FMOD::Channel* shot_channel[3]{};	// 공격
	FMOD::Channel* bgm_channel = 0;
	FMOD::Channel* effect_channel = 0;	// 픽업, 데미지, 장전, 클릭, 등등
	FMOD::Channel* zombie_channel[3]{};	// 좀비 폭발 힐 등

	FMOD_RESULT result;
	void* extradriverdata = 0;

	int shot_cnt{};
	int zc_cnt{};
};