#include "CBEntityComponentSystem/Core/EntitiesComponentsContainer.h"

//-------------------------------------------------------------------
// CONSTRUCTOR - DESTRUCTOR
//-------------------------------------------------------------------

//-------------------------------------------------------------------
// PUBLIC
//-------------------------------------------------------------------

template<class T, typename... Args>
std::shared_ptr<T> cb::ecs::EntityComponentDatabaseModifier::addComponentToEntity(const cb::ecs::Entity& entity, Args... args)
{
	std::shared_ptr<cb::ecs::ComponentsContainer> components_container = getComponentsContainerForEntity(entity);
	if (!components_container->hasComponentAtIndex(getIndexForComponent<T>()))
	{
		components_container->addComponentAtIndex(createComponentOfType<T, Args...>(args...), getIndexForComponent<T>());
	}
	return getComponentFromEntity<T>(entity);
}

//-------------------------------------------------------------------

template<class T>
void cb::ecs::EntityComponentDatabaseModifier::addComponentToEntity(const cb::ecs::Entity& entity, std::shared_ptr<T> component)
{
	std::shared_ptr<cb::ecs::ComponentsContainer> components_container = getComponentsContainerForEntity(entity);
	components_container->addComponentAtIndex(component, getIndexForComponent<T>());
}

//-------------------------------------------------------------------

template<class T>
std::shared_ptr<T> cb::ecs::EntityComponentDatabaseModifier::getComponentFromEntity(const cb::ecs::Entity& entity)
{
	std::shared_ptr<cb::ecs::ComponentsContainer> components_container = getComponentsContainerForEntity(entity);
	return std::dynamic_pointer_cast<T>(components_container->getComponentAtIndex(getIndexForComponent<T>()));
	std::shared_ptr<T> component = nullptr;
}

//-------------------------------------------------------------------

template <class T>
bool cb::ecs::EntityComponentDatabaseModifier::hasComponentForEntity(const cb::ecs::Entity& entity)
{
	std::shared_ptr<cb::ecs::ComponentsContainer> components_container = m_entities_components_container->getComponentsContainerForEntity(entity);
	return components_container->hasComponentAtIndex(getIndexForComponent<T>());
}

//-------------------------------------------------------------------
// PROTECTED
//-------------------------------------------------------------------

//-------------------------------------------------------------------
// PRIVATE
//-------------------------------------------------------------------

template <class T>
std::size_t cb::ecs::EntityComponentDatabaseModifier::getIndexForComponent()
{
	return m_component_index_generator->getComponentIndex<T>();
}

//-------------------------------------------------------------------

template <class T, typename... Args>
std::shared_ptr<T> cb::ecs::EntityComponentDatabaseModifier::createComponentOfType(Args... args)
{
	return std::make_shared<T>(args...);
}

//-------------------------------------------------------------------