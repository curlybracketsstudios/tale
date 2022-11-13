#include "CBEntityComponentSystem/Core/EntityComponentDatabaseQuerier.h"

#include "CBEntityComponentSystem/Core/Component/ComponentIndexGenerator.h"
#include "CBEntityComponentSystem/Core/EntitiesComponentsContainer.h"

//-------------------------------------------------------------------
// CONSTRUCTOR - DESTRUCTOR
//-------------------------------------------------------------------

cb::ecs::EntityComponentDatabaseQuerier::EntityComponentDatabaseQuerier
(
	std::shared_ptr<cb::ecs::EntitiesComponentsContainer> entitiesComponentsContainer,
	std::shared_ptr<cb::ecs::ComponentIndexGenerator> componentIndexGenerator
)
	: m_entities_components_container(entitiesComponentsContainer != nullptr ? entitiesComponentsContainer : std::make_shared<cb::ecs::EntitiesComponentsContainer>())
	, m_component_index_generator(componentIndexGenerator != nullptr ? componentIndexGenerator : std::make_shared<cb::ecs::ComponentIndexGenerator>())
{
}

//-------------------------------------------------------------------
// PUBLIC
//-------------------------------------------------------------------

//-------------------------------------------------------------------
// PROTECTED
//-------------------------------------------------------------------

//-------------------------------------------------------------------
// PRIVATE
//-------------------------------------------------------------------