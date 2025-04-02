#pragma once
#include <OGL3D/All.h>
#include "PlayerEntity.h"

class GameApp: public OGame
{
public:
	GameApp();
	~GameApp();

	virtual void onCreate();
	virtual void onUpdate(f32 deltaTime);

private:
	f32 m_elapsedSeconds = 0.0f;
	PlayerEntity* m_player = nullptr;
};

