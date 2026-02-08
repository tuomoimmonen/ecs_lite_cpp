#pragma once
#include "Component.h"
#include "TransformComponent.h"

class SpriteComponent : public Component
{
public:
    SpriteComponent(char new_symbol);
    ~SpriteComponent();

    virtual void update(Vec4& new_direction) override;

    int get_x() const { return x; }
    int get_y() const { return y; }
    char get_symbol() { return symbol; }

private:
    char symbol = 'D';

    int x = 0;
    int y = 0;
};