#pragma once
#include "components/Component.h"
#include <vector>

class Entity
{
public:
    Entity();
    ~Entity();

    void update();
    void add_component(const Component* new_component);

    template<typename Type>
    Type* get_component()
    {
        for (Component* c : m_components)
        {
            if (c->get_type() == Type) {
                Type* ptr = c->get_type();
                return ptr;
            }
            else
            {
                return nullptr;
            }
        }
    }

private:
    std::vector<Component*> m_components;

};