#include "PlayerEntity.h"

PlayerEntity::PlayerEntity()
{
}

PlayerEntity::~PlayerEntity()
{
}

void PlayerEntity::onCreate()
{
	m_entity = getEntitySystem()->createEntity<OEntity>();
}

void PlayerEntity::onUpdate(f32 deltaTime)
{
	m_elapsedSeconds += deltaTime;

	if (m_entity && m_elapsedSeconds >= 3.0f)
	{
		m_entity->release();
		m_entity = nullptr;
	}

}
