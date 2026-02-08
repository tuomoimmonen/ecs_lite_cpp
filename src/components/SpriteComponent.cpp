#include "SpriteComponent.h"
#include <iostream>

SpriteComponent::SpriteComponent(char new_symbol)
    :symbol(new_symbol)
{

}

SpriteComponent::~SpriteComponent()
{

}

void SpriteComponent::update(Vec4& new_direction)
{
    TransformComponent* transform = m_owner->get_component<TransformComponent>();
    if (transform) {
        // update the sprite position
        int new_x = transform->get_x();
        int new_y = transform->get_y();

        x = new_x;
        y = new_y;
    }

}
