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

TEST(AComponentsContainer, ShouldReturn0AsIndexFromFirstAddedComponent)
{
	cb::ecs::ComponentsContainer components_container;

	std::size_t result = components_container.getComponentIndex<TestComponent>();

	ASSERT_THAT(result, Eq(0));
}

//-------------------------------------------------------------------