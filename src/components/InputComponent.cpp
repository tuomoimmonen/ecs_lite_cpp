#include "InputComponent.h"
#include <iostream>

InputComponent::InputComponent()
{
    std::cout << "InputComponent constructor called\n";
}

InputComponent::~InputComponent()
{
    std::cout << "InputComponent destructor called\n";
}

void InputComponent::update(Vec4& new_direction)
{
    TransformComponent* transform = m_owner->get_component<TransformComponent>();
    if (transform) {
        std::cout << "InputComponent found TransformComponent\n";
    }
}
