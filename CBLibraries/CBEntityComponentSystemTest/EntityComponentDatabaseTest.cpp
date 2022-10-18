#include <gtest/gtest.h>
#include <gmock/gmock.h>

//-------------------------------------------------------------------

#include "CBEntityComponentSystem/EntityComponentDatabase.h"

//-------------------------------------------------------------------

TEST(AnEntityComponentDatabase, ShouldBeCreatable)
{
	cb::ecs::EntityComponentDatabase database;
}