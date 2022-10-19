#include <gtest/gtest.h>
#include <gmock/gmock.h>

//-------------------------------------------------------------------

using namespace testing;

//-------------------------------------------------------------------

#include "CBEntityComponentSystem/Core/EntityComponentDatabase.h"
#include "CBEntityComponentSystem/Core/Entity.h"

//-------------------------------------------------------------------

TEST(AnEntityComponentDatabase, ShouldBeCreatable)
{
	cb::ecs::EntityComponentDatabase database;
}

//-------------------------------------------------------------------

TEST(AnEntityComponentDatabase, ShouldReturnAValidEntityWhenItCreatesOne)
{
	cb::ecs::EntityComponentDatabase database;

	cb::ecs::Entity entity = database.createEntity();

	ASSERT_THAT(entity.isNull(), Eq(false));
}

//-------------------------------------------------------------------

TEST(AnEntity, ShouldBeNullWhenNotCreatedByEntityComponentDatabase)
{
	cb::ecs::Entity entity;

	ASSERT_THAT(entity.isNull(), Eq(true));
}

//-------------------------------------------------------------------

TEST(AnEntityComponentDatabase, ShouldAlwaysCreateUniqueEntities)
{
	cb::ecs::EntityComponentDatabase database;

	cb::ecs::Entity first_entity = database.createEntity();
	cb::ecs::Entity second_entity = database.createEntity();

	ASSERT_THAT(first_entity, Ne(second_entity));
}

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