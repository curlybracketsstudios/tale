#include "CBEntityComponentSystem/Core/EntityComponentDatabase.h"

//-------------------------------------------------------------------
// CONSTRUCTOR - DESTRUCTOR
//-------------------------------------------------------------------

cb::ecs::EntityComponentDatabase::EntityComponentDatabase()
{
}

//-------------------------------------------------------------------
// PUBLIC
//-------------------------------------------------------------------

bool cb::ecs::EntityComponentDatabase::hasEntity(const cb::ecs::Entity& entity) const
{
	return m_entity_components.find(entity) != m_entity_components.end();
}

//-------------------------------------------------------------------

void cb::ecs::EntityComponentDatabase::removeEntity(const cb::ecs::Entity& entity)
{
	auto it_entity = m_entity_components.find(entity);
	if (it_entity != m_entity_components.end())
	{
		m_entity_components.erase(it_entity);
	}
}

//-------------------------------------------------------------------
// PROTECTED
//-------------------------------------------------------------------

//-------------------------------------------------------------------
// PRIVATE
//-------------------------------------------------------------------