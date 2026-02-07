#include <iostream>
#include "game/Game.h"

int main()
{
    Game game;

    while (game.get_is_running())
    {
        game.update();
    }

    std::cout << "\nProgram ended\n";
    
    std::cin.get();
    return 0;
}