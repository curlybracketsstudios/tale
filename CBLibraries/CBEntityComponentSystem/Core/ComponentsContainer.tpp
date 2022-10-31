//-------------------------------------------------------------------
// CONSTRUCTOR - DESTRUCTOR
//-------------------------------------------------------------------

//-------------------------------------------------------------------
// PUBLIC
//-------------------------------------------------------------------

template<class T>
std::shared_ptr<T> cb::ecs::ComponentsContainer::addComponent()
{
	std::shared_ptr<T> typed_component = std::make_shared<T>();

	m_components.push_back(std::dynamic_pointer_cast<cb::ecs::Component>(typed_component));

	return typed_component;
}

//-------------------------------------------------------------------

template<class T>
std::shared_ptr<T> cb::ecs::ComponentsContainer::getComponent()
{
	return std::dynamic_pointer_cast<T>(*m_components.begin());
}

//-------------------------------------------------------------------

template <class T>
std::size_t cb::ecs::ComponentsContainer::getComponentIndex()
{
	std::size_t component_index;
	std::type_index component_type_index(typeid(T));

	auto it_component_type = m_component_type_to_index.find(component_type_index);
	if (it_component_type != m_component_type_to_index.end())
	{
		component_index = it_component_type->second;
	}
	else
	{
		component_index = m_component_type_to_index.size();
		m_component_type_to_index.insert(std::make_pair(component_type_index, component_index));
	}

	return component_index;
}

//-------------------------------------------------------------------
// PROTECTED
//-------------------------------------------------------------------

//-------------------------------------------------------------------
// PRIVATE
//-------------------------------------------------------------------