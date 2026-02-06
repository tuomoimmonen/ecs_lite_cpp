#include "Component.h"
#include <iostream>

Component::Component()
{
    std::cout << "Component base constructor called\n";
}

Component::~Component()
{
    std::cout << "Component base destructor called\n";
}
