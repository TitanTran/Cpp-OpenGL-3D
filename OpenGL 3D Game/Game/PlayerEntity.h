#pragma once
#include <OGL3D/All.h>

class PlayerEntity: public OEntity
{
public:
	PlayerEntity();
	~PlayerEntity();

	virtual void onCreate();
	virtual void onUpdate(f32 deltaTime);

private:
	f32 m_elapsedSeconds = 0.0f;
	OEntity* m_entity = nullptr;
};

