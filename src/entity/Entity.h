#pragma once
#include "components/Component.h"
#include <memory>
#include <vector>

class Component;

class Entity
{
public:
    Entity();
    ~Entity();

    void update(Vec4& new_direction);
    void add_component(Component* new_component);

    template<typename Type>
    Type* get_component()
    {
        for (Component* component : m_components)
        {
            Type* pointer = dynamic_cast<Type*>(component);
            if (pointer) {
                return pointer;
            }
            else {
                return nullptr;
            }
        }
        return nullptr;
    }

private:
    std::vector<Component*> m_components;

};