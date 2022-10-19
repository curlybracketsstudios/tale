#include <gtest/gtest.h>
#include <gmock/gmock.h>

//-------------------------------------------------------------------

using namespace testing;

//-------------------------------------------------------------------

#include "CBEntityComponentSystem/Core/EntityComponentDatabase.h"
#include "CBEntityComponentSystem/Core/Entity.h"

//-------------------------------------------------------------------

TEST(AnEntityComponentDatabase, ShouldStoreItsCreatedEntities)
{
	cb::ecs::EntityComponentDatabase database;

	cb::ecs::Entity entity = database.createEntity();

	bool result = database.hasEntity(entity);

	ASSERT_THAT(result, Eq(true));
}

//-------------------------------------------------------------------

TEST(AnEntityComponentDatabase, ShouldNotHaveEntitiesItDoesntCreate)
{
	cb::ecs::EntityComponentDatabase database_retrieve;
	cb::ecs::EntityComponentDatabase database_create;
	cb::ecs::Entity entity = database_create.createEntity();

	bool result = database_retrieve.hasEntity(entity);

	ASSERT_THAT(result, Eq(false));
}

//-------------------------------------------------------------------

TEST(AnEntityComponentDatabase, ShouldNotHaveARemovedEntityAnymore)
{
	cb::ecs::EntityComponentDatabase database;

	cb::ecs::Entity entity = database.createEntity();

	ASSERT_THAT(database.hasEntity(entity), Eq(true));

	database.removeEntity(entity);

	ASSERT_THAT(database.hasEntity(entity), Eq(false));
}

//-------------------------------------------------------------------