#include "Game.h"
#include "Utils.h"
#include <iostream>

Game::Game(Grid& _Level) : Level(_Level), player(Player(15, 10, 10)) {
	gameState = GameState::MainMenu;
	inventoryOpen = false;

	terminal_open();
}

void Game::OpenMainMenu() {
	ButtonList buttonList(6, 2, TK_ALIGN_CENTER);
	buttonList.AddButton("1. Play", [&]() { gameState = GameState::Game; });
	buttonList.AddButton("2. Settings", [&]() { gameState = GameState::Settings; });
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

void Game::DisplayStatusBar() {

}

void Game::StartGame() {
	Inventory inventory(20, 10);

	while (true) {
		terminal_clear();

		DrawMap();
		if (inventoryOpen) { inventory.Display(); }
		DisplayStatusBar();

		int key = terminal_peek();

		if (key == TK_ESCAPE || key == TK_CLOSE) {
			gameState = GameState::Quit;
			return;
		}

		if (key == TK_I) {
			inventoryOpen = !inventoryOpen;
		}

		if (inventoryOpen) {
			inventory.HandleKey(key);
		}
		else {
			if (CharIs(key, { TK_A, TK_S, TK_W, TK_D })) {
				MovePlayer(key);
			}
		}

		terminal_refresh();

		if (terminal_has_input()) terminal_read();

		terminal_delay(10); // Delta time
	}
}

void Game::MovePlayer(int CharCode) {
	Point coords = player.GetCoords();
	switch (CharCode) {
	case TK_A: coords.x--; break;
	case TK_S: coords.y++; break;
	case TK_D: coords.x++; break;
	case TK_W: coords.y--; break;
	}
	
	std::cout << coords << std::endl;
	GridCell& cell = Level.GetCell(coords.x, coords.y);
	if (cell.CellType == GridCellType::Floor || cell.CellType == GridCellType::Door) {
		player.SetCoords(coords);
	}
}

void Game::SetPlayerCoords(int x, int y) {
	player.SetX(x);
	player.SetY(y);
}

void Game::DrawMap() {
	for (int x = 0; x < Level.GridWidth; x++) {
		for (int y = 0; y < Level.GridHeight; y++) {
			if (player.GetX() == x && player.GetY() == y) continue;
			
			terminal_put(x + 1, y + 1, GridHelpers::CellTypeToChar(Level.GetCell(x, y).CellType));
		}
	}
	terminal_put(player.GetX() + 1, player.GetY() + 1, ' ');
}