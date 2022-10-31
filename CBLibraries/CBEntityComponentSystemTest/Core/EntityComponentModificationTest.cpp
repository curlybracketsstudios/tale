#include "CBEntityComponentSystemTest/Core/TestComponents.h"

#include <gtest/gtest.h>
#include <gmock/gmock.h>

//-------------------------------------------------------------------

using namespace testing;

//-------------------------------------------------------------------

#include "CBEntityComponentSystem/Core/Component.h"
#include "CBEntityComponentSystem/Core/Entity.h"
#include "CBEntityComponentSystem/Core/EntityComponentDatabaseModifier.h"
#include "CBEntityComponentSystem/Core/EntityFactory.h"

#include <memory>

//-------------------------------------------------------------------

class AnEntityComponentDatabaseModifier : public Test
{
public:
	AnEntityComponentDatabaseModifier()
		: database(cb::ecs::EntityComponentDatabaseModifier())
		, entity(cb::ecs::EntityFactory::createEntity())
	{
	}

public:
	cb::ecs::EntityComponentDatabaseModifier	database;
	cb::ecs::Entity								entity;
};

//-------------------------------------------------------------------

TEST_F(AnEntityComponentDatabaseModifier, ShouldReturnAValidSharedPointerToAComponentOfTheGivenTypeWhenAdded)
{
	std::shared_ptr<TestComponent> test_component = database.addComponentToEntity<TestComponent>(entity);
	
	ASSERT_THAT(test_component, Ne(nullptr));
}

//-------------------------------------------------------------------

TEST_F(AnEntityComponentDatabaseModifier, ShouldReturnTheSameComponentFromTheEntityWhenItWasPreviouslyAdded)
{
	std::shared_ptr<TestComponent> test_component_added = database.addComponentToEntity<TestComponent>(entity);

	std::shared_ptr<TestComponent> test_component_retrieved = database.getComponentFromEntity<TestComponent>(entity);

	ASSERT_THAT(test_component_added, Eq(test_component_retrieved));
}

//-------------------------------------------------------------------

TEST_F(AnEntityComponentDatabaseModifier, ShouldReturnTheFirstComponentWhenSecondComponentOfSameTypeIsAdded)
{
	std::shared_ptr<TestComponent> test_component_added_first = database.addComponentToEntity<TestComponent>(entity);

	std::shared_ptr<TestComponent> test_component_added_second = database.addComponentToEntity<TestComponent>(entity);

	ASSERT_THAT(test_component_added_first, Eq(test_component_added_second));
}

//-------------------------------------------------------------------

TEST_F(AnEntityComponentDatabaseModifier, ShouldReturnTheCorrectComponentWhenMultipleComponentsAreAdded)
{
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

TEST_F(AnEntityComponentDatabaseModifier, ShouldReturnNullptrWhenNonAddedComponentIsQueried)
{
	std::shared_ptr<TestComponent> test_component = database.getComponentFromEntity<TestComponent>(entity);

	ASSERT_THAT(test_component, Eq(nullptr));
}

//-------------------------------------------------------------------

TEST_F(AnEntityComponentDatabaseModifier, ShouldCreateComponentWithCorrectConstructorArgumentsWhenGivenToAddComponent)
{
	std::shared_ptr<TestComponent> test_component = database.addComponentToEntity<TestComponent>(entity, 3, .1415);
	std::shared_ptr<TestComponent> secon_test_component = database.addComponentToEntity<TestComponent>(entity, 1, .618);

	ASSERT_THAT(test_component->m_integer_part, Eq(3));
	ASSERT_THAT(test_component->m_fractional_part, DoubleEq(.1415));
}

//-------------------------------------------------------------------