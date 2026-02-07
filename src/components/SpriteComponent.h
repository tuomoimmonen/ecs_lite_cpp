#pragma once
#include "Component.h"
#include "TransformComponent.h"

class SpriteComponent : public Component
{
public:
    SpriteComponent(char new_symbol);
    ~SpriteComponent();

    virtual void update(Vec4& new_direction) override;

    char get_symbol() { return symbol; }

private:
    char symbol = 'D';
};