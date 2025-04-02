#include "GameApp.h"

GameApp::GameApp()
{
}

GameApp::~GameApp()
{
}

void GameApp::onCreate()
{
	OGame::onCreate();
	m_player = getEntitySystem()->createEntity<PlayerEntity>();
}

void GameApp::onUpdate(f32 deltaTime)
{

}
