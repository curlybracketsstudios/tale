#include <gtest/gtest.h>
#include <gmock/gmock.h>

//-------------------------------------------------------------------

using namespace testing;

//-------------------------------------------------------------------

#include "CBEntityComponentSystem/Core/Entity.h"
#include "CBEntityComponentSystem/Core/EntityComponentDatabase.h"

//-------------------------------------------------------------------

TEST(AnEntity, ShouldBeEqualToItself)
{
	cb::ecs::EntityComponentDatabase database;

	cb::ecs::Entity entity_created = database.createEntity();
	
	ASSERT_THAT(entity_created, Eq(entity_created));
}

//-------------------------------------------------------------------

TEST(AnEntity, ShouldBeBiggerThanConstructedEntityIfCreated)
{
	cb::ecs::EntityComponentDatabase database;

	cb::ecs::Entity entity_created = database.createEntity();
	cb::ecs::Entity entity_constructed;

	ASSERT_THAT(entity_created > entity_constructed, Eq(true));
}

//-------------------------------------------------------------------

TEST(AnEntity, ShouldBeSmallerThanCreatedEntityIfConstructed)
{
	cb::ecs::EntityComponentDatabase database;

	cb::ecs::Entity entity_created = database.createEntity();
	cb::ecs::Entity entity_constructed;

	ASSERT_THAT(entity_constructed < entity_created, Eq(true));
}

//-------------------------------------------------------------------