#include "TransformComponent.h"
#include <iostream>

TransformComponent::TransformComponent()
{
    std::cout << "TransformComponent constructor called\n";
}

TransformComponent::~TransformComponent()
{
    std::cout << "TransformComponent destructor called\n";
}

void TransformComponent::update(Vec4& new_direction)
{
    x_position += new_direction.x_dir;
    y_position += new_direction.y_dir;

    std::cout << "Entity new position: " << x_position << ", " << y_position << "\n";
}
