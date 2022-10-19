#include "CBEntityComponentSystem/Core/EntityComponentDatabase.h"

#include <boost/uuid/random_generator.hpp>

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
	entity.setGuid(boost::uuids::random_generator()());
	return entity;
}

//-------------------------------------------------------------------
// PROTECTED
//-------------------------------------------------------------------

//-------------------------------------------------------------------
// PRIVATE
//-------------------------------------------------------------------