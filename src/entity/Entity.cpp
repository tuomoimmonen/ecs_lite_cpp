#include "Entity.h"
#include <iostream>

Entity::Entity()
{
    std::cout << "Entity constructor called\n";

}

Entity::~Entity()
{
    std::cout << "Entity destructor called\n";

}

void Entity::update()
{
    if (!m_components.empty())
    {
        for (Component* c : m_components)
        {
            c->update();
        }
    }

}

void Entity::add_component(const Component* new_component)
{

}
