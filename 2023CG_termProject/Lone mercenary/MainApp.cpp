
#include "MainApp.h"
#include "CameraObj.h"
#include "ProjObj.h"
#include "Player.h"


bool MainApp::Initialize()
{
	mPlayer = new Player(100, 200, 5, 10, 0);
	camera = new CameraObj;
	proj = new ProjObj;

	game_state = 타이틀;
	return true;
}

bool MainApp::Update_MainApp()
{
	switch (game_state) {

	}
}

bool MainApp::Render()
{
	switch (game_state) {
	case 타이틀:
	case 필드:
	}
	return true;
}

void MainApp::DestoryMainApp()
{
	if (nullptr != mPlayer)
		delete mPlayer;
	if (nullptr != camera)
		delete camera;
	if (nullptr != proj)
		delete proj;
}