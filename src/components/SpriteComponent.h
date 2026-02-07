#pragma once
#include "Component.h"
#include "TransformComponent.h"

class SpriteComponent : public Component
{
public:
    SpriteComponent();
    ~SpriteComponent();

    virtual void update(Vec4& new_direction) override;

private:
    char symbol = '@';
};