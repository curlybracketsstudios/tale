#include <gtest/gtest.h>
#include <gmock/gmock.h>

//-------------------------------------------------------------------

using namespace testing;

//-------------------------------------------------------------------

#include "CBEntityComponentSystem/Core/Component.h"
#include "CBEntityComponentSystem/Core/EntityComponentDatabase.h"
#include "CBEntityComponentSystem/Core/Entity.h"
#include "CBEntityComponentSystem/Core/EntityFactory.h"

//-------------------------------------------------------------------

class TestComponent : public cb::ecs::Component
{
public:
	TestComponent() {};
	~TestComponent() override = default;
};

//-------------------------------------------------------------------

TEST(AnEntityComponentDatabase, ShouldStoreEntityWhenComponentIsAddedToIt)
{
	cb::ecs::EntityComponentDatabase database;

	cb::ecs::Entity entity = cb::ecs::EntityFactory::createEntity();

	database.addComponentToEntity<TestComponent>(entity);

	bool result = database.hasEntity(entity);

	ASSERT_THAT(result, Eq(true));
}

//-------------------------------------------------------------------

TEST(AnEntityComponentDatabase, ShouldNotHaveEntitiesItDoesntHaveComponentsFrom)
{
	cb::ecs::EntityComponentDatabase database_retrieve;
	cb::ecs::Entity entity = cb::ecs::EntityFactory::createEntity();

	bool result = database_retrieve.hasEntity(entity);

	ASSERT_THAT(result, Eq(false));
}

//-------------------------------------------------------------------

TEST(AnEntityComponentDatabase, ShouldNotHaveARemovedEntityAnymore)
{
	cb::ecs::EntityComponentDatabase database;

	cb::ecs::Entity entity = cb::ecs::EntityFactory::createEntity();

	database.addComponentToEntity<TestComponent>(entity);

	database.removeEntity(entity);

	ASSERT_THAT(database.hasEntity(entity), Eq(false));
}

//-------------------------------------------------------------------