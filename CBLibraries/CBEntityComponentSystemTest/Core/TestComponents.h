#pragma once

#include "CBEntityComponentSystem/Core/Component.h"

//-------------------------------------------------------------------

class TestComponent : public cb::ecs::Component
{
public:
	TestComponent() {};
	~TestComponent() override = default;
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