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

cb::ecs::Entity cb::ecs::EntityComponentDatabase::createEntity()
{
	cb::ecs::Entity entity;
	entity.setGuid(cb::base::createGUID());
	m_all_entities.insert(entity);
	return entity;
}

//-------------------------------------------------------------------

bool cb::ecs::EntityComponentDatabase::hasEntity(const cb::ecs::Entity& entity) const
{
	return m_all_entities.find(entity) != m_all_entities.end();
}

//-------------------------------------------------------------------

void cb::ecs::EntityComponentDatabase::removeEntity(const cb::ecs::Entity& entity)
{
	auto it_entity = m_all_entities.find(entity);
	if (it_entity != m_all_entities.end())
	{
		m_all_entities.erase(it_entity);
	}
}

//-------------------------------------------------------------------
// PROTECTED
//-------------------------------------------------------------------

//-------------------------------------------------------------------
// PRIVATE
//-------------------------------------------------------------------