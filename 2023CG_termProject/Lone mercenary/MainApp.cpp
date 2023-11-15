
#include "MainApp.h"
#include "Player.h"

MainApp::MainApp()
{
	mPlayer = nullptr;
}

MainApp::~MainApp() {};

bool MainApp::Initialize()
{
	if (not mPlayer)
		mPlayer = new Player(100, 200, 5, 10, 0);
}