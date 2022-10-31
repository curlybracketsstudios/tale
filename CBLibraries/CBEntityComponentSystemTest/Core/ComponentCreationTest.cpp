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

TEST(AnEntityComponentDatabase, ShouldReturnTheFirstComponentWhenSecondComponentOfSameTypeIsAdded)
{
	cb::ecs::EntityComponentDatabase database;
	cb::ecs::Entity entity = cb::ecs::EntityFactory::createEntity();
	std::shared_ptr<TestComponent> test_component_added_first = database.addComponentToEntity<TestComponent>(entity);

	std::shared_ptr<TestComponent> test_component_added_second = database.addComponentToEntity<TestComponent>(entity);

	ASSERT_THAT(test_component_added_first, Eq(test_component_added_second));
}

//-------------------------------------------------------------------

TEST(AnEntityComponentDatabase, ShouldReturnTheCorrectComponentWhenMultipleComponentsAreAdded)
{
	cb::ecs::EntityComponentDatabase database;
	cb::ecs::Entity entity = cb::ecs::EntityFactory::createEntity();
	std::shared_ptr<TestComponent> test_component_added = database.addComponentToEntity<TestComponent>(entity);
	std::shared_ptr<AnotherTestComponent> another_test_component_added = database.addComponentToEntity<AnotherTestComponent>(entity);
	std::shared_ptr<AThirdTestComponent> a_third_test_component_added = database.addComponentToEntity<AThirdTestComponent>(entity);

	std::shared_ptr<TestComponent> test_component_retrieved = database.getComponentFromEntity<TestComponent>(entity);
	std::shared_ptr<AnotherTestComponent> another_test_component_retrieved = database.getComponentFromEntity<AnotherTestComponent>(entity);
	std::shared_ptr<AThirdTestComponent> a_third_test_component_retrieved = database.getComponentFromEntity<AThirdTestComponent>(entity);

	ASSERT_THAT(test_component_added, Eq(test_component_retrieved));
	ASSERT_THAT(another_test_component_added, Eq(another_test_component_retrieved));
	ASSERT_THAT(a_third_test_component_added, Eq(a_third_test_component_retrieved));
}

//-------------------------------------------------------------------

TEST(AnEntityComponentDatabase, ShouldDoWhatWhenNonAddedComponentIsAsked)
{
	cb::ecs::EntityComponentDatabase database;
	cb::ecs::Entity entity = cb::ecs::EntityFactory::createEntity();

	std::shared_ptr<TestComponent> test_component = database.getComponentFromEntity<TestComponent>(entity);

	ASSERT_THAT(test_component, Eq(nullptr));
}

//-------------------------------------------------------------------