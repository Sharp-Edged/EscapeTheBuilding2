#include <iostream>
#include "Game.h"

int main()
{
    Game game;

    game.ShowMainMenu();

    while (terminal_read() != TK_CLOSE);

    terminal_close();
}
