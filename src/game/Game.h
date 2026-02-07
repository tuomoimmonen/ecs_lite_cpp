#pragma once
#include "entity/Entity.h"
#include <vector>

enum class GameState
{
    NONE = 0, RUNNING
};

class Game
{
public:
    Game();
    ~Game();

    void update();

    const bool get_is_running() const { return m_state == GameState::RUNNING; }

private:
    void init();
    void draw_map();
    void fill_map_borders();
    void fill_entity_map();
    Vec4 handle_input();
    void update_entities(Vec4& new_direction);

    void create_entities();

private:
    int m_screen_width = 20;
    int m_screen_height = 10;
    char m_map[10][20];
    char m_entities_map[10][20];

    GameState m_state = GameState::NONE;
    std::vector<Entity*> m_entities;
};