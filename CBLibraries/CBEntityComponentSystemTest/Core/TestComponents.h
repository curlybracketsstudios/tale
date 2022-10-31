#pragma once

#include "CBEntityComponentSystem/Core/Component.h"

//-------------------------------------------------------------------

class TestComponent : public cb::ecs::Component
{
public:
	TestComponent(int integerPart = 0, double fractionalPart = 0.0) 
		: m_integer_part(integerPart)
		, m_fractional_part(fractionalPart)
	{};
	~TestComponent() override = default;

public:
	int		m_integer_part;
	double	m_fractional_part;
};

//-------------------------------------------------------------------

class AnotherTestComponent : public cb::ecs::Component
{
public:
	AnotherTestComponent() {};
	~AnotherTestComponent() override = default;
};

//-------------------------------------------------------------------

class AThirdTestComponent : public cb::ecs::Component
{
public:
	AThirdTestComponent() {};
	~AThirdTestComponent() override = default;
};

//-------------------------------------------------------------------