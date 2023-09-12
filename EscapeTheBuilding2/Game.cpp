#include "Game.h"

Game::Game() {
	terminal_open();
}

void Game::ShowMainMenu() {
	TerminalUtility::PrintCentered(3, "Escape the building 2");
	terminal_refresh();
}