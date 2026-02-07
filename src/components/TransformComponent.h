#pragma once
#include "Component.h"
#include "entity/Entity.h"

class TransformComponent : public Component
{
public:
    TransformComponent();
    ~TransformComponent();

    virtual void update(Vec4& new_direction) override;

    const int get_x() { return x_position; }
    const int get_y() { return y_position; }

private:
    int x_position = 0;
    int y_position = 0;

};