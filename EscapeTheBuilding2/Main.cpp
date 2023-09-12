#include <iostream>
#include "Game.h"

int main()
{
    Grid grid(20, 20);
    Game game(grid);

    while (true) {
        game.OpenMainMenu();

        if (game.gameState == GameState::Game) {

        }
        else if (game.gameState == GameState::Settings) {

        }
        else if (game.gameState == GameState::Quit) {
            break;
        }
    }

    terminal_close();
}
