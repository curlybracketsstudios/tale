#include "CBEntityComponentSystemTest/Core/TestComponents.h"

#include <gtest/gtest.h>
#include <gmock/gmock.h>

//-------------------------------------------------------------------

using namespace testing;

//-------------------------------------------------------------------

#include "CBEntityComponentSystem/Core/ComponentsContainer.h"

#include <memory>

//-------------------------------------------------------------------

TEST(AComponentsContainer, ShouldBeConstructable)
{
	cb::ecs::ComponentsContainer;
}

//-------------------------------------------------------------------

TEST(AComponentsContainer, ShouldBeAbleToAddAComponentOfAGivenType)
{
	cb::ecs::ComponentsContainer components_container;

	std::shared_ptr<TestComponent> test_component = components_container.addComponent<TestComponent>();

	ASSERT_THAT(test_component, Ne(nullptr));
}

//-------------------------------------------------------------------

TEST(AComponentsContainer, ShouldBeAbleToRetreiveTheAddedComponent)
{
	cb::ecs::ComponentsContainer components_container;

	std::shared_ptr<TestComponent> test_component_added = components_container.addComponent<TestComponent>();
	std::shared_ptr<TestComponent> test_component_retrieved = components_container.getComponent<TestComponent>();

	ASSERT_THAT(test_component_added, Eq(test_component_retrieved));
}