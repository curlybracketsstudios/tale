#include <gtest/gtest.h>
#include <gmock/gmock.h>

//-------------------------------------------------------------------

using namespace testing;

//-------------------------------------------------------------------

#include "CBEntityComponentSystem/Core/EntityComponentDatabaseQuerier.h"

//-------------------------------------------------------------------

TEST(AnEntityComponentDatabaseQuerier, ShouldBeConstructable)
{
	cb::ecs::EntityComponentDatabaseQuerier database_querier;
}

//-------------------------------------------------------------------