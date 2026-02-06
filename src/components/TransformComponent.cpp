#include "TransformComponent.h"
#include <iostream>

TransformComponent::TransformComponent(const ComponentType& new_type)
    :Component(new_type)
{
    std::cout << "TransformComponent constructor called\n";
}

TransformComponent::~TransformComponent()
{
    std::cout << "TransformComponent destructor called\n";
}

void TransformComponent::update()
{

}
