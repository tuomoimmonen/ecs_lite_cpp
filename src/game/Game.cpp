#include "Game.h"
#include <iostream>
#include <limits>
#include "components/TransformComponent.h"
#include "components/SpriteComponent.h"
#include "components/AIComponent.h"
#include "components/InputComponent.h"

Game::Game()
{
    init();
}

Game::~Game()
{
    for(Entity* e : m_entities) {
        delete e;
    }
    m_entities.clear();

}

void Game::init()
{
    // CREATE ENTITIES
    create_entities();

    m_state = GameState::RUNNING;
}


void Game::update()
{
    // 1. RENDER
    draw_map();
    
    // 2. HANDLE INPUT
    Vec4 directions = handle_input();

    // 3. UPDATE ENTITIES
    update_entities(directions);

    // CLEAR SCREEN
    //system("cls");

    // 4. CHECK COLLISION

    // 5. DELETE END OF FRAME
}

void Game::draw_map()
{
    // FILL BORDERS
    fill_map_borders();

    // FILL ENTITY
    fill_entity_map();

    // FILL ITEMS

    // DRAW MAP
    for (int y = 0; y < m_screen_height; y++) {
        for (int x = 0; x < m_screen_width; x++) {
            std::cout << m_map[y][x];
        }
        std::cout << "\n";
    }

}

void Game::fill_map_borders()
{
    for (int y = 0; y < m_screen_height; y++)
    {
        for (int x = 0; x < m_screen_width; x++)
        {
            if (y > 0 && y < m_screen_height - 1) {
                m_map[y][x] = ' ';
            }
            else {
                m_map[y][x] = '-';
            }

            if (x == 0 || x == m_screen_width - 1) {
                m_map[y][x] = '|';
            }
        }
    }
}

void Game::fill_entity_map()
{
    if (!m_entities.empty())
    {
        for (Entity* e : m_entities)
        {
            // get position + sprite
            TransformComponent* t = e->get_component<TransformComponent>();
            SpriteComponent* s = e->get_component<SpriteComponent>();
            
            if (t && s) {
                int x = t->get_x();
                int y = t->get_y();

                // fill the map
                m_map[y][x] = s->get_symbol();
            }
        }
    }
}

Vec4 Game::handle_input()
{
    char input = 'x';

    do
    {
        std::cout << "\n1. print\n";
        std::cout << "2. quit\n";
        std::cout << "w. forward\n";
        std::cout << "d. right\n";
        std::cout << "s. down\n";
        std::cout << "a. left\n";
        std::cout << "> ";
        std::cin >> input;

        switch (input)
        {
        case '1':
        {
            std::cout << "\nTODO PRINT INVENTORY\n";
            return Vec4(0, 0, m_screen_width, m_screen_height);
            break;
        }
        case '2':
        {
            std::cout << "\nGame ending\n";
            input = 'q';
            m_state = GameState::NONE;
            return Vec4(0, 0, 0, 0);
            break;
        }
        case 'w': return Vec4(0, -1, m_screen_width, m_screen_height);   break;
        case 'd': return Vec4(1, 0, m_screen_width, m_screen_height);    break;
        case 's': return Vec4(0, 1, m_screen_width, m_screen_height);    break;
        case 'a': return Vec4(-1, 0, m_screen_width, m_screen_height);   break;

        default:
        {
            if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "INVALID INPUT\n";
            }
            return Vec4(0, 0, 0, 0);
            break;
        }
        }
    } while (input == 'x');
}

void Game::update_entities(Vec4& new_direction)
{
    if (!m_entities.empty())
    {
        // UPDATE ENTITIES
        for (Entity* e : m_entities) {
            e->update(new_direction);
        }
    }
    else {
        std::cout << "\nEntity vector is empty\n";
    }

}

void Game::create_entities()
{
    m_entities.emplace_back(create_player_entity(10, 10));
    m_entities.emplace_back(create_enemy_entity(10, 10));
}

Entity* Game::create_player_entity(int x_pos, int y_pos)
{
    Entity* entity = new Entity();
    SpriteComponent* sprite = new SpriteComponent('@');
    entity->add_sprite_component(sprite);
    TransformComponent* transform = new TransformComponent(m_screen_width / 2, m_screen_height / 2);
    entity->add_component(transform);
    InputComponent* input = new InputComponent();
    entity->add_component(input);

    return entity;
}

Entity* Game::create_enemy_entity(int x_pos, int y_pos)
{
    int rand_x = (rand() % m_screen_width - 1) + 1;
    int rand_y = (rand() % m_screen_height - 1) + 1;

    Entity* entity = new Entity();
    SpriteComponent* sprite = new SpriteComponent('E');
    entity->add_sprite_component(sprite);
    TransformComponent* transform = new TransformComponent(rand_x, rand_y);
    entity->add_component(transform);
    AIComponent* ai_component = new AIComponent();
    entity->add_component(ai_component);

    return entity;
}
