#include "Game.h"
#include <iostream>
#include <limits>

Game::Game()
{
    std::cout << "Game constructor called\n";

    init();
}

Game::~Game()
{
    for(Entity* e : m_entities) {
        delete e;
    }
    m_entities.clear();

    std::cout << "\nGame constructor called\n";
}

void Game::init()
{
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
    draw_map_borders();

    // FILL PLAYER

    // FILL ITEMS

    // DRAW MAP
    for (int y = 0; y < m_screen_height; y++) {
        for (int x = 0; x < m_screen_width; x++) {
            std::cout << m_map[y][x];
        }
        std::cout << "\n";
    }

}

void Game::draw_map_borders()
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
        case 'w': return Vec4(0, -1, m_screen_width, m_screen_width);   break;
        case 'd': return Vec4(1, 0, m_screen_width, m_screen_width);    break;
        case 's': return Vec4(0, 1, m_screen_width, m_screen_width);    break;
        case 'a': return Vec4(-1, 0, m_screen_width, m_screen_width);   break;

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
