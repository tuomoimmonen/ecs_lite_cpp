#pragma once
#include "Component.h"
#include <random>

class AIComponent : public Component
{
public:
    AIComponent();
    ~AIComponent();

    virtual void update(Vec4& new_direction) override;

private:
    std::mt19937 generator;

};