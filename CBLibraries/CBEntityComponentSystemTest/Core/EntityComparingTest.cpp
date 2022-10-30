#include <gtest/gtest.h>
#include <gmock/gmock.h>

//-------------------------------------------------------------------

using namespace testing;

//-------------------------------------------------------------------

#include "CBEntityComponentSystem/Core/Entity.h"
#include "CBEntityComponentSystem/Core/EntityFactory.h"

//-------------------------------------------------------------------

TEST(AnEntity, ShouldBeEqualToItself)
{
	cb::ecs::Entity entity_created = cb::ecs::EntityFactory::createEntity();
	
	ASSERT_THAT(entity_created, Eq(entity_created));
}

//-------------------------------------------------------------------

TEST(AnEntity, ShouldBeBiggerThanConstructedEntityIfCreated)
{
	cb::ecs::Entity entity_created = cb::ecs::EntityFactory::createEntity();
	cb::ecs::Entity entity_constructed;

	ASSERT_THAT(entity_created > entity_constructed, Eq(true));
}

//-------------------------------------------------------------------

TEST(AnEntity, ShouldBeSmallerThanCreatedEntityIfConstructed)
{
	cb::ecs::Entity entity_created = cb::ecs::EntityFactory::createEntity();
	cb::ecs::Entity entity_constructed;

	ASSERT_THAT(entity_constructed < entity_created, Eq(true));
}

//-------------------------------------------------------------------