
#include "MainApp.h"
#include "CameraObj.h"
#include "ProjObj.h"
#include "Player.h"


bool MainApp::Initialize()
{
	mPlayer = new Player(100, 200, 5, 10, 0);
	camera = new CameraObj;
	proj = new ProjObj;

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