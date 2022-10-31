#include "CBEntityComponentSystemTest/Core/TestComponents.h"

#include <gtest/gtest.h>
#include <gmock/gmock.h>

//-------------------------------------------------------------------

using namespace testing;

//-------------------------------------------------------------------

#include "CBEntityComponentSystem/Core/Component/ComponentsContainer.h"

#include <memory>

//-------------------------------------------------------------------

TEST(AComponentsContainer, ShouldBeConstructable)
{
	cb::ecs::ComponentsContainer;
}

//-------------------------------------------------------------------

TEST(AComponentsContainer, ShouldBeAbleToAddAComponentOfAGivenTypeToIndex)
{
	cb::ecs::ComponentsContainer components_container;
	std::shared_ptr<TestComponent> test_component = std::make_shared<TestComponent>();

	components_container.addComponentAtIndex(test_component, 0);

	ASSERT_THAT(components_container.hasComponentAtIndex(0), Eq(true));
}

//-------------------------------------------------------------------

TEST(AComponentsContainer, ShouldBeAbleToRetrieveAddedComponent)
{
	cb::ecs::ComponentsContainer components_container;
	std::shared_ptr<TestComponent> test_component_added = std::make_shared<TestComponent>();
	components_container.addComponentAtIndex(test_component_added, 0);

	std::shared_ptr<cb::ecs::Component> test_component_retrieved = components_container.getComponentAtIndex(0);


	ASSERT_THAT(test_component_added, Eq(test_component_retrieved));
}

//-------------------------------------------------------------------

TEST(AComponentsContainer, ShouldBeAbleToRetrieveCorrectComponentWhenMultipleAdded)
{
	cb::ecs::ComponentsContainer components_container;

	std::shared_ptr<TestComponent> test_component_added = std::make_shared<TestComponent>();
	std::shared_ptr<AnotherTestComponent> another_test_component_added = std::make_shared<AnotherTestComponent>();
	components_container.addComponentAtIndex(test_component_added, 0);
	components_container.addComponentAtIndex(another_test_component_added, 1);

	std::shared_ptr<cb::ecs::Component> test_component_retrieved = components_container.getComponentAtIndex(0);
	std::shared_ptr<cb::ecs::Component> another_test_component_retrieved = components_container.getComponentAtIndex(1);

	ASSERT_THAT(test_component_added, Eq(test_component_retrieved));
	ASSERT_THAT(another_test_component_added, Eq(another_test_component_retrieved));
}

//-------------------------------------------------------------------