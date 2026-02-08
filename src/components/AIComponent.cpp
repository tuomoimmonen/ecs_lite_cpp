#include "AIComponent.h"
#include <iostream>
#include "TransformComponent.h"

AIComponent::AIComponent()
{
    std::random_device rd;
    generator.seed(rd());

    //std::cout << "AIComponent constructor called\n";
}

AIComponent::~AIComponent()
{
    //std::cout << "AIComponent destructor called\n";
}

void AIComponent::update(Vec4& new_direction)
{
    // get transform
    TransformComponent* transform = m_owner->get_component<TransformComponent>();
    if (transform)
    {
        int x = 0;
        int y = 0;

        std::uniform_int_distribution<int> random(-1, 1);
        int random_x = random(generator);
        int random_y = random(generator);
        x = random_x;
        y = random_y;

        transform->add_position(x, y, new_direction.width, new_direction.height);
    }
}
