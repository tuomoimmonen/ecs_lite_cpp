#pragma once

struct Vec4
{
    int x_dir = 0;
    int y_dir = 0;
    int width = 0;
    int height = 0;
};

class Entity;

class Component
{
public:
    Component();
    virtual ~Component();

    virtual void update(Vec4& new_direction) = 0;

    void set_owner(Entity* new_owner) { m_owner = new_owner; }

protected:

protected:
    Entity* m_owner = nullptr;
};