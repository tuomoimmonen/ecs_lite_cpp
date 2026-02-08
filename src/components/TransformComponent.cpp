#include "TransformComponent.h"
#include "InputComponent.h"
#include <iostream>

TransformComponent::TransformComponent(int x_starting_position, int y_starting_position)
    :x_position(x_starting_position), y_position(y_starting_position)
{
    //std::cout << "TransformComponent constructor called\n";
}

TransformComponent::~TransformComponent()
{
    //std::cout << "TransformComponent destructor called\n";
}

void TransformComponent::update(Vec4& new_direction)
{

}

void TransformComponent::add_position(int x, int y, int width, int height)
{
    x_position += x;
    y_position += y;

    if (x_position < 1) {
        x_position = 1;
    }
    else if (x_position > width - 2) {
        x_position = width - 2;
    }

    if (y_position < 1) {
        y_position = 1;
    }
    else if (y_position > height - 2) {
        y_position = height - 2;
    }

}
