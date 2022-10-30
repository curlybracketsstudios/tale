//-------------------------------------------------------------------
// CONSTRUCTOR - DESTRUCTOR
//-------------------------------------------------------------------

//-------------------------------------------------------------------
// PUBLIC
//-------------------------------------------------------------------

template<class T>
std::shared_ptr<T> cb::ecs::EntityComponentDatabase::addComponentToEntity(const cb::ecs::Entity& entity)
{
	cb::ecs::ComponentsContainer& components_container = m_entity_components[entity];
	return components_container.addComponent<T>();
}

//-------------------------------------------------------------------

template<class T>
std::shared_ptr<T> cb::ecs::EntityComponentDatabase::getComponentFromEntity(const cb::ecs::Entity& entity)
{
	std::shared_ptr<T> component_from_entity = std::make_shared<T>();

	auto it_entity = m_entity_components.find(entity);
	if (it_entity != m_entity_components.end())
	{
		cb::ecs::ComponentsContainer& components_container = it_entity->second;
		component_from_entity = components_container.getComponent<T>();
	}

	return component_from_entity;
}

//-------------------------------------------------------------------
// PROTECTED
//-------------------------------------------------------------------

//-------------------------------------------------------------------
// PRIVATE
//-------------------------------------------------------------------