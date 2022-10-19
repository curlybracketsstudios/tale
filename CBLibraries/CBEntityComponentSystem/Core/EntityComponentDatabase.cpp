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
	return entity;
}

//-------------------------------------------------------------------

bool cb::ecs::EntityComponentDatabase::hasEntity(const cb::ecs::Entity& entity) const
{
	return true;
}

//-------------------------------------------------------------------
// PROTECTED
//-------------------------------------------------------------------

//-------------------------------------------------------------------
// PRIVATE
//-------------------------------------------------------------------