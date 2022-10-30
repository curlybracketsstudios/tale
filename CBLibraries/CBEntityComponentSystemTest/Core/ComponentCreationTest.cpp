#include "CBEntityComponentSystemTest/Core/TestComponents.h"

#include <gtest/gtest.h>
#include <gmock/gmock.h>

//-------------------------------------------------------------------

using namespace testing;

//-------------------------------------------------------------------

#include "CBEntityComponentSystem/Core/Component.h"
#include "CBEntityComponentSystem/Core/Entity.h"
#include "CBEntityComponentSystem/Core/EntityComponentDatabase.h"
#include "CBEntityComponentSystem/Core/EntityFactory.h"

#include <memory>

//-------------------------------------------------------------------

TEST(AnEntityComponentDatabase, ShouldReturnAValidSharedPointerToAComponentOfTheGivenTypeWhenAdded)
{
	cb::ecs::EntityComponentDatabase database;
	cb::ecs::Entity entity = cb::ecs::EntityFactory::createEntity();

	std::shared_ptr<TestComponent> test_component = database.addComponentToEntity<TestComponent>(entity);
	
	ASSERT_THAT(test_component, Ne(nullptr));
}

//-------------------------------------------------------------------

TEST(AnEntityComponentDatabase, ShouldReturnTheSameComponentFromTheEntityWhenItWasPreviouslyAdded)
{
	cb::ecs::EntityComponentDatabase database;
	cb::ecs::Entity entity = cb::ecs::EntityFactory::createEntity();
	std::shared_ptr<TestComponent> test_component_added = database.addComponentToEntity<TestComponent>(entity);

	std::shared_ptr<TestComponent> test_component_retrieved = database.getComponentFromEntity<TestComponent>(entity);

	ASSERT_THAT(test_component_added, Eq(test_component_retrieved));
}

//-------------------------------------------------------------------