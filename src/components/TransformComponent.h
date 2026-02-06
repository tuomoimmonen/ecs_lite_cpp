#pragma once
#include "Component.h"
#include "entity/Entity.h"

class TransformComponent : public Component
{
public:
    TransformComponent();
    ~TransformComponent();

    virtual void update() override;

private:
    int x_position = 0;
    int y_position = 0;

};