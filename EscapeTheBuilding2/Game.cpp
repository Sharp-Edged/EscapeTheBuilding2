#include "Game.h"
#include <array>
#include <iostream>

Game::Game(Grid& _Level) : Level(_Level), player(Player(15)), gameState(GameState::MainMenu) {
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
			gameState = GameState::Quit;
			return;
		}

		if (buttonList.HandleKey(key)) { return; }
	}
}

void Game::OpenSettings() {
	while (true) {
		terminal_clear();

		terminal_print_ext(0, 3, WIDTH, 1, TK_ALIGN_CENTER, "Settings");

		terminal_refresh();

		int key = terminal_read();

		if (key == TK_ESCAPE) {
			gameState = GameState::MainMenu;
			return;
		}

		if (key == TK_CLOSE) {
			gameState = GameState::Quit;
			return;
		}
	}
}

static bool CharIs(int Char, std::vector<int> Chars) {
	for (int c : Chars) {
		if (Char == c) return true;
	}
	return false;
}

void Game::MainLoop() {
	int c;
	while ((c = terminal_read()) != TK_CLOSE) {
		if (CharIs(c, { TK_A, TK_S, TK_W, TK_D })) {
			MovePlayer(c);
		}
	}
}

void Game::MovePlayer(int CharCode) {
	std::array<int, 2> coords = player.GetCoords();
	switch (CharCode) {
	case TK_A: coords[0]--; break;
	case TK_S: coords[1]++; break;
	case TK_D: coords[0]++; break;
	case TK_W: coords[1]--; break;
	}
	
	GridCell& cell = Level.GetCell(coords[0], coords[1]);
	if (cell.CellType == GridCellType::FLOOR || cell.CellType == GridCellType::DOOR) {
		player.SetCoords(coords);
		std::cout << coords[0] << " " << coords[1] << std::endl;
		IlluminateMap();
	}
}

void Game::IlluminateMap() {
	auto coords = player.GetCoords();
	for (int i = 0; i < Level.DataLen(); i++) {
		auto& c = Level.GetCell(i);
		c.Visible = false;
	}
	for (int i = coords[0] - 1; i < coords[0] + 1; i++) {
		for (int j = coords[1] - 1; j < coords[1] + 1; j++) {
			Level.SetVisibility(i, j, true);
		}
	}
}