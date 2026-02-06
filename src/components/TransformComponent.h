#pragma once
#include "Component.h"

class TransformComponent : public Component
{
public:
    TransformComponent(const ComponentType& new_type);
    ~TransformComponent();

    virtual void update() override;

private:
    int x_position = 0;
    int y_position = 0;

};