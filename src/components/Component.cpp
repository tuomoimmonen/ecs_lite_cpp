#include "Component.h"
#include <iostream>

Component::Component(const ComponentType& new_type)
    :type(new_type)
{
    std::cout << "Component base constructor called\n";
}

Component::~Component()
{
    std::cout << "Component base destructor called\n";
}
