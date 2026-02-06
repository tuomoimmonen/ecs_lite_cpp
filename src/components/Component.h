#pragma once
#include "entity/Entity.h"

enum class ComponentType
{
    NONE = 0, TRANSFORM
};

class Component
{
public:
    Component(const ComponentType& new_type);
    virtual ~Component();

    virtual void update() = 0;

    const ComponentType& get_type() const { return type; }

protected:
    Entity* m_owner = nullptr;
    ComponentType type = ComponentType::NONE;
};