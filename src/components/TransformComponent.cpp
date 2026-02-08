#include "TransformComponent.h"
#include "InputComponent.h"
#include <iostream>

TransformComponent::TransformComponent(int x_starting_position, int y_starting_position)
    :x_position(x_starting_position), y_position(y_starting_position)
{
    std::cout << "TransformComponent constructor called\n";
}

TransformComponent::~TransformComponent()
{
    std::cout << "TransformComponent destructor called\n";
}

void TransformComponent::update(Vec4& new_direction)
{
    InputComponent* input = m_owner->get_component<InputComponent>();
    if (!input) return;

    x_position += new_direction.x_dir;
    y_position += new_direction.y_dir;

    if (x_position < 1) {
        x_position = 1;
    }
    else if (x_position > new_direction.width - 1) {
        x_position = new_direction.width - 1;
    }

    if (y_position < 1) {
        y_position = 1;
    }
    else if (y_position > new_direction.height - 1) {
        y_position = new_direction.height - 1;
    }

    std::cout << "Entity new position: " << x_position << ", " << y_position << "\n";
}

void TransformComponent::add_position(int x, int y, int width, int height)
{
    x_position += x;
    y_position += y;

    if (x_position < 1) {
        x_position = 1;
    }
    else if (x_position > width - 1) {
        x_position = width - 1;
    }

    if (y_position < 1) {
        y_position = 1;
    }
    else if (y_position > height - 1) {
        y_position = height - 1;
    }

}
