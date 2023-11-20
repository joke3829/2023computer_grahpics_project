
#include "MainApp.h"
#include "Player.h"
#include "RenderManager.h"

MainApp::MainApp()
{
	mPlayer = nullptr;
	renderer = nullptr;
}


bool MainApp::Initialize()
{
	if (not renderer)
		renderer = new RenderManager;
	game_state = ≈∏¿Ã∆≤;
	return true;
}

bool MainApp::Update_MainApp()
{
	switch (game_state) {

	}
}

bool MainApp::Render()
{
	
	return true;
}

void MainApp::DestoryMainApp()
{

}