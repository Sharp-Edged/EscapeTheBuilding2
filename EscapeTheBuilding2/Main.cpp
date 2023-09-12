#include <iostream>
#include "Game.h"

int main()
{
    Grid grid(20, 20);
    Game game(grid);

    game.ShowMainMenu();
    game.MainLoop();

    terminal_close();
}
