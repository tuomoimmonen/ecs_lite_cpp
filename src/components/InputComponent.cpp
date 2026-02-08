#include "InputComponent.h"
#include <iostream>

InputComponent::InputComponent()
{
}

InputComponent::~InputComponent()
{
}

void InputComponent::update(Vec4& new_direction)
{
    TransformComponent* transform = m_owner->get_component<TransformComponent>();
    if (transform) {
        transform->add_position(new_direction.x_dir, new_direction.y_dir, new_direction.width, new_direction.height);
    }
}
