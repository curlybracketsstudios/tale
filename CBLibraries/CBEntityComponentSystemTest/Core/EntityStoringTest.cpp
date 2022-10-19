#include <gtest/gtest.h>
#include <gmock/gmock.h>

//-------------------------------------------------------------------

using namespace testing;

//-------------------------------------------------------------------

#include "CBEntityComponentSystem/Core/EntityComponentDatabase.h"
#include "CBEntityComponentSystem/Core/Entity.h"

//-------------------------------------------------------------------

TEST(AnEntityComponentDatabase, ShouldNotHaveARemovedEntityAnymore)
{
	cb::ecs::EntityComponentDatabase database;

	cb::ecs::Entity entity = database.createEntity();

	ASSERT_THAT(database.hasEntity(entity), Eq(true));

	database.removeEntity(entity);

	ASSERT_THAT(database.hasEntity(entity), Eq(false));
}