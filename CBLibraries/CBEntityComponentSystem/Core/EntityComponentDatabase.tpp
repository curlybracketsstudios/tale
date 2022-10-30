//-------------------------------------------------------------------
// CONSTRUCTOR - DESTRUCTOR
//-------------------------------------------------------------------

//-------------------------------------------------------------------
// PUBLIC
//-------------------------------------------------------------------

template<class T>
std::shared_ptr<T> cb::ecs::EntityComponentDatabase::addComponentToEntity(const cb::ecs::Entity& entity)
{
	std::shared_ptr<T> typed_component = std::make_shared<T>();

	m_entity_components[entity].push_back(std::dynamic_pointer_cast<cb::ecs::Component>(typed_component));

	return typed_component;
}

//-------------------------------------------------------------------

template<class T>
std::shared_ptr<T> cb::ecs::EntityComponentDatabase::getComponentFromEntity(const cb::ecs::Entity& entity)
{
	std::shared_ptr<T> component_from_entity = std::make_shared<T>();

	auto it_entity = m_entity_components.find(entity);
	if (it_entity != m_entity_components.end() && it_entity->second.size())
	{
		component_from_entity = std::dynamic_pointer_cast<T>(*it_entity->second.begin());
	}

	return component_from_entity;
}

//-------------------------------------------------------------------
// PROTECTED
//-------------------------------------------------------------------

//-------------------------------------------------------------------
// PRIVATE
//-------------------------------------------------------------------