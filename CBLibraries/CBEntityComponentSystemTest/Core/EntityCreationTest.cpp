#include <gtest/gtest.h>
#include <gmock/gmock.h>

//-------------------------------------------------------------------

using namespace testing;

//-------------------------------------------------------------------

#include "CBEntityComponentSystem/Core/Entity.h"
#include "CBEntityComponentSystem/Core/EntityFactory.h"

//-------------------------------------------------------------------

TEST(AnEntityFactory, ShouldReturnAValidEntityWhenItCreatesOne)
{
	cb::ecs::Entity entity = cb::ecs::EntityFactory::createEntity();

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
	cb::ecs::Entity first_entity = cb::ecs::EntityFactory::createEntity();
	cb::ecs::Entity second_entity = cb::ecs::EntityFactory::createEntity();

	ASSERT_THAT(first_entity, Ne(second_entity));
}

//-------------------------------------------------------------------