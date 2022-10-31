#include <gtest/gtest.h>
#include <gmock/gmock.h>

//-------------------------------------------------------------------

using namespace testing;

//-------------------------------------------------------------------

#include "CBEntityComponentSystem/Core/Component/ComponentsContainer.h"
#include "CBEntityComponentSystem/Core/Entity.h"
#include "CBEntityComponentSystem/Core/EntityFactory.h"
#include "CBEntityComponentSystem/Core/EntitiesComponentsContainer.h"

#include <memory>

//-------------------------------------------------------------------

TEST(AnEntitiesComponentsContainer, ShouldBeConstructable)
{
	cb::ecs::EntitiesComponentsContainer entity_components_container;
}

//-------------------------------------------------------------------

TEST(AnEntitiesComponentsContainer, ShouldReturn0ForNumberOfEntitiesOnConstruction)
{
	cb::ecs::EntitiesComponentsContainer entity_components_container;

	ASSERT_THAT(entity_components_container.getNumberOfEntities(), Eq(0));
}

//-------------------------------------------------------------------

TEST(AnEntitiesComponentsContainer, ShouldReturnFalseForCheckingHasEntitiesWhenEntityNotAdded)
{
	cb::ecs::EntitiesComponentsContainer entity_components_container;
	cb::ecs::Entity entity = cb::ecs::EntityFactory::createEntity();

	ASSERT_THAT(entity_components_container.hasEntity(entity), Eq(false));
}

//-------------------------------------------------------------------

TEST(AnEntitiesComponentsContainer, ShouldReturnTrueForCheckingHasEntitiesWhenEntityAdded)
{
	cb::ecs::EntitiesComponentsContainer entity_components_container;
	cb::ecs::Entity entity = cb::ecs::EntityFactory::createEntity();
	entity_components_container.addEntity(entity);

	ASSERT_THAT(entity_components_container.hasEntity(entity), Eq(true));
}

//-------------------------------------------------------------------

TEST(AnEntitiesComponentsContainer, ShouldReturn1ForNumberOfEntitiesWhenEntityIsAdded)
{
	cb::ecs::EntitiesComponentsContainer entity_components_container;
	cb::ecs::Entity entity = cb::ecs::EntityFactory::createEntity();

	entity_components_container.addEntity(entity);

	ASSERT_THAT(entity_components_container.getNumberOfEntities(), Eq(1));
}

//-------------------------------------------------------------------

TEST(AnEntitiesComponentsContainer, ShouldReturnFalseForCheckingHasEntitiesWhenEntityAddedAndRemoved)
{
	cb::ecs::EntitiesComponentsContainer entity_components_container;
	cb::ecs::Entity entity = cb::ecs::EntityFactory::createEntity();
	entity_components_container.addEntity(entity);

	entity_components_container.removeEntity(entity);

	ASSERT_THAT(entity_components_container.hasEntity(entity), Eq(false));
}

//-------------------------------------------------------------------

TEST(AnEntitiesComponentsContainer, ShouldReturnSameContainerForAddedEntityMultipleTimes)
{
	cb::ecs::EntitiesComponentsContainer entity_components_container;
	cb::ecs::Entity entity = cb::ecs::EntityFactory::createEntity();
	entity_components_container.addEntity(entity);

	std::shared_ptr<cb::ecs::ComponentsContainer> first_retrieved_container = entity_components_container.getComponentsContainerForEntity(entity);
	std::shared_ptr<cb::ecs::ComponentsContainer> second_retrieved_container = entity_components_container.getComponentsContainerForEntity(entity);

	ASSERT_THAT(first_retrieved_container, Eq(second_retrieved_container));
}

//-------------------------------------------------------------------

TEST(AnEntitiesComponentsContainer, ShouldReturnDifferentContainersWhenEntityNotAdded)
{
	cb::ecs::EntitiesComponentsContainer entity_components_container;
	cb::ecs::Entity entity = cb::ecs::EntityFactory::createEntity();

	std::shared_ptr<cb::ecs::ComponentsContainer> first_retrieved_container = entity_components_container.getComponentsContainerForEntity(entity);
	std::shared_ptr<cb::ecs::ComponentsContainer> second_retrieved_container = entity_components_container.getComponentsContainerForEntity(entity);

	ASSERT_THAT(first_retrieved_container, Ne(second_retrieved_container));
}

//-------------------------------------------------------------------

TEST(AnEntitiesComponentsContainer, ShouldReturnDifferentContainersWhenEntityAddedAndRemoved)
{
	cb::ecs::EntitiesComponentsContainer entity_components_container;
	cb::ecs::Entity entity = cb::ecs::EntityFactory::createEntity();
	entity_components_container.addEntity(entity);

	entity_components_container.removeEntity(entity);

	std::shared_ptr<cb::ecs::ComponentsContainer> first_retrieved_container = entity_components_container.getComponentsContainerForEntity(entity);
	std::shared_ptr<cb::ecs::ComponentsContainer> second_retrieved_container = entity_components_container.getComponentsContainerForEntity(entity);
	ASSERT_THAT(first_retrieved_container, Ne(second_retrieved_container));
}

//-------------------------------------------------------------------