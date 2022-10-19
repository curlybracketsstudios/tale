#include "CBBase/GUID/GUID.h"

#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/random_generator.hpp>

//-------------------------------------------------------------------
// CONSTRUCTOR - DESTRUCTOR
//-------------------------------------------------------------------

cb::base::GUID::GUID()
	: m_value(boost::uuids::nil_generator()())
{
}

//-------------------------------------------------------------------
// PUBLIC
//-------------------------------------------------------------------

bool cb::base::GUID::isNull() const
{
	return m_value.is_nil();
}

//-------------------------------------------------------------------
// PROTECTED
//-------------------------------------------------------------------

//-------------------------------------------------------------------
// PRIVATE
//-------------------------------------------------------------------

//-------------------------------------------------------------------

bool cb::base::operator==(const cb::base::GUID& lhs, const cb::base::GUID& rhs)
{
	return lhs.m_value == rhs.m_value;
}

//-------------------------------------------------------------------

bool cb::base::operator!=(const cb::base::GUID& lhs, const cb::base::GUID& rhs)
{
	return lhs.m_value != rhs.m_value;
}

//-------------------------------------------------------------------

bool cb::base::operator<(const cb::base::GUID& lhs, const cb::base::GUID& rhs)
{
	return lhs.m_value < rhs.m_value;
}

//-------------------------------------------------------------------

bool cb::base::operator>(const cb::base::GUID& lhs, const cb::base::GUID& rhs)
{
	return lhs.m_value > rhs.m_value;
}

//-------------------------------------------------------------------

cb::base::GUID cb::base::createGUID()
{
	cb::base::GUID guid;
	guid.m_value = boost::uuids::random_generator()();
	return guid;
}

//-------------------------------------------------------------------