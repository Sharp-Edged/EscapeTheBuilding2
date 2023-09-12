#include "Game.h"

Game::Game() {
	terminal_open();
}

void Game::OpenMainMenu() {
	ButtonList buttonList(6, 2, TK_ALIGN_CENTER);
	buttonList.AddButton("1. Play", [&]() { gameState = GameState::Game;  });
	buttonList.AddButton("2. Settings", [&]() { gameState = GameState::Settings;  });
	buttonList.AddButton("3. Quit", [&]() { gameState = GameState::Quit; });

	while (true) {
		terminal_clear();
		
		terminal_print_ext(0, 3, WIDTH, 1, TK_ALIGN_CENTER, "Escape the building 2");
		buttonList.Display();
		
		terminal_refresh();

		int key = terminal_read();

		if (key == TK_ESCAPE || key == TK_CLOSE) {
			break;
		}
		
		if (buttonList.HandleKey(key)) { return; }
	}

	terminal_close();
}