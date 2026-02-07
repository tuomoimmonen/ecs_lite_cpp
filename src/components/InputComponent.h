#pragma once
#include "Component.h"
#include "TransformComponent.h"

class InputComponent : public Component
{
public:
    InputComponent();
    ~InputComponent();

    virtual void update(Vec4& new_direction) override;

private:
    

};