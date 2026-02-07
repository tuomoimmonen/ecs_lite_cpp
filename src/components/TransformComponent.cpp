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

}
