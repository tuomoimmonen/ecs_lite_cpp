#include "SpriteComponent.h"
#include <iostream>

SpriteComponent::SpriteComponent(char new_symbol)
    :symbol(new_symbol)
{
    std::cout << "SpriteComponent constructor called\n";

}

SpriteComponent::~SpriteComponent()
{
    std::cout << "SpriteComponent destructor called\n";

}

void SpriteComponent::update(Vec4& new_direction)
{
    TransformComponent* transform = m_owner->get_component<TransformComponent>();
    if (transform) {
        // update the sprite position
        std::cout << "SpriteComponent found TransformComponent\n";
    }

}
