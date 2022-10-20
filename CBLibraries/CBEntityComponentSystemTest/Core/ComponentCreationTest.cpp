#include <gtest/gtest.h>
#include <gmock/gmock.h>

//-------------------------------------------------------------------

using namespace testing;

//-------------------------------------------------------------------

#include "CBEntityComponentSystem/Core/Entity.h"
#include "CBEntityComponentSystem/Core/EntityComponentDatabase.h"

#include <memory>

//-------------------------------------------------------------------

class TestComponent
{
};

//-------------------------------------------------------------------

TEST(AnEntityComponentDatabase, ShouldReturnAValidSharedPointerToAComponentOfTheGivenTypeWhenAdded)
{
	cb::ecs::EntityComponentDatabase database;
	cb::ecs::Entity entity = database.createEntity();

	std::shared_ptr<TestComponent> test_component = database.addComponentToEntity<TestComponent>(entity);
	
	ASSERT_THAT(test_component, Ne(nullptr));
}

//-------------------------------------------------------------------