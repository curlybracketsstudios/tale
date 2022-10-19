#include <gtest/gtest.h>
#include <gmock/gmock.h>

//-------------------------------------------------------------------

using namespace testing;

//-------------------------------------------------------------------

#include "CBEntityComponentSystem/EntityComponentDatabase.h"
#include "CBEntityComponentSystem/Entity.h"

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