#include "Entity.h"
#include <iostream>

Entity::Entity()
{
    //std::cout << "Entity constructor called\n";
}

Entity::~Entity()
{
    for (Component* c : m_components)
    {
        delete c;
    }
    m_components.clear();

    //std::cout << "Entity destructor called\n";
}

void Entity::update(Vec4& new_direction)
{
    if (!m_components.empty())
    {
        for (Component* c : m_components)
        {
            c->update(new_direction);
        }
    }
}

void Entity::add_component(Component* new_component)
{
    //std::cout << "New component added to entity\n";
    new_component->set_owner(this);
    m_components.push_back(new_component);
    //m_components.emplace_back(new_component);
    //m_components.back()->set_owner(this);
}

void Entity::add_sprite_component(SpriteComponent* new_sprite)
{
    //std::cout << "New SpriteComponent added to entity\n";
    new_sprite->set_owner(this);
    m_components.push_back(new_sprite);
    //m_components.back()->set_owner(this);
}
