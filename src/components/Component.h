#pragma once
#include "entity/Entity.h"

class Entity;

class Component
{
public:
    Component();
    virtual ~Component();

    virtual void update() = 0;

    void set_owner(Entity* new_owner) { m_owner = new_owner; }

protected:

protected:
    Entity* m_owner = nullptr;
};