#include "CBEntityComponentSystemTest/Core/TestComponents.h"

#include <gtest/gtest.h>
#include <gmock/gmock.h>

//-------------------------------------------------------------------

using namespace testing;

//-------------------------------------------------------------------

#include "CBEntityComponentSystem/Core/ComponentIndexGenerator.h"

//-------------------------------------------------------------------

TEST(AComponentIndexGenerator, ShouldBeConstructable)
{
	cb::ecs::ComponentIndexGenerator component_index_generator;
}

//-------------------------------------------------------------------

TEST(AComponentIndexGenerator, ShouldReturn0AsIndexForFirstComponentAdded)
{
	cb::ecs::ComponentIndexGenerator component_index_generator;

	auto result = component_index_generator.getComponentIndex<TestComponent>();

	ASSERT_THAT(result, Eq(0));
}

//-------------------------------------------------------------------

TEST(AComponentIndexGenerator, ShouldReturn1AsIndexForSecondComponentAdded)
{
	cb::ecs::ComponentIndexGenerator component_index_generator;
	component_index_generator.getComponentIndex<TestComponent>();
	auto result = component_index_generator.getComponentIndex<AnotherTestComponent>();

	ASSERT_THAT(result, Eq(1));
}

//-------------------------------------------------------------------