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
// PROTECTED
//-------------------------------------------------------------------

//-------------------------------------------------------------------
// PRIVATE
//-------------------------------------------------------------------