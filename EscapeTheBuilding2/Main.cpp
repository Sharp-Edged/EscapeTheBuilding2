#include <iostream>
#include "Game.h"
#include "Utils.h"

int main()
{
    auto res = levelToGrid(0);
    Game game(res.grid);
    game.SetPlayerCoords(res.playerX, res.playerY);

    while (true) {
        game.OpenMainMenu();

        if (game.gameState == GameState::Game) {
            game.StartGame();
        }
        else if (game.gameState == GameState::Settings) {
            game.OpenSettings();
        }
        
        if (game.gameState == GameState::Quit) {
            break;
        }
    }

    terminal_close();
}
