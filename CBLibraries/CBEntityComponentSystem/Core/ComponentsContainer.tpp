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

//-------------------------------------------------------------------
// PROTECTED
//-------------------------------------------------------------------

//-------------------------------------------------------------------
// PRIVATE
//-------------------------------------------------------------------