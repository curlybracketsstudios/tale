#include "CBEntityComponentSystemTest/Core/TestComponents.h"

#include <gtest/gtest.h>
#include <gmock/gmock.h>

//-------------------------------------------------------------------

using namespace testing;

//-------------------------------------------------------------------

#include "CBEntityComponentSystem/Core/Component/ComponentIndexGenerator.h"

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

TEST(AComponentIndexGenerator, ShouldReturn2AsIndexForThirdComponentAdded)
{
	cb::ecs::ComponentIndexGenerator component_index_generator;
	component_index_generator.getComponentIndex<TestComponent>();
	component_index_generator.getComponentIndex<AnotherTestComponent>();

	auto result = component_index_generator.getComponentIndex<AThirdTestComponent>();

	ASSERT_THAT(result, Eq(2));
}

//-------------------------------------------------------------------

TEST(AComponentIndexGenerator, ShouldReturn0AsIndexWhenFirstComponentAddedAgainAfterOthersAreAdded)
{
	cb::ecs::ComponentIndexGenerator component_index_generator;
	component_index_generator.getComponentIndex<TestComponent>();
	component_index_generator.getComponentIndex<AnotherTestComponent>();
	component_index_generator.getComponentIndex<AThirdTestComponent>();

	auto result = component_index_generator.getComponentIndex<TestComponent>();

	ASSERT_THAT(result, Eq(0));
}

//-------------------------------------------------------------------

TEST(AComponentIndexGenerator, ShouldReturn2AsNumberOfComponentsWhenTwoTypesOfComponentsAreQueriedForIndices)
{
	cb::ecs::ComponentIndexGenerator component_index_generator;
	component_index_generator.getComponentIndex<TestComponent>();
	component_index_generator.getComponentIndex<AnotherTestComponent>();
	component_index_generator.getComponentIndex<TestComponent>();
	component_index_generator.getComponentIndex<AnotherTestComponent>();
	component_index_generator.getComponentIndex<TestComponent>();
	component_index_generator.getComponentIndex<AnotherTestComponent>();

	auto result = component_index_generator.getNumberOfComponents();

	ASSERT_THAT(result, Eq(2));
}

//-------------------------------------------------------------------